#pragma once
#include "MainMenu.h"
#include "Level1.h"

#include <GLFW/glfw3.h>

class SceneRenderer
{
private:
	Level1 level1;
	MainMenu mainMenu;

	int oldIndex = 0;

	bool startCalled;

public:
	void Start();
	void Update();
	void ClearData();

	friend class MainMenu;
};