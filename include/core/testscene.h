#ifndef TEST_SCENE_H
#define TEST_SCENE_H

#include "sprite.h"
#include "mesh.h"
#include "gameobject.h"
#include "scene.h"
#include "glshader.h"
#include "window.h"

#include "input.h"
#include "resourceloader.hpp"

class TestScene : public Scene
{
private:
    std::shared_ptr<Sprite> m_sprite;
    GameObject m_object;

    Mesh m_mesh;
    GLShader m_shader;

public:
    void onCreate() override
    {
        m_shader.attachShader("assets/shaders/default.vert", GL_VERTEX_SHADER);
        m_shader.attachShader("assets/shaders/default.frag", GL_FRAGMENT_SHADER);
        m_shader.link();

        float width = 0.5f, height = 0.5f;

        std::vector<Vector3> vertices = {
            {-width * 0.5f, -height * 0.5f, 0.0f},
            {-width * 0.5f, height * 0.5f, 0.0f},
            {width * 0.5f, height * 0.5f, 0.0f},
            {width * 0.5f, -height * 0.5f, 0.0f}};

        std::vector<GLuint> indices = {
            0, 1, 2,
            0, 2, 3};

        std::vector<float> texCoords = {
            0.0f, 0.0f,
            0.0f, 1.0f,
            1.0f, 1.0f,
            1.0f, 0.0f};

        m_mesh.setVertices(vertices);
        m_mesh.setIndices(indices);
        m_mesh.setTexCoords(texCoords);

        m_sprite = m_object.addComponent<Sprite>();
        m_sprite->load("assets/textures/square.png");
    }

    void onDestroy() override
    {
    }

    void update(const float &deltaTime) override
    {
        static float accumulatedTime;
        static bool lastPressed = false;
        static int counter = 0;

        m_object.transform->setLocalPosition(Vector3(std::cos(accumulatedTime), 0, 0));
        m_object.update(deltaTime);

        accumulatedTime += deltaTime;

        bool isPressed = Input::getKeyDown(GLFW_KEY_SPACE);

        if (isPressed && !lastPressed)
        {
            counter++;
            lastPressed = true;
        }
        else if (!isPressed && lastPressed)
        {
            lastPressed = false;
        }

        if (Input::getKeyDown(GLFW_KEY_R))
            counter = 0;

        std::fprintf(stdout, "Counter: % 5d\r", counter);
        std::fflush(stdout);
    }

    void draw() override
    {
        m_shader.use();
        m_shader.setUniform("modelMatrix", m_object.transform->getModelMatrix());
        m_object.draw(m_shader);
        m_mesh.render();
    }
};

#endif
