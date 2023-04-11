#version 330 core

in vec2 texCoord;
in vec4 color;
in vec3 normal;
in vec3 fragmentPos;

out vec4 fragColor;

uniform vec3 defaultColor;
uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 cameraPos;

void main()
{
    // ambient
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColor;

    // diffuse 
    vec3 norm = normalize(normal);
    vec3 lightDir = normalize(lightPos - fragmentPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    // specular
    float specularStrength = 0.5;
    vec3 viewDir = normalize(cameraPos - fragmentPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * lightColor;

    float distance = length(lightPos - fragmentPos);
    float attenuation = 1.0 / (1.0f + 0.09f * distance +
        0.032f * (distance * distance));

    ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;

    vec3 litObj = (ambient + diffuse + specular) * defaultColor;

	fragColor = vec4(litObj, 1.0);
}