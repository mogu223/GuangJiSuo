#version 330 core

in vec2 vTexCoord;

uniform int uType; // 0 仅纹理 1 颜色 * 纹理
uniform vec4 uColor;
uniform sampler2D uTexture;

out vec4 FragColor;

void main(){
    if (uType == 0) {
        FragColor = texture(uTexture, vTexCoord);
    } else {
        FragColor = texture(uTexture, vTexCoord) * uColor;
    }
}