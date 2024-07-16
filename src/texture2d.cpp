#include "texture2d.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Texture2D::Texture2D()
{
    glGenTextures(1, &m_texture);
}

bool Texture2D::loadFromFile(const std::string &filepath)
{

    int width, height, nrChannels;
    unsigned char *data = stbi_load(filepath.c_str(), &width, &height, &nrChannels, 0);

    if (data != nullptr)
    {
        m_width = width;
        m_height = height;

        if (nrChannels == 1)
            m_format = GL_RED;
        else if (nrChannels == 3)
            m_format = GL_RGB;
        else if (nrChannels == 4)
            m_format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D, m_texture);
        glTexImage2D(GL_TEXTURE_2D, 0, m_format, m_width, m_height, 0, m_format, GL_UNSIGNED_BYTE, data);

        stbi_image_free(data);
        glBindTexture(GL_TEXTURE_2D, 0);
        return true;
    }
    else
    {
        std::cerr << "Failed to load texture: " << filepath << std::endl;
        return false;
    }
}

void Texture2D::create(const GLuint &width, const GLuint &height, const GLenum &format)
{
    m_width = width;
    m_height = height;
    m_format = format;

    glBindTexture(GL_TEXTURE_2D, m_texture);
    glTexImage2D(GL_TEXTURE_2D, 0, m_format, width, height, 0, m_format, GL_UNSIGNED_BYTE, nullptr);
    glBindTexture(GL_TEXTURE_2D, 0);
}

GLenum Texture2D::getFormat() const
{
    return m_format;
}

void Texture2D::setParam(const GLenum &param, const GLint &value)
{

    glBindTexture(GL_TEXTURE_2D, m_texture);

    glTexParameteri(GL_TEXTURE_2D, param, value);

    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture2D::bind() const
{
    glBindTexture(GL_TEXTURE_2D, m_texture);
}

Texture2D::~Texture2D()
{
    glDeleteTextures(1, &m_texture);
}
