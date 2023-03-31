#pragma once

#include "Shader.h"
#include "Texture.h"
#include "Cube.h"
#include "Camera.h"

#include "PlayerMovement.h"
#include "PlatformSpawner.h"

#include "Time.h"

#include <GLFW/glfw3.h>

class Level1
{
private:
	Texture* gridTex;
	Shader* unlitTex;
	Texture* containerTex;
	Shader* unlitColor;

	Camera camera;

	Cube platform;
	Cube playerCube;

	Time time;

	PlayerMovement playerMovement;

	float speed = 2.0f;
	float positionZ = 1.0f;

	PlatformSpawner platformSpawner;

	bool levelStarted;

public:
	void Start();
	void Update();

	void ClearData();
};