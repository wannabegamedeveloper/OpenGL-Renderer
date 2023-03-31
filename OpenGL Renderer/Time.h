#pragma once

#include <GLFW/glfw3.h>

class Time
{
private:
	float deltaTime = 0.0f;
	float lastFrame = 0.0f;

public:
	void CreateDeltaTime();
	float GetDeltaTime();
};