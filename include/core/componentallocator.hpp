#ifndef COMPONENT_ALLOCATOR_H
#define COMPONENT_ALLOCATOR_H

#include "component.h"

#include <typeinfo>
#include <memory>
#include <unordered_map>

class GameObject;

class ComponentAllocator
{
private:
    std::unordered_map<unsigned int, std::unordered_map<size_t, std::shared_ptr<Component>>> m_components;

public:
    void awake(const unsigned int &id);

    void start(const unsigned int &id);

    void update(const unsigned int &id, const float &deltaTime);

    void fixedUpdate(const unsigned int &id, const float &deltaTime);

    void draw(const unsigned int &id, GLShader &shader);

    template <typename T>
    std::shared_ptr<T>
    addComponent(const unsigned int &id, std::shared_ptr<GameObject> object)
    {
        const auto &typeID = typeid(T).hash_code();

        auto componentIterator = m_components[id].find(typeID);

        if (componentIterator != m_components[id].end())
            return std::dynamic_pointer_cast<T>(componentIterator->second);

        std::shared_ptr<T> component = std::make_shared<T>(object);
        m_components[id][typeID] = component;

        return component;
    }

    template <typename T>
    std::shared_ptr<T>
    getComponent(const unsigned int &id)
    {
        const auto &typeID = typeid(T).hash_code();

        auto componentIterator = m_components[id].find(typeID);

        if (componentIterator != m_components[id].end())
            return std::dynamic_pointer_cast<T>(componentIterator->second);

        return nullptr;
    }
};

#endif
