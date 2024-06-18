#include "geometry.h"

Geometry::Geometry(){

    glGenVertexArrays(1, &m_vao);
    this->m_vbo = 0;
    this->m_ebo = 0;
    this->m_numIndices = 0;
    this->m_numVertices = 0;
    this->m_mode = GL_TRIANGLES;
}

void Geometry::setRenderMode(GLenum mode){
    this->m_mode = mode;
}

void Geometry::setIndices(GLuint * indices, GLint number){
    this->m_numIndices = number;

    glBindVertexArray(m_vao);

    if( m_ebo != 0 )
        glDeleteBuffers(1, &m_ebo);

    glGenBuffers(1, &m_ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, number * sizeof(GLuint), indices, GL_STATIC_DRAW);

    glBindVertexArray(0);
}

void Geometry::setVertices(vec3 * vertices, GLint number){
    this->m_numVertices = number;

    glBindVertexArray(m_vao);

    if( m_vbo != 0 )
        glDeleteBuffers(1, &m_vbo);

    glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, number * sizeof(vec3), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Geometry::render(){

    glBindVertexArray(m_vao);

    if( m_numIndices > 0 ){
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
        glDrawElements(m_mode, m_numIndices, GL_UNSIGNED_INT, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }else{
        glDrawArrays(m_mode, 0, m_numVertices);
    }

    glBindVertexArray(0);

}

Geometry::~Geometry(){
    glDeleteVertexArrays(1, &m_vao);
    glDeleteBuffers(1, &m_vbo);
    glDeleteBuffers(1, &m_ebo);
}
