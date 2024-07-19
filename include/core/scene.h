#ifndef SCENE_H
#define SCENE_H

#include "input.h"
#include "gameobjectwarehouse.h"
#include <memory>

class Scene
{
protected:
    GameObjectWarehouse m_objects;

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
