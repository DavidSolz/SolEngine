#ifndef TEST_SCENE_H
#define TEST_SCENE_H

#include "sprite.h"
#include "gameobject.h"
#include "scene.h"

class TestScene : public Scene
{
private:
    std::shared_ptr<Sprite> m_sprite;
    GameObject m_object;

public:
    void onCreate() override
    {
        m_sprite = m_object.addComponent<Sprite>();
        m_sprite->load("assets/textures/square.png");
    }

    void onDestroy() override
    {
    }

    void processInput(Window &window) override
    {
    }

    void update(const float &deltaTime) override
    {
    }

    void draw() override
    {
    }
};

#endif
