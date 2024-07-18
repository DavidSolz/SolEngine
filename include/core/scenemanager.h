#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include <unordered_map>
#include <list>

#include "scene.h"

class SceneManager
{
private:
    std::unordered_map<unsigned int, std::shared_ptr<Scene>> m_scenes;
    std::list<unsigned int> m_unusedID;

    std::shared_ptr<Scene> m_currentScene;

    unsigned int m_sceneID;

public:
    SceneManager();

    void update(const float &deltaTime);

    void fixedUpdate(const float &deltaTime);

    void draw();

    unsigned int add(std::shared_ptr<Scene> scene);

    void remove(const unsigned int &id);

    void transiteTo(const unsigned int &id);
};

#endif
