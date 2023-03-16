#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Window
{
private:
	GLFWwindow* window;

	static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

public:
	Window(int WIDTH, int HEIGHT, const char* title, GLFWmonitor* monitor);
	
	GLFWwindow* GetWindowInstance();
	void GetWindowSize(int* WIDTH, int* HEIGHT);
};