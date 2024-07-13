#include "scene.h"

void Scene::addEntity(Entity & entity){
    m_entities.emplace_back( &entity );
}

void Scene::addEntities(std::vector<Entity> & entities){

    for( Entity & entity : entities ){
        m_entities.emplace_back( &entity );
    }

}

void Scene::addMesh(Mesh & mesh){
    m_meshes.emplace_back( mesh );
}

void Scene::addMeshes(std::vector<Mesh> & meshes){

    for( Mesh & mesh : meshes){
        m_meshes.emplace_back( mesh );
    }

}

std::vector< Entity* >& Scene::getEntities(){
    return m_entities;
}

std::vector<Mesh>& Scene::getMeshes(){
    return m_meshes;
}

