#pragma once

#include <GLFW/glfw3.h>

#include "Shader.h"
#include "Texture.h"
#include "Cube.h"
#include "Camera.h"

class MainMenu
{
public:
	void Start();
	void Update();

	void ClearData();
};