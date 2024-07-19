#ifndef OBJECT_H
#define OBJECT_H

#include <GL/glew.h>
#include <memory>
#include <vector>
#include <cassert>

#include "component.h"
#include "transform.h"
#include "glshader.h"

class GameObject
{

private:
    std::vector<std::shared_ptr<Component>> m_components;

public:
    GameObject();

    void awake();

    void start();

    void update(const float &deltaTime);

    void fixedUpdate(const float &deltaTime);

    void draw(GLShader &shader);

    template <typename T>
    std::shared_ptr<T> addComponent()
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
    std::shared_ptr<T> getComponent()
    {
        static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");

        for (auto &exisitingComponent : m_components)
        {
            if (std::dynamic_pointer_cast<T>(exisitingComponent))
                return std::dynamic_pointer_cast<T>(exisitingComponent);
        }

        return nullptr;
    }

    std::shared_ptr<Transform> transform;
};

#endif
