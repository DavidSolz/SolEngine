#ifndef GL_SHADER_H
#define GL_SHADER_H

#include <GL/glew.h>
#include <string>
#include <unordered_map>
#include <fstream>
#include <iostream>
#include "vec3.h"
#include "mat4.h"

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

    void setUniform(const std::string & name, const Vec3 & value);

    void setUniform(const std::string & name, const Mat4 & value);

    void link();

    void use();

    ~GLShader();

};

#endif
