#version 330 core

layout (triangles) in;
layout (triangle_strip, max_vertices = 3) out;

uniform mat4 uMatrix;

out vec3 vNormal;
out vec3 vFragPos;

void main(){
    vec3 edge1 = gl_in[1].gl_Position.xyz - gl_in[0].gl_Position.xyz;  
    vec3 edge2 = gl_in[2].gl_Position.xyz - gl_in[0].gl_Position.xyz;
    vNormal = normalize(cross(edge1, edge2));

    vFragPos = gl_in[0].gl_Position.xyz;
    gl_Position = uMatrix * gl_in[0].gl_Position;
    EmitVertex();
    vFragPos = gl_in[1].gl_Position.xyz;
    gl_Position = uMatrix * gl_in[1].gl_Position;  
    EmitVertex(); 
    vFragPos = gl_in[2].gl_Position.xyz;
    gl_Position = uMatrix * gl_in[2].gl_Position;  
    EmitVertex(); 
    EndPrimitive();

}
