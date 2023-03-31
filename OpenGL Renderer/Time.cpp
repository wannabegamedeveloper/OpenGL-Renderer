#include "Time.h"

void Time::CreateDeltaTime()
{
	float currentFrame = static_cast<float>(glfwGetTime());
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;
}

float Time::GetDeltaTime()
{
	return deltaTime;
}