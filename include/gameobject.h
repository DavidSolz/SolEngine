#ifndef OBJECT_H
#define OBJECT_H

#include <GL/glew.h>
#include <memory>
#include <vector>
#include <cassert>

#include "component.h"

class GameObject
{

private:
    std::vector<std::shared_ptr<Component>> components;

public:
    void awake();

    void start();

    void update(const float &deltaTime);

    void fixedUpdate(const float &deltaTime);

    void draw();

    template <typename T>
    std::shared_ptr<T> addComponent();

    template <typename T>
    std::shared_ptr<T> getComponent();
};

#endif
