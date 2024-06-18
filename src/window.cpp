#include "window.h"

Window::Window(){

    if( glfwInit() == GLFW_FALSE ){
        exit(-1);
    }

    m_window = NULL;
}

void Window::setResizeCallback(GLFWwindowsizefun callback){
    glfwSetWindowSizeCallback(m_window, callback);
}

void Window::setErrorCallback(GLFWerrorfun callback){
    glfwSetErrorCallback(callback);
}

void Window::open(const int & width, const int & height, const std::string & title){

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

    m_window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    glfwMakeContextCurrent(m_window);

    glewExperimental = true;
    glewInit();

    const GLubyte * device = glGetString(GL_RENDERER);
    const GLubyte * version = glGetString(GL_VERSION);

    std::cout << "Device : " << device << std::endl;
    std::cout << "OpenGL Version : " << version << std::endl;

}

void Window::update(){
    glfwPollEvents();
    glfwSwapBuffers(m_window);

    GLenum error = glGetError();

    if( error == GL_NO_ERROR )
        return;

    std::unordered_map<GLenum, const char *>::const_iterator it = errorMap.find(error);
    std::cout<< "Error " << error << " : " << it->second << std::endl;

}

void Window::clearBuffers(GLenum bufferBits){

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(bufferBits);

}

bool Window::shouldClose(){
    return glfwWindowShouldClose(m_window);
}

Window::~Window(){
    glfwTerminate();
}
