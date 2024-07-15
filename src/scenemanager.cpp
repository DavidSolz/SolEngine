#include "scenemanager.h"

SceneManager::SceneManager()
{
    this->m_sceneID = 0;
}

void SceneManager::processInput(Window &window)
{
    if (m_currentScene == nullptr)
        return;

    m_currentScene->processInput(window);
}

void SceneManager::update(const float &deltaTime)
{
    if (m_currentScene == nullptr)
        return;

    m_currentScene->update(deltaTime);
}

void SceneManager::fixedUpdate(const float &deltaTime)
{
    if (m_currentScene == nullptr)
        return;

    m_currentScene->fixedUpdate(deltaTime);
}

void SceneManager::draw()
{
    if (m_currentScene == nullptr)
        return;

    m_currentScene->draw();
}

unsigned int SceneManager::add(std::shared_ptr<Scene> scene)
{

    unsigned int id = 0;

    if (m_unusedID.empty() == true)
    {
        id = m_sceneID++;
    }
    else
    {
        id = m_unusedID.front();
        m_unusedID.pop_front();
    }

    auto it = m_scenes.insert(std::make_pair(id, scene));
    it.first->second->onCreate();

    return m_sceneID;
}

void SceneManager::remove(const unsigned int &id)
{

    auto it = m_scenes.find(id);

    if (it == m_scenes.end())
        return;

    if (m_currentScene == it->second)
        m_currentScene = nullptr;

    it->second->onDestroy();
    m_scenes.erase(it);
}

void SceneManager::transiteTo(const unsigned int &id)
{

    auto it = m_scenes.find(id);

    if (it == m_scenes.end())
        return;

    if (m_currentScene)
        m_currentScene->onDeactivate();

    m_currentScene = it->second;
    m_currentScene->onActivate();
}
