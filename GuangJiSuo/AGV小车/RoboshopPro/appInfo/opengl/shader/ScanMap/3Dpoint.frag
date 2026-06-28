#version 330 core

in vec4 vColor;
in vec3 vPos;
out vec4 FragColor;

uniform vec2 uZRange;
uniform int uClipping;

void main(){
    if(uClipping != 0 && (vPos.z < uZRange[0] || vPos.z > uZRange[1])) {
        discard;
    }
    FragColor = vColor;
}
