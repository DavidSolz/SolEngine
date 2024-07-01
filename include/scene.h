#ifndef SCENE_H
#define SCENE_H

#include "mesh.h"
#include "entity.h"

#include <vector>

class Scene{

private:

    Entity m_world;

    std::vector<Mesh> m_meshes;

public:

    Scene() = default;

    template<typename... T>
    void addChild(const T & ... child);

    template<typename... T>
    void addMesh(const T & ... mesh);

};



#endif
