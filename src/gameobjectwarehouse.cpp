#include "gameobjectwarehouse.h"

void GameObjectWarehouse::add(std::shared_ptr<GameObject> object)
{
    m_toAdd.emplace_back(object);
}

void GameObjectWarehouse::update(const float &deltaTime)
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

void GameObjectWarehouse::fixedUpdate(const float &deltaTime)
{
    for (auto &object : m_objects)
        object->fixedUpdate(deltaTime);
}

void GameObjectWarehouse::draw(GLShader &shader)
{
    for (auto &object : m_objects)
        object->draw(shader);
}
