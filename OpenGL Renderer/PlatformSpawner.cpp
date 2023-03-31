#include "PlatformSpawner.h"

void PlatformSpawner::Spawn(Cube platform, Shader shader)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			SpawnPlatform(glm::vec3(x1, -0.5f, -position1), phase1[j],
				platform, shader);

			x1 += 0.2f;

			position1 = i * distance;
		}
		x1 = -0.2f;
	}
	for (int i = 5; i < 10; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			SpawnPlatform(glm::vec3(x2, -0.5f, -position2), phase2[j],
				platform, shader);

			x2 += 0.2f;

			position2 = i * distance;
		}
		x2 = -0.4f;
	}
	for (int i = 10; i < index; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			SpawnPlatform(glm::vec3(x3, -0.5f, -position3), phase3[j],
				platform, shader);

			x3 += 0.2f;

			position3 = i * distance;
		}
		x3 = -0.6f;
	}
}

void PlatformSpawner::SpawnPlatform(glm::vec3 position, glm::vec3 color, 
	Cube platform, Shader shader)
{
	platform.SetPosition(position);
	platform.SetRotation(0.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	platform.SetScale(glm::vec3(0.2f, 0.1f, 10.0f));

	platform.SetColor(color);
	platform.draw(shader, glm::vec2(0.1f, 1.0f));
}