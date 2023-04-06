#include "PointLight.h"

void PointLight::SetupLight(Shader shader, Camera camera)
{
	cube.SetPosition(position);
	cube.SetColor(color);

	shader.Use();

	GLint loc = glGetUniformLocation(shader.GetID(), "cameraPos");
	glUniform3fv(loc, 1, glm::value_ptr(camera.GetPosition()));

	std::cout << camera.GetPosition().z << std::endl;

	cube.SetScale(glm::vec3(0.1f, 0.1f, 0.1f));
	cube.draw(shader, glm::vec2(1.0f, 1.0f));
}

void PointLight::SetPosition(glm::vec3 pos, Shader shader)
{
	position = pos;

	shader.Use();

	GLint loc = glGetUniformLocation(shader.GetID(), "lightPos");
	glUniform3fv(loc, 1, glm::value_ptr(pos));
}

void PointLight::SetColor(glm::vec3 col, Shader shader)
{
	color = col;

	shader.Use();

	GLint loc = glGetUniformLocation(shader.GetID(), "lightColor");
	glUniform3fv(loc, 1, glm::value_ptr(color));
}