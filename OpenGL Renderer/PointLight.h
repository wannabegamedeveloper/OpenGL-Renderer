#pragma once

#include "Cube.h"
#include "Camera.h"

class PointLight
{
private:
	Cube cube;
	glm::vec3 color = glm::vec3(1.0f);
	glm::vec3 position = glm::vec3(0.0f);

public:
	void SetupLight(Shader shader);
	void SetColor(glm::vec3 color, Shader shader);
	void SetPosition(glm::vec3 pos, Shader shader, Camera camera);
};