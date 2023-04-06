#pragma once

#include "Cube.h"
#include "InputManager.h"

#include "CollisionDetector.h"
#include "PlatformSpawner.h"
#include "ObstacleSpawner.h"

class PlayerMovement
{
private:
	float zPos = 0.0f;
	float movementSpeed = -2.0f;

	InputManager inputManager;

	glm::vec3 position;

	int currentPhase = 0;

	CollisionDetector col;	
	PlatformSpawner ps;
	ObstacleSpawner os;

	float clamp(float n, float lower, float upper);

public:
	void Move(Cube& cube, float deltaTime, Shader);
};