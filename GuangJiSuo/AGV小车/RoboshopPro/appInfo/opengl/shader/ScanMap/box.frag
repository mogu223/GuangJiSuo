#version 330 core

in vec3 vFragPos;
in vec3 vNormal;

uniform vec3 uViewPos;
uniform vec4 uColor;

out vec4 FragColor;

void main() {
    vec3 L = normalize(uViewPos - vFragPos);
    float NL = max(dot(normalize(vNormal), L), 0.0);
    vec3 col = clamp(uColor.rgb * 0.4 + uColor.rgb * 0.6 * NL, 0.0, 1.0);
    FragColor = vec4(col, uColor.a);
}
