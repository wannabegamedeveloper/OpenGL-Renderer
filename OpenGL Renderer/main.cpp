#include "LevelManager.h"
#include "Window.h"

#include "Shader.h"
#include "Texture.h"
#include "Cube.h"
#include "Camera.h"

bool pressed;

float WIDTH = 800, HEIGHT = 800;

glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 1.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

float deltaTime = 0.0f;
float lastFrame = 0.0f;

float pitch = 0.0f, yaw = 0.0f;

bool firstMouse = true;
float lastX = WIDTH / 2;
float lastY = HEIGHT / 2;

Camera camera;

inline void mouse_callback(GLFWwindow* window, double xPos, double yPos)
{
	float xpos = static_cast<float>(xPos);
	float ypos = static_cast<float>(yPos);

	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos;
	lastX = xpos;
	lastY = ypos;

	float sensitivity = 0.1f;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	yaw += xoffset;
	pitch += yoffset;

	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	camera.SetRotation(glm::vec3(yaw, pitch, 0.0f));
}

void processInput(GLFWwindow* window)
{
	const float cameraSpeed = 2.5f * deltaTime;
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		cameraPos += cameraSpeed * camera.GetForward();
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		cameraPos -= cameraSpeed * camera.GetForward();
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		cameraPos += glm::normalize(glm::cross(camera.GetForward(), cameraUp)) * cameraSpeed;
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		cameraPos -= glm::normalize(glm::cross(camera.GetForward(), cameraUp)) * cameraSpeed;

	cameraPos.y = 0.0f;
}

int main()
{
	Window window(WIDTH, HEIGHT, "test game", glfwGetPrimaryMonitor());

	glfwSetCursorPosCallback(window.GetWindowInstance(), mouse_callback);
	glfwSetInputMode(window.GetWindowInstance(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetInputMode(window.GetWindowInstance(), GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);

	LevelManager levelManager;
	levelManager.ChangeLevel(1);
	levelManager.Start();

	glEnable(GL_DEPTH_TEST);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	while (!glfwWindowShouldClose(window.GetWindowInstance()))
	{
		float currentFrame = static_cast<float>(glfwGetTime());
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		processInput(window.GetWindowInstance());
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		levelManager.Update();

		glfwSwapBuffers(window.GetWindowInstance());
		glfwPollEvents();
	}

	levelManager.ClearData();

	glfwTerminate();
	return 0;
}

