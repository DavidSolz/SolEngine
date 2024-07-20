#include "gameobjectstorage.h"

void GameObjectStorage::add(std::shared_ptr<GameObject> object)
{
    m_toAdd.emplace_back(object);
}

void GameObjectStorage::update(const float &deltaTime)
{
    if (!m_toAdd.empty())
    {
        for (const auto &object : m_toAdd)
        {
            object->awake();
        }

        for (const auto &object : m_toAdd)
        {
            object->start();
        }

        m_objects.assign(m_toAdd.begin(), m_toAdd.end());
        m_toAdd.clear();
    }

    for (auto &object : m_objects)
        object->update(deltaTime);
}

void GameObjectStorage::fixedUpdate(const float &deltaTime)
{
    for (auto &object : m_objects)
        object->fixedUpdate(deltaTime);
}

void GameObjectStorage::draw(GLShader &shader)
{
    for (auto &object : m_objects)
        object->draw(shader);
}
