#include "gameobject.h"

GameObject::GameObject()
{
    transform = addComponent<Transform>();
}

void GameObject::awake()
{
    for (auto &component : m_components)
        component->awake();
}

void GameObject::start()
{
    for (auto &component : m_components)
        component->start();
}

void GameObject::update(const float &deltaTime)
{
    for (auto &component : m_components)
        component->update(deltaTime);
}

void GameObject::fixedUpdate(const float &deltaTime)
{
    for (auto &component : m_components)
        component->fixedUpdate(deltaTime);
}

void GameObject::draw(GLShader &shader)
{
    for (auto &component : m_components)
        component->draw(shader);
}
