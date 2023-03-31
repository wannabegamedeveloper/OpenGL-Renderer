#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Shader.h"
#include "VAO.h"
#include "VBO.h"

class Cube 
{
private:
	VAO vao;
	VBO vbo;

	GLuint modelLoc;
	glm::mat4 model = glm::mat4(1.0f);

	glm::vec3 _position = glm::vec3(0.0f);
	float _angle = 0.0f;
	glm::vec3 _axis = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 _scale = glm::vec3(1.0f);

	glm::vec3 defaultColor = glm::vec3(1.0f, 1.0f, 1.0f);

public:
	Cube();

	void draw(Shader shader, glm::vec2 tiling);

	void SetPosition(glm::vec3 newPosition);
	void SetRotation(float angle, glm::vec3 axis);
	void SetScale(glm::vec3 newScale);
	void SetColor(glm::vec3 newColor);

	float getPositionZ();

	void clearData();
};