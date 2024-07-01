#ifndef ENTITY_H
#define ENTITY_H

#include "transform.h"

#include <list>

class Entity{

public:

    std::list<std::unique_ptr<Entity>> children;
    std::unique_ptr<Entity> parent = nullptr;

    Transform transform;

    unsigned int meshID = 0;

    template<typename... Child>
    void addChild(const Child & ... child);

    void update();

    void forceUpdate();

};

#endif
