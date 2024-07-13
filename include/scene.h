#ifndef SCENE_H
#define SCENE_H

#include "mesh.h"
#include "entity.h"

#include <vector>
#include <map>

class Scene{

private:

    std::vector<Mesh> m_meshes;

    std::vector< Entity* > m_entities;

public:

    void addEntity(Entity & entity);

    void addEntities(std::vector<Entity> & entities);

    void addMesh(Mesh & mesh);

    void addMeshes(std::vector<Mesh> & meshes);

    std::vector<Entity*>& getEntities();

    std::vector<Mesh>& getMeshes();

};

#endif
