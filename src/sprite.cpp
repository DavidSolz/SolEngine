#include "sprite.h"

void Sprite::load(const std::string &filepath)
{
    m_texture.loadFromFile(filepath);
}

void Sprite::draw()
{
    m_texture.bind();
}
