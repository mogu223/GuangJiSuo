#version 330 core

in vec3 vPos;
in vec4 vColor;
flat in int vLineType;

out vec4 FragColor;

uniform vec3 uViewPos;

void main()
{
    float dist = distance(uViewPos, vPos);
    if (vLineType == 0) {
        if (dist > 25)
            discard;
        else {
            FragColor = vec4(vColor.rgb, vColor.a * (25.0 - dist) / 25.0);
        }
    } else {
        if (dist > 80)
            discard;
        else {
            FragColor = vec4(vColor.rgb, vColor.a * (80.0 - dist) / 80.0);
        }
    }
}