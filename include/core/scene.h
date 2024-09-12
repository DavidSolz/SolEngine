#ifndef SCENE_H
#define SCENE_H

#include "input.h"
#include "componentallocator.hpp"
#include "delegate.hpp"
#include "gameobjectstorage.h"
#include <memory>

class Scene
{
private:
    unsigned int m_objectID;
    ComponentAllocator m_allocator;

protected:
    GameObjectStorage m_objects;
    std::shared_ptr<GameObject> createObject();

public:
    Delegate<void> onCreate;
    Delegate<void> onDestroy;
    Delegate<void> onActivate;
    Delegate<void> onDeactivate;

    virtual void update([[maybe_unused]] const float &deltaTime) {}
    virtual void fixedUpdate([[maybe_unused]] const float &deltaTime) {}
    virtual void draw() {}

    virtual ~Scene() {}
};

#endif
