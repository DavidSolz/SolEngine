#include "componentallocator.hpp"

void ComponentAllocator::awake(const unsigned int &id)
{
    auto entityIterator = m_components[id];

    for (auto &pair : entityIterator)
        pair.second->awake();
}

void ComponentAllocator::start(const unsigned int &id)
{
    auto entityIterator = m_components[id];

    for (auto &pair : entityIterator)
        pair.second->start();
}

void ComponentAllocator::update(const unsigned int &id, const float &deltaTime)
{
    auto entityIterator = m_components[id];

    for (auto &pair : entityIterator)
        pair.second->update(deltaTime);
}

void ComponentAllocator::fixedUpdate(const unsigned int &id, const float &deltaTime)
{
    auto entityIterator = m_components[id];

    for (auto &pair : entityIterator)
        pair.second->fixedUpdate(deltaTime);
}

void ComponentAllocator::draw(const unsigned int &id, GLShader &shader)
{
    auto entityIterator = m_components[id];

    for (auto &pair : entityIterator)
        pair.second->draw(shader);
}
