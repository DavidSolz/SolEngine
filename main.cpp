#include "include/window.h"
#include "include/geometry.h"
#include "include/glshader.h"
#include "include/texture2d.h"

std::unordered_map<std::string, Geometry *> geometries;

void windowResizeCallback(GLFWwindow * window, int width, int height);
void windowErrorCallback(int code, const char * description);


int main(){

    Window ctx;

    ctx.open(800, 600, "Application");
    ctx.setResizeCallback(windowResizeCallback);
    ctx.setErrorCallback(windowErrorCallback);

    geometries["triangle"] = new Geometry();

    std::vector<vec3> vertices = {
        {-1.0, -1.0, 0.0},
        {1.0, -1.0, 0.0},
        {0.0, 1.0, 0.0}
    };

    std::vector<float> texCoords = {
        0.0f, 0.0f,
        1.0f, 0.0f,
        0.5f, 1.0f
    };

    geometries["triangle"]->setVertices(vertices);
    geometries["triangle"]->setTexCoords(texCoords);

    GLShader defaultShader;
    defaultShader.attachShader("shaders/default.vert", GL_VERTEX_SHADER);
    defaultShader.attachShader("shaders/default.frag", GL_FRAGMENT_SHADER);
    defaultShader.link();

    Texture2D backTexture;

    std::vector<color> backcolors = {
        {255, 0, 0, 255},
        {0, 255, 0, 255},
        {0, 0, 255, 255},
        {255, 255, 255, 255}
    };

    backTexture.create(backcolors, 2, 2);
    backTexture.setParam(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    backTexture.setParam(GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    backTexture.setParam(GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    backTexture.setParam(GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    while ( !ctx.shouldClose() ) {

        ctx.update();
        ctx.clearBuffers(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        float time = glfwGetTime();

        defaultShader.use();

        backTexture();
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
