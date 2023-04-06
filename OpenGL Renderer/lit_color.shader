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
	vec3 norm = normalize(normal);
	vec3 lightDir = normalize(lightPos - fragmentPos);

	float specularStrength = 0.5;

	vec3 viewDir = normalize(cameraPos - fragmentPos);
	vec3 reflectDir = reflect(-lightDir, norm);

	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
	vec3 specular = specularStrength * spec * lightColor;

	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = diff * lightColor;

	float ambientStrength = 0.0;
	vec3 ambient = ambientStrength * lightColor;

	vec3 litObj = (ambient + diffuse + specular) * defaultColor;

	fragColor = vec4(litObj, 1.0);
}