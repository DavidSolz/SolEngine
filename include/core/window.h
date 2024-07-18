#ifndef WINDOW_H
#define WINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <unordered_map>
#include <iostream>
#include <string>

class Window
{

private:
    const std::unordered_map<GLenum, const char *> errorMap = {
        {GL_NO_ERROR, "GL_NO_ERROR"},
        {GL_INVALID_ENUM, "GL_INVALID_ENUM"},
        {GL_INVALID_VALUE, "GL_INVALID_VALUE"},
        {GL_INVALID_OPERATION, "GL_INVALID_OPERATION"},
        {GL_STACK_OVERFLOW, "GL_STACK_OVERFLOW"},
        {GL_STACK_UNDERFLOW, "GL_STACK_UNDERFLOW"},
        {GL_OUT_OF_MEMORY, "GL_OUT_OF_MEMORY"},
        {GL_INVALID_FRAMEBUFFER_OPERATION, "GL_INVALID_FRAMEBUFFER_OPERATION"},
        {GL_CONTEXT_LOST, "GL_CONTEXT_LOST"}};

    GLFWwindow *m_window;
    GLenum m_bufferBits;

    int m_width;
    int m_height;

public:
    Window();

    void open(const int &width, const int &height, const std::string &title);

    void setResizeCallback(GLFWwindowsizefun callback);

    void setErrorCallback(GLFWerrorfun callback);

    void setKeyCallback(GLFWkeyfun callback);

    void setButtonCallback(GLFWmousebuttonfun callback);

    void clearBuffers(GLenum buffer = 0);

    void updateFramebufferSize();

    bool isKeyPressed(const unsigned int &key) const;

    bool isButtonPressed(const unsigned int &button) const;

    int getWindowWidth();

    int getWindowHeight();

    bool shouldClose() const;

    void update();

    ~Window();
};

#endif
