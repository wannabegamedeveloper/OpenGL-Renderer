#pragma once

#include <GLFW/glfw3.h>
#include <iostream>
#include <map>

class InputManager
{
private:
	std::map <int, bool> keysDown;
	std::map <int, bool> keysUp;

	void addKeyDown(int key);
	void addKeyUp(int key);

public:
	bool GetKey(int key);

	bool GetKeyDown(int key);

	bool GetKeyUp(int key);
};