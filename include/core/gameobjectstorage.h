#ifndef GAME_OBJECT_STORAGE_H
#define GAME_OBJECT_STORAGE_H

#include "gameobject.hpp"
#include <memory>
#include <vector>

class GameObjectStorage
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
