#include "include/window.h"
#include "include/glshader.h"
#include "include/texture2d.h"
#include "include/framebuffer.h"
#include "include/scene.h"

void windowResizeCallback(GLFWwindow * window, int width, int height);
void windowErrorCallback(int code, const char * description);

int main(){

    Window ctx;

    ctx.open(800, 600, "Application");
    ctx.setResizeCallback(windowResizeCallback);
    ctx.setErrorCallback(windowErrorCallback);

    GLShader defaultShader;
    defaultShader.attachShader("shaders/default.vert", GL_VERTEX_SHADER);
    defaultShader.attachShader("shaders/default.frag", GL_FRAGMENT_SHADER);
    defaultShader.link();

    Texture2D backTexture;

    std::vector<color> backcolors = {
        {0, 0, 255, 255},
    };

    backTexture.create(backcolors, 1, 1);
    backTexture.setParam(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    backTexture.setParam(GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    backTexture.setParam(GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    backTexture.setParam(GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    const int32_t width = 2;
    const int32_t height = 2;

    std::vector<Vector3> vertices;

    float horizontalResolution = 1.0f/width;
    float verticalResolution = 1.0f/height;

    for(int32_t i = 0; i < width; i++){

        float x = ( i - width * 0.5f)/(width * 0.5f) + horizontalResolution;

        for(int32_t j = 0; j < height; j++){

            float y = ( j - height * 0.5f)/(height * 0.5f) + verticalResolution;

            vertices.push_back({x, y, 0.0f});

        }

    }

    std::vector<GLuint> indices;

    for (int32_t i = 0; i < width - 1; ++i) {
        for (int32_t j = 0; j < height - 1; ++j) {
            GLuint i0 = i * height + j;
            GLuint i1 = i0 + 1;
            GLuint i2 = (i + 1) * height + j;
            GLuint i3 = i2 + 1;

            indices.push_back(i0);
            indices.push_back(i2);
            indices.push_back(i1);

            indices.push_back(i1);
            indices.push_back(i2);
            indices.push_back(i3);
        }
    }

    glPointSize(3.0f);

    Mesh g;
    g.setVertices(vertices);
    g.setIndices(indices);
    g.setRenderMode(GL_TRIANGLES);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    Matrix4 modelMatrix = Matrix4();

    while ( !ctx.shouldClose() ) {

        ctx.update();
        ctx.clearBuffers(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        defaultShader.use();
        defaultShader.setUniform("modelMatrix", modelMatrix);

        backTexture.use();
        g.render();

    }

    return 0;
}

void windowResizeCallback(GLFWwindow * window, int width, int height){
    glViewport(0, 0, width, height);
}

void windowErrorCallback(int code, const char * description){
    std::cout << "Error " << code << " : " << description << std::endl;
}
