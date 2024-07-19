#ifndef OBJECT_WAREHOUSE_H
#define OBJECT_WAREHOUSE_H

#include "gameobject.hpp"
#include <memory>
#include <vector>

class GameObjectWarehouse
{
private:
    std::vector<std::shared_ptr<GameObject>> m_objects;
    std::vector<std::shared_ptr<GameObject>> m_toAdd;

public:
    void add(std::shared_ptr<GameObject> object);

    void update(const float &deltaTime);

    void fixedUpdate(const float &deltaTime);

    void draw(GLShader &shader);
};

#endif
