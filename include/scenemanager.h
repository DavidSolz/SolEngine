#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "scene.h"
#include "glshader.h"

class SceneManager {

private:

    Scene * m_scene;

    GLShader m_defaultShader;

public:

    SceneManager(Scene & scene);

    void render();


};

#endif
