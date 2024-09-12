#include "application.h"

Application::Application(const std::string &title, const uint32_t &width, const uint32_t &height)
{
    this->m_deltaTime = m_timer.restart();
    this->m_window.open(width, height, title);
    setFramerate();

    std::shared_ptr<TestScene> m_testscene = std::make_shared<TestScene>();

    auto m_t = m_sceneManager.add(m_testscene);
    m_sceneManager.transiteTo(m_t);
}

void Application::setFramerate(const uint32_t &fps)
{
    uint32_t clampedRate = std::max(uint32_t(1), fps);
    m_targetFrameDuration = 1.0 / clampedRate;
}

void Application::loop()
{

    while (isRunning())
    {
        m_deltaTime = m_timer.restart();

        Input::update(m_window);
        update();
        fixedUpdate();
        draw();
    }
}

SceneManager &Application::getSceneManager()
{
    return m_sceneManager;
}

bool Application::isRunning() const
{
    return !m_window.shouldClose();
}

void Application::update()
{
    m_window.updateFramebufferSize();
    m_window.update();
    m_window.clearBuffers();
    m_sceneManager.update(m_deltaTime);

    const auto elapsed = m_timer.getElapsed();
    const double sleepTime = std::max(m_targetFrameDuration - elapsed, 0.0);
    m_timer.sleepForSeconds(sleepTime);
}

void Application::fixedUpdate()
{
    m_sceneManager.fixedUpdate(m_deltaTime);
}

void Application::draw()
{
    m_sceneManager.draw();
}
