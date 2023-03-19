#pragma once

#include "Shader.h"
#include "Texture.h"
#include "Cube.h"
#include "Camera.h"

#include "InputManager.h"
#include "LevelManager.h"

class MainMenu
{
private:
	InputManager inputManager;
	LevelManager levelManager;

public:
	void Start();
	void Update();

	void ClearData();
};