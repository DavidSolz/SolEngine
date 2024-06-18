#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <GL/glew.h>
#include <vector>
#include "vec3.h"

class Geometry{
private:

    GLuint m_vao;
    GLuint m_vbo;
    GLuint m_ebo;
    GLuint m_tbo;

    GLenum m_mode;

    GLuint m_numVertices;
    GLuint m_numIndices;

public:

    Geometry();

    void setRenderMode(GLenum mode);

    void setIndices(const std::vector<GLuint> & indices);

    void setVertices(const std::vector<vec3> & vertices);

    void setTexCoords(const std::vector<float> & coords);

    void render();

    ~Geometry();

};


#endif
