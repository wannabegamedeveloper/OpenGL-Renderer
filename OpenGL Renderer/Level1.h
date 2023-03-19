#pragma once

#include "Shader.h"
#include "Texture.h"
#include "Cube.h"
#include "Camera.h"

#include <GLFW/glfw3.h>

class Level1
{
private:
	Texture* gridTex;
	Shader* unlitTex;

	Camera camera;

	Cube platform;

	bool levelStarted;

public:
	void Start();
	void Update();

	void ClearData();
};