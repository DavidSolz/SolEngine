#include "application.h"

void Application::loop()
{

    while (isRunning())
    {

        m_deltaTime = 1.0f; // TODO

        processInput();
        update();
        fixedUpdate();
        draw();
    }
}

bool Application::isRunning() const
{
    return !m_window->shouldClose();
}

void Application::processInput()
{
    m_sceneManager.processInput(m_window);
}

void Application::update()
{
    m_window->updateFramebufferSize();
    m_window->update();
    m_window->clearBuffers();
    m_sceneManager.update(m_deltaTime);
}

void Application::fixedUpdate()
{
    m_sceneManager.fixedUpdate(m_deltaTime);
}

void Application::draw()
{
    m_sceneManager.draw();
}
