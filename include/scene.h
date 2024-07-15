#ifndef SCENE_H
#define SCENE_H

#include "window.h"

class Scene
{
public:
    virtual void onCreate() = 0;

    virtual void onDestroy() = 0;

    virtual void onActivate() = 0;

    virtual void onDeactivate() = 0;

    virtual void processInput([[maybe_unused]] Window &window) {}

    virtual void update([[maybe_unused]] const float &deltaTime) {}

    virtual void fixedUpdate([[maybe_unused]] const float &deltaTime) {}

    virtual void draw() {}
};

#endif
