#ifndef COMPONENT_H
#define COMPONENT_H

#include <memory>

#include "glshader.h"

class GameObject;

class Component
{

protected:
    std::shared_ptr<GameObject> m_parent;

public:
    Component(std::shared_ptr<GameObject> parent) : m_parent(parent) {}

    virtual ~Component() {}

    virtual void awake() {}

    virtual void start() {}

    virtual void update([[maybe_unused]] const float &deltaTime) {}

    virtual void fixedUpdate([[maybe_unused]] const float &deltaTime) {}

    virtual void draw([[maybe_unused]]GLShader &shader) {}
};

#endif
