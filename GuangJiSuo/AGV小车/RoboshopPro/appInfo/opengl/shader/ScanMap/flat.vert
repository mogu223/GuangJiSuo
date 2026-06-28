#version 330 core
layout (location = 0) in vec4 aPos;

uniform mat4 uMatrix;
uniform mat4 uModel;

out vec3 vPos;
out vec4 vColor;
flat out int vLineType;

void main(void)
{
    gl_Position = uMatrix * vec4(aPos.xy, 0.0, 1.0);
    vPos = (uModel * vec4(aPos.xy, 0.0, 1.0)).xyz;
    vLineType = int(aPos.w);

    if (vLineType == 0) { // 子网格
        vColor = vec4(0.31, 0.31, 0.31, 1.0);
        return;
    }

    
    if (int(aPos.z) == 0) { // Y轴线
        if (int(vPos.x) == 0) {
            vColor = vec4(0.5137, 0.8, 0.05882, 1.0);
            return;
        }
    } else { // X轴线
        if (int(vPos.y) == 0) {
            vColor = vec4(0.9137, 0.2156, 0.3176, 1.0);
            return;
        }
    }

    // 主网格
    vColor = vec4(0.35, 0.35, 0.35, 1.0);
}