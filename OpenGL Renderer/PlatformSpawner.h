#pragma once

#include "Cube.h"
#include "InputManager.h"

#include <GLFW/glfw3.h>

class PlatformSpawner
{
private:
	int index = 20;
	float distance = 10.0f;

	float position1 = 0.0f;
	float position2 = 0.0f;
	float position3 = 0.0f;
	float x1 = -0.2f;
	float x2 = -0.2f;
	float x3 = -0.2f;

	glm::vec3 phase1[3] = { glm::vec3(1.0f, 0.3f, 0.6f), 
		glm::vec3(0.6f, 1.0f, 0.3f), 
		glm::vec3(0.3f, 0.6f, 1.0f) };

	glm::vec3 phase2[5] = { glm::vec3(1.0f, 0.3f, 0.6f),
		glm::vec3(0.6f, 1.0f, 0.3f),
		glm::vec3(0.3f, 0.6f, 1.0f),
		glm::vec3(0.3f, 1.0f, 1.0f),
		glm::vec3(1.0f, 0.6f, 1.0f) };

	glm::vec3 phase3[7] = { glm::vec3(1.0f, 0.3f, 0.6f),
		glm::vec3(0.6f, 1.0f, 0.3f),
		glm::vec3(0.3f, 0.6f, 1.0f),
		glm::vec3(0.3f, 1.0f, 1.0f),
		glm::vec3(1.0f, 0.6f, 1.0f),
		glm::vec3(0.0f, 0.6f, 1.0f),
		glm::vec3(1.0f, 0.0f, 1.0f) };

	void SpawnPlatform(glm::vec3 position, glm::vec3 color, Cube platform, Shader shader);

	InputManager inputManager;

public:
	void Spawn(Cube platform, Shader shader);
};