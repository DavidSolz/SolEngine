#ifndef SCENE_H
#define SCENE_H

#include "input.h"
#include "componentallocator.hpp"
#include "gameobjectstorage.h"
#include <memory>

class Scene
{
protected:
    unsigned int m_objectID;

    ComponentAllocator m_allocator;
    GameObjectStorage m_objects;

    std::shared_ptr<GameObject> createObject();

public:
    virtual void onCreate() = 0;
    virtual void onDestroy() = 0;
    virtual void onActivate() {};
    virtual void onDeactivate() {};

    virtual void update([[maybe_unused]] const float &deltaTime) {}
    virtual void fixedUpdate([[maybe_unused]] const float &deltaTime) {}
    virtual void draw() {}

    virtual ~Scene() {}
};

#endif
