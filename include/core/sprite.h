#ifndef SPRITE_H
#define SPRITE_H

#include "component.h"
#include "texture2d.h"

class Sprite : public Component
{
private:
    Texture2D m_texture;

public:
    Sprite(std::shared_ptr<GameObject> parent) : Component(parent) {}

    void load(const std::string &filepath);

    void draw(GLShader &shader) override;
};

#endif
