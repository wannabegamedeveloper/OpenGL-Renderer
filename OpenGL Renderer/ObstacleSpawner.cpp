#include "ObstacleSpawner.h"

void ObstacleSpawner::StartSpawning(Shader _shader, glm::vec3 _colors1[], glm::vec3 _colors2[], glm::vec3 _colors3[])
{
	shader = &_shader;
	for (int i = 0; i < 3; i++)
		colors[i] = _colors1[i];
	for (int i = 3; i < 8; i++)
		colors[i] = _colors2[i - 3];
	for (int i = 8; i < 15; i++)
		colors[i] = _colors3[i - 8];

	if (!setColors)
	{
		for (int i = 0; i < 100; i++)
		{
			if (i < 15)
				colorIndex[i] = rand() % 3;
			else if (i >= 15 && i < 35)
				colorIndex[i] = (rand() % (7 - 3 + 1)) + 3;
			else
				colorIndex[i] = (rand() % (14 - 8 + 1)) + 8;
		}

		setColors = true;
	}

	Spawn();
}

void ObstacleSpawner::Spawn()
{
	for (int i = 0; i < 100; i++)
	{
		Cube obstacleInstance;
		obstacleInstance.SetPosition(glm::vec3(0.0f, -0.2f, -distance * i));

		if (-distance * i > -45.0f)
			obstacleInstance.SetScale(glm::vec3(0.6f, 0.4f, 0.1f));
		else if (-distance * i <= -45.0f && -distance * i > -95.0f)
			obstacleInstance.SetScale(glm::vec3(0.9f, 0.4f, 0.1f));
		else
			obstacleInstance.SetScale(glm::vec3(1.2f, 0.4f, 0.1f));

		obstacleInstance.SetColor(colors[colorIndex[i]]);
		obstacleInstance.draw(*shader, glm::vec2(3.0f, 1.0f));
	}
}