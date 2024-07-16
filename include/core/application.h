#ifndef APPLICATION_H
#define APPLICATION_H

#include "window.h"
#include "scenemanager.h"

class Application
{
private:
    std::shared_ptr<Window> m_window;

    float m_deltaTime;

    SceneManager m_sceneManager;

    void processInput();

    void update();

    void fixedUpdate();

    void draw();

    bool isRunning() const;

public:
    Application(std::shared_ptr<Window> window) : m_window(window) {}

    void loop();
};

#endif
