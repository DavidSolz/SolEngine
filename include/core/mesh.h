#ifndef MESH_H
#define MESH_H

#include <GL/glew.h>
#include <vector>
#include "vector3.h"

class Mesh{
private:

    GLuint m_vao;
    GLuint m_vbo;
    GLuint m_ebo;
    GLuint m_tbo;
    GLuint m_nbo;

    GLenum m_mode;

    GLuint m_numVertices;
    GLuint m_numIndices;

public:

    Mesh();

    void setRenderMode(GLenum mode);

    void setIndices(const std::vector<GLuint> & indices);

    void setVertices(const std::vector<Vector3> & vertices);

    void setNormals(const std::vector<Vector3> & normals);

    void setTexCoords(const std::vector<float> & coords);

    static Mesh genQuad(const int & width, const int & height);

    GLuint getID() const;

    void render();

    ~Mesh();

};


#endif
