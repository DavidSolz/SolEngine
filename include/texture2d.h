#ifndef TEXUTRE_2D_H
#define TEXUTRE_2D_H

#include <GL/glew.h>
#include <vector>
#include "color.h"

class Texture2D{

private:

    GLuint m_texture;
    GLuint m_width;
    GLuint m_height;

public:

    Texture2D();

    void create(const std::vector<color> & colors, const GLuint & width, const GLuint & height);

    void update(const std::vector<color> & colors, const GLuint & width, const GLuint & height);

    void setParam(const GLenum & param, const GLint & value);

    void operator()();

    ~Texture2D();
};

#endif
