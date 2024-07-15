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

void GameObject::draw()
{
    for (auto &component : m_components)
        component->draw();
}

template <typename T>
std::shared_ptr<T> GameObject::addComponent()
{
    static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");

    for (auto &exisitingComponent : m_components)
    {
        if (std::dynamic_pointer_cast<T>(exisitingComponent))
            return std::dynamic_pointer_cast<T>(exisitingComponent);
    }

    auto wrappedPtr = std::make_shared<GameObject>(*this);

    std::shared_ptr<T> newComponent = std::make_shared<T>(wrappedPtr);
    m_components.push_back(newComponent);

    return newComponent;
}

template <typename T>
std::shared_ptr<T> GameObject::getComponent()
{
    static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");

    for (auto &exisitingComponent : m_components)
    {
        if (std::dynamic_pointer_cast<T>(exisitingComponent))
            return std::dynamic_pointer_cast<T>(exisitingComponent);
    }

    return nullptr;
}
