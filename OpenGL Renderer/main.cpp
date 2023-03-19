#include "SceneRenderer.h"
#include "Window.h"

#include "Shader.h"
#include "Texture.h"
#include "Cube.h"
#include "Camera.h"

float WIDTH = 800, HEIGHT = 800;

glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 1.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

float deltaTime = 0.0f;
float lastFrame = 0.0f;

int main()
{
	Window window(WIDTH, HEIGHT, "test game", glfwGetPrimaryMonitor());

	extern GLFWwindow* windowInstance;
	windowInstance = window.GetWindowInstance();

	SceneRenderer sceneRenderer;
	sceneRenderer.Start();

	glEnable(GL_DEPTH_TEST);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	while (!glfwWindowShouldClose(window.GetWindowInstance()))
	{
		float currentFrame = static_cast<float>(glfwGetTime());
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		sceneRenderer.Update();

		glfwSwapBuffers(window.GetWindowInstance());
		glfwPollEvents();
	}

	sceneRenderer.ClearData();

	glfwTerminate();
	return 0;
}

