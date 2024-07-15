#include "gameobject.h"

void GameObject::awake()
{

    for (auto &component : components)
        component->awake();
}

void GameObject::start()
{
    for (auto &component : components)
        component->start();
}

void GameObject::update(const float &deltaTime)
{
    for (auto &component : components)
        component->update(deltaTime);
}

void GameObject::fixedUpdate(const float &deltaTime)
{
    for (auto &component : components)
        component->fixedUpdate(deltaTime);
}

void GameObject::draw()
{
    for (auto &component : components)
        component->draw();
}

template <typename T>
std::shared_ptr<T> GameObject::addComponent()
{
    static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");

    for (auto &exisitingComponent : components)
    {
        if (std::dynamic_pointer_cast<T>(exisitingComponent))
            return std::dynamic_pointer_cast<T>(exisitingComponent);
    }

    std::shared_ptr<T> newComponent = std::make_shared<T>(this);
    components.push_back(newComponent);

    return newComponent;
}

template <typename T>
std::shared_ptr<T> GameObject::getComponent()
{
    static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");

    for (auto &exisitingComponent : components)
    {
        if (std::dynamic_pointer_cast<T>(exisitingComponent))
            return std::dynamic_pointer_cast<T>(exisitingComponent);
    }

    return nullptr;
}
