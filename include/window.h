#ifndef WINDOW_H
#define WINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <unordered_map>
#include <iostream>
#include <string>
#include <functional>

class Window{

private:

    const std::unordered_map<GLenum, const char*> errorMap = {
        {GL_NO_ERROR, "GL_NO_ERROR"},
        {GL_INVALID_ENUM, "GL_INVALID_ENUM"},
        {GL_INVALID_VALUE, "GL_INVALID_VALUE"},
        {GL_INVALID_OPERATION, "GL_INVALID_OPERATION"},
        {GL_STACK_OVERFLOW, "GL_STACK_OVERFLOW"},
        {GL_STACK_UNDERFLOW, "GL_STACK_UNDERFLOW"},
        {GL_OUT_OF_MEMORY, "GL_OUT_OF_MEMORY"},
        {GL_INVALID_FRAMEBUFFER_OPERATION, "GL_INVALID_FRAMEBUFFER_OPERATION"},
        {GL_CONTEXT_LOST, "GL_CONTEXT_LOST"}
    };

    GLFWwindow * m_window;

public:

    Window();

    void open(const int & width, const int & height, const std::string & title);

    void setResizeCallback(GLFWwindowsizefun callback);

    void setErrorCallback(GLFWerrorfun callback);

    void clearBuffers(GLenum bufferBits);

    bool shouldClose();

    void update();

    ~Window();
};

#endif
