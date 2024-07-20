#ifndef OBJECT_H
#define OBJECT_H

#include <GL/glew.h>
#include <vector>
#include <memory>

#include "componentallocator.hpp"

#include "transform.h"
#include "glshader.h"

class GameObject
{
private:
    unsigned int m_id = 0;

    std::shared_ptr<ComponentAllocator> m_allocator;

public:
    GameObject(const unsigned int &id, std::shared_ptr<ComponentAllocator> allocator);

    void awake();

    void start();

    void update(const float &deltaTime);

    void fixedUpdate(const float &deltaTime);

    void draw(GLShader &shader);

    unsigned int getID() const;

    template <typename T>
    std::shared_ptr<T> addComponent()
    {
        return m_allocator->addComponent<T>(m_id, std::make_shared<GameObject>(*this));
    }

    template <typename T>
    std::shared_ptr<T> getComponent()
    {
        return m_allocator->getComponent<T>(m_id);
    }

    std::shared_ptr<Transform> transform;
};

#endif
