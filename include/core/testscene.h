#ifndef TEST_SCENE_H
#define TEST_SCENE_H

#include "sprite.h"
#include "mesh.h"
#include "scene.h"
#include "glshader.h"
#include "window.h"

class TestScene : public Scene
{
private:
    std::shared_ptr<Sprite> m_sprite;
    std::shared_ptr<Transform> m_transform;

    Mesh m_mesh;
    GLShader m_shader;

    void create()
    {
        m_shader.attachShader("assets/shaders/default.vert", GL_VERTEX_SHADER);
        m_shader.attachShader("assets/shaders/default.frag", GL_FRAGMENT_SHADER);
        m_shader.link();

        auto object = createObject();
        m_transform = object->transform;

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

        m_sprite = object->addComponent<Sprite>();
        m_sprite->load("assets/textures/square.png");
    }

public:
    TestScene() : Scene()
    {
        onCreate.add([this]()
                     { create(); });
    }

    void update(const float &deltaTime) override
    {

        const auto position = m_transform->getLocalPosition();

        if (Input::getKeyDown(GLFW_KEY_RIGHT))
            m_transform->setX(position.x + deltaTime);

        if (Input::getKeyDown(GLFW_KEY_LEFT))
            m_transform->setX(position.x - deltaTime);

        if (Input::getKeyDown(GLFW_KEY_UP))
            m_transform->setY(position.y + deltaTime);

        if (Input::getKeyDown(GLFW_KEY_DOWN))
            m_transform->setY(position.y - deltaTime);

        m_objects.update(deltaTime);
    }

    void draw() override
    {
        m_shader.use();
        m_shader.setUniform("modelMatrix", m_transform->getModelMatrix());
        m_objects.draw(m_shader);
        m_mesh.render();
    }
};

#endif
