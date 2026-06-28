#version 330 core
// 简化光照
// 平行光
struct DirLight {
    vec3 direction;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

in vec2 vTexCoord;
in vec3 vNormal;
in vec3 vFragPos;
in vec3 vViewPos;
in mat3 vTBN;

out vec4 FragColor;

uniform vec3 uViewPos;
uniform DirLight dirLight;
uniform vec3 spotLightPosition;

uniform sampler2D texture_diffuse1; // 漫反射
uniform sampler2D texture_specular1; // 镜面反射
uniform sampler2D texture_normals1; // 法线贴图
uniform vec4 uDiffuseColor;
uniform vec4 uSpecularColor;

uniform float uShininess;
uniform int uNormalMapping;
uniform int uTextureMapping;

vec3 CalcDirLight(vec3 normal, vec3 viewDir, vec3 diffuse, vec3 specular);
vec3 CalcSpotLight(vec3 normal, vec3 fragPos, vec3 viewDir, vec3 diffuse, vec3 specular);

void main()
{
    vec3 norm, viewDir;
    vec4 diffuse, specular;
    if (uTextureMapping == 1) {
        diffuse = uDiffuseColor;
        specular = uSpecularColor;
    } else {
        diffuse = texture(texture_diffuse1, vTexCoord);
        specular = texture(texture_specular1, vTexCoord);
    }
    if (uNormalMapping != 0) {
        norm = texture(texture_normals1, vTexCoord).rgb;
        norm = normalize(norm * 2.0 - 1.0);
        viewDir = normalize(vViewPos - vFragPos);
    } else {
        norm = normalize(vNormal);
        viewDir = normalize(uViewPos - vFragPos);
    }
    // 计算平行光
    vec3 result = CalcDirLight(norm, viewDir, diffuse.rgb, specular.rgb);
    // 计算投射光
    result += CalcSpotLight(norm, vFragPos, viewDir, diffuse.rgb, specular.rgb);
    FragColor = vec4(result, 1.0);
}


vec3 CalcDirLight(vec3 normal, vec3 viewDir, vec3 diffuse, vec3 specular)
{
    // 漫反射
    vec3 lightDir = normalize(-dirLight.direction);
    float diff = max(dot(normal, lightDir), 0.0);
    // 镜面反射
    vec3 halfwayDir = normalize(lightDir + viewDir);
    float spec = pow(max(dot(normal, halfwayDir), 0.0), uShininess);
    // 计算合并最终光照结果
    vec3 a = dirLight.ambient * diffuse;
    vec3 d = dirLight.diffuse * diff * diffuse;
    vec3 s = dirLight.specular * spec * specular;
    return (a + d + s);
}

vec3 CalcSpotLight(vec3 normal, vec3 fragPos, vec3 viewDir, vec3 diffuse, vec3 specular)
{
    vec3 lightDir = uNormalMapping == 0 ? normalize(spotLightPosition - fragPos) : normalize(vTBN * spotLightPosition - fragPos);
    float diff = max(dot(normal, lightDir), 0.0);
    // 镜面反射
    vec3 halfwayDir = normalize(lightDir + viewDir);
    float spec = pow(max(dot(normal, halfwayDir), 0.0), 2);
    vec3 a = diffuse * 0.3;
    vec3 d = diffuse * diff * 0.5;
    vec3 s = specular * spec * 0.2;
    return (a + d + s);
}
