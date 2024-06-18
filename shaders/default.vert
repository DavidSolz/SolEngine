#version 410 core

uniform mat4 modelMatrix;

layout(location = 0) in vec3 vertex;
layout(location = 1) in vec2 texCoords;

out vec2 o_texCoord;

void main(){
    gl_Position =  modelMatrix * vec4(vertex, 1.0);
    o_texCoord = texCoords;
}
