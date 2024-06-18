#include "glshader.h"

GLShader::GLShader(){
    this->m_shader = glCreateProgram();
}

bool GLShader::checkProgramStatus(GLuint shader){

    GLint success;
    glGetProgramiv(shader, GL_LINK_STATUS, &success);

    if (!success) {

        char infoLog[512];
        glGetProgramInfoLog(shader, 512, nullptr, infoLog);
        std::cout << "Program linking error : " << infoLog << std::endl;

        return false;
    }

    return true;
}


bool GLShader::checkShaderStatus(GLuint shader){
    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (!success) {

        char infoLog[512];
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::cout << "Shader compilation error : " << infoLog << std::endl;

        return false;
    }

    return true;
}

void GLShader::attachShader(const std::string & shaderPath, const GLenum type){
    std::ifstream input(shaderPath);

    if( !input.is_open() ){
        std::cout << shaderPath << " can't be opened or does not exist" << std::endl;
        exit(1);
    }

    std::string rawCode((std::istreambuf_iterator<char>(input)), std::istreambuf_iterator<char>());
    input.close();

    const char * rawBytesPtr = rawCode.c_str();
    int numBytes = rawCode.length();

    GLuint shader = glCreateShader(type);

    glShaderSource(shader, 1, &rawBytesPtr, &numBytes);
    glCompileShader(shader);

    if( checkShaderStatus(shader) == false )
        exit(1);

    glAttachShader(m_shader, shader);
    glDeleteShader(shader);

}

void GLShader::link(){
    glLinkProgram(m_shader);

    if( checkProgramStatus(m_shader) == false )
        exit(1);

}

void GLShader::use(){
    glUseProgram(m_shader);
}

GLShader::~GLShader(){
    glUseProgram(0);
    glDeleteProgram(m_shader);

}
