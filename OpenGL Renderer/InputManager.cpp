#include "InputManager.h"

GLFWwindow* windowInstance;

void InputManager::addKeyDown(int key)
{
	if (keysDown.find(key) != keysDown.end())
		keysDown.insert({ key, false });
}

void InputManager::addKeyUp(int key)
{
	if (keysUp.find(key) != keysUp.end())
		keysUp.insert({ key, true });
}

bool InputManager::GetKey(int key)
{
	addKeyDown(key);
	addKeyUp(key);

	return glfwGetKey(windowInstance, key) == GLFW_PRESS;
}

bool InputManager::GetKeyDown(int key)
{
	addKeyDown(key);

	if (glfwGetKey(windowInstance, key) == GLFW_PRESS && !keysDown[key])
	{
		keysDown[key] = true;
		return true;
	}
	else if (glfwGetKey(windowInstance, key) != GLFW_PRESS && keysDown[key])
	{
		keysDown[key] = false;
		return false;
	}
	return false;
}

bool InputManager::GetKeyUp(int key)
{
	addKeyUp(key);

	if (glfwGetKey(windowInstance, key) != GLFW_PRESS && !keysUp[key])
	{
		keysUp[key] = true;
		return true;
	}
	else if (glfwGetKey(windowInstance, key) == GLFW_PRESS && keysUp[key])
	{
		keysUp[key] = false;
		return false;
	}
}