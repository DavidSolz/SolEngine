#include "texture2d.h"

Texture2D::Texture2D()
{

    this->m_texture = 0;
}

void Texture2D::create(const std::vector<Color> &colors, const GLuint &width, const GLuint &height)
{

    this->m_width = width;
    this->m_height = height;

    if (m_texture != 0)
        glDeleteTextures(1, &m_texture);

    glGenTextures(1, &m_texture);
    glBindTexture(GL_TEXTURE_2D, m_texture);

    if (colors.size() > 0)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, colors.data());
    }
    else
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
    }

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture2D::update(const std::vector<Color> &colors, const GLuint &width, const GLuint &height)
{

    if ((colors.size() != width * height) || (m_width != width) || (m_height != height))
        return;

    if (m_texture == 0)
        glGenTextures(1, &m_texture);

    glBindTexture(GL_TEXTURE_2D, m_texture);

    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, colors.data());

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture2D::setParam(const GLenum &param, const GLint &value)
{

    if (m_texture == 0)
        return;

    glBindTexture(GL_TEXTURE_2D, m_texture);

    glTexParameteri(GL_TEXTURE_2D, param, value);

    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture2D::use() const
{
    glBindTexture(GL_TEXTURE_2D, m_texture);
}

GLuint Texture2D::operator()() const
{
    return m_texture;
}

Texture2D::~Texture2D()
{
    glDeleteTextures(1, &m_texture);
}
