#ifndef TEST_SCENE_H
#define TEST_SCENE_H

#include "sprite.h"
#include "mesh.h"
#include "gameobject.hpp"
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

        m_objects.add(std::make_shared<GameObject>(m_object));
    }

    void onDestroy() override
    {
    }

    void update(const float &deltaTime) override
    {

        const auto position = m_object.transform->getLocalPosition();

        if (Input::getKeyDown(GLFW_KEY_RIGHT))
            m_object.transform->setX(position.x + deltaTime);

        if (Input::getKeyDown(GLFW_KEY_LEFT))
            m_object.transform->setX(position.x - deltaTime);

        if (Input::getKeyDown(GLFW_KEY_UP))
            m_object.transform->setY(position.y + deltaTime);

        if (Input::getKeyDown(GLFW_KEY_DOWN))
            m_object.transform->setY(position.y - deltaTime);

        m_objects.update(deltaTime);
    }

    void draw() override
    {
        m_shader.use();
        m_shader.setUniform("modelMatrix", m_object.transform->getModelMatrix());
        m_objects.draw(m_shader);
        m_mesh.render();
    }
};

#endif
