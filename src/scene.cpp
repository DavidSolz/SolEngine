#include "scene.h"


template<typename... T>
void Scene::addChild(const T & ... child){
    m_world.addChild(std::make_unique<Entity>(child...));
}

template<typename... T>
void Scene::addMesh(const T & ... mesh){
    m_meshes.emplace_back(mesh...);
}

