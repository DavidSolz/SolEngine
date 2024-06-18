#ifndef GL_SHADER_H
#define GL_SHADER_H

#include <GL/glew.h>
#include <string>
#include <unordered_map>
#include <fstream>
#include <iostream>
#include "vec3.h"

class GLShader {

private:

    std::unordered_map<std::string, GLint> m_uniforms;
    GLuint m_shader;

    bool checkShaderStatus(GLuint shader);

    bool checkProgramStatus(GLuint shader);

public:

    GLShader();

    void attachShader(const std::string & shaderPath, const GLenum type);

    void link();

    void use();

    ~GLShader();

};

#endif
