#ifndef APPLICATION_H
#define APPLICATION_H

#include "window.h"
#include "timer.h"
#include "testscene.h"
#include "input.h"
#include "scenemanager.h"

class Application
{
private:
    float m_deltaTime;
    float m_targetFrameDuration;

    std::shared_ptr<TestScene> m_testscene;

    Window m_window;
    SceneManager m_sceneManager;
    Timer m_timer;

    void update();

    void fixedUpdate();

    void draw();

    bool isRunning() const;

public:
    Application(const std::string &title = "Application", const uint32_t &width = 800, const uint32_t &height = 600);

    void setFramerate(const uint32_t &fps = 60);

    void loop();
};

#endif
