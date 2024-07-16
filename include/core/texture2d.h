#ifndef TEXTURE_2D_H
#define TEXTURE_2D_H

#include <GL/glew.h>
#include <string>
#include <iostream>

class Texture2D
{

private:
    GLuint m_texture;
    GLuint m_width;
    GLuint m_height;
    GLenum m_format;

public:
    Texture2D();

    void setParam(const GLenum &param, const GLint &value);

    void create(const GLuint &width, const GLuint &height, const GLenum &format);

    void bind() const;

    bool loadFromFile(const std::string &filepath);

    GLenum getFormat() const;

    ~Texture2D();
};

#endif
