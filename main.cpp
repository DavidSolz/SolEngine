#include "include/window.h"
#include "include/geometry.h"
#include "include/glshader.h"

std::unordered_map<std::string, Geometry *> geometries;

void windowResizeCallback(GLFWwindow * window, int width, int height);
void windowErrorCallback(int code, const char * description);


int main(){

    Window ctx;

    ctx.open(800, 600, "Application");
    ctx.setResizeCallback(windowResizeCallback);
    ctx.setErrorCallback(windowErrorCallback);

    geometries["triangle"] = new Geometry();

    vec3 vertices[3] = {
        {-1.0, -1.0, 0.0},
        {1.0, -1.0, 0.0},
        {0.0, 1.0, 0.0}
    };

    geometries["triangle"]->setVertices(vertices, 3);

    GLShader defaultShader;
    defaultShader.attachShader("shaders/default.vert", GL_VERTEX_SHADER);
    defaultShader.attachShader("shaders/default.frag", GL_FRAGMENT_SHADER);
    defaultShader.link();

    while ( !ctx.shouldClose() )
    {

        ctx.update();
        ctx.clearBuffers(GL_COLOR_BUFFER_BIT);

        defaultShader.use();

        geometries["triangle"]->render();

    }

    for( auto pair : geometries)
        delete pair.second;

    return 0;
}

void windowResizeCallback(GLFWwindow * window, int width, int height){
    glViewport(0, 0, width, height);
}

void windowErrorCallback(int code, const char * description){
    std::cout << "Error " << code << " : " << description << std::endl;
}
