#include "scenemanager.h"


SceneManager::SceneManager(Scene & scene){

    this->m_scene = &scene;

    this->m_defaultShader.attachShader("shaders/default.vert", GL_VERTEX_SHADER);
    this->m_defaultShader.attachShader("shaders/default.frag", GL_FRAGMENT_SHADER);
    this->m_defaultShader.link();

}

void SceneManager::render(){

    auto & entities = m_scene->getEntities();
    auto & meshes = m_scene->getMeshes();

    m_defaultShader.use();

    for( auto & entity : entities ){

        entity->update();

        m_defaultShader.setUniform("modelMatrix", entity->transform.getModelMatrix());

        meshes[ 0 ].render();

    }

}
