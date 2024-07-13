#ifndef ENTITY_H
#define ENTITY_H

#include "transform.h"

#include <GL/glew.h>
#include <list>
#include <memory>

class Entity{

public:

    std::list<std::unique_ptr<Entity>> children;
    std::unique_ptr<Entity> parent;

    Transform transform;

    GLuint meshID = 0;

    Entity();

    template<typename... Child>
    void addChild(const Child & ... child);

    void update();

    void forceUpdate();

};

#endif
