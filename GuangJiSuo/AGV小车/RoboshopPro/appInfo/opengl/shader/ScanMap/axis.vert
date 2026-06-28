#version 330 core
layout (location = 0) in vec4 aPos;

uniform mat4 uMatrix;
out vec4 vColor;

void main(void)
{
    gl_Position = uMatrix * vec4(aPos.xyz, 1.0f);
    switch(int(aPos.w)) {
    case 1:
        vColor = vec4(0.5137, 0.8, 0.05882, 1.0);
        break;
    case 2:
        vColor = vec4(0.1804,  0.5255, 0.9176, 1.0f);
        break;
    case 0:
    default:
        vColor = vec4(0.9137, 0.2156, 0.3176, 1.0f); 
    }
}