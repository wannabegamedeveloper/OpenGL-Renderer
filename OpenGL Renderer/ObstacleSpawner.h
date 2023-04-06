#pragma once

#include "Cube.h"

#include <list>

class ObstacleSpawner
{
private:
	float zPos;
	float distance = 3.0f;

	int colorIndex[100];

	Shader *shader;

	bool setColors = false;

	glm::vec3 colors[15];

public:
	void StartSpawning(Shader _shader, glm::vec3 _colors1[], glm::vec3 _colors2[], glm::vec3 _colors3[]);
	void Spawn();
};