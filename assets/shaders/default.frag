#version 410 core

in vec2 o_texCoord;

out vec4 fragmentColor;

uniform sampler2D colorTexture;

void main(){
    fragmentColor = texture(colorTexture, o_texCoord);
}
