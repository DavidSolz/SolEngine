#include "scenemanager.h"

SceneManager::SceneManager()
{
    this->m_sceneID = 0;
    this->m_currentScene = nullptr;
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

    auto result = m_scenes.emplace(id, scene);

    if (result.second)
    {
        scene->onCreate.invoke();
    }

    return id;
}

void SceneManager::remove(const unsigned int &id)
{

    auto it = m_scenes.find(id);

    if (it == m_scenes.end())
        return;

    if (m_currentScene == it->second)
        m_currentScene = nullptr;

    it->second->onDestroy.invoke();
    m_unusedID.emplace_back(it->first);

    m_scenes.erase(it);
}

void SceneManager::transiteTo(const unsigned int &id)
{

    auto it = m_scenes.find(id);

    if (it == m_scenes.end())
        return;

    if (m_currentScene != nullptr)
        m_currentScene->onDeactivate.invoke();

    m_currentScene = it->second;
    m_currentScene->onActivate.invoke();
}
