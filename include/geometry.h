#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <GL/glew.h>

#include "vec3.h"

class Geometry{
private:

    GLuint m_vao;
    GLuint m_vbo;
    GLuint m_ebo;

    GLenum m_mode;

    GLuint m_numVertices;
    GLuint m_numIndices;

public:

    Geometry();

    void setRenderMode(GLenum mode);

    void setIndices(GLuint * indices, GLint number);

    void setVertices(vec3 * vertices, GLint number);

    void render();

    ~Geometry();

};


#endif
