#ifndef GL_SHADER_H
#define GL_SHADER_H

#include <GL/glew.h>
#include <string>
#include <unordered_map>
#include <fstream>
#include <iostream>
#include "vector3.h"
#include "matrix4.h"

class GLShader {

private:

    std::unordered_map<std::string, GLint> m_uniforms;
    GLuint m_shader;

    bool checkShaderStatus(GLuint shader);

    bool checkProgramStatus(GLuint shader);

    GLint locateUniform(const std::string & name);

public:

    GLShader();

    void attachShader(const std::string & shaderPath, const GLenum & type);

    void setUniform(const std::string & name, const GLfloat & value);

    void setUniform(const std::string & name, const GLint & value);

    void setUniform(const std::string & name, const Vector3 & value);

    void setUniform(const std::string & name, const Matrix4 & value);

    void link();

    void use();

    ~GLShader();

};

#endif
