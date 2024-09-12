#include "sprite.h"

void Sprite::load(const std::string &filepath)
{
    m_texture.loadFromFile(filepath);
}

void Sprite::draw([[maybe_unused]] GLShader &shader)
{
    m_texture.bind();
}
