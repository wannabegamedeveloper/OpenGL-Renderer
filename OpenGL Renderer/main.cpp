#include "SceneRenderer.h"
#include "Window.h"

#include "Shader.h"
#include "Texture.h"
#include "Cube.h"
#include "Camera.h"
#include "Time.h"

float WIDTH = 800, HEIGHT = 800;

glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 1.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

int main()
{
	Window window(WIDTH, HEIGHT, "test game", glfwGetPrimaryMonitor());

	extern GLFWwindow* windowInstance;
	windowInstance = window.GetWindowInstance();

	SceneRenderer sceneRenderer;
	sceneRenderer.Start();

	glEnable(GL_DEPTH_TEST);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	Time time;

	while (!glfwWindowShouldClose(window.GetWindowInstance()))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		time.CreateDeltaTime();
		sceneRenderer.Update(time.GetDeltaTime());

		glfwSwapBuffers(window.GetWindowInstance());
		glfwPollEvents();
	}

	sceneRenderer.ClearData();

	glfwTerminate();
	return 0;
}

