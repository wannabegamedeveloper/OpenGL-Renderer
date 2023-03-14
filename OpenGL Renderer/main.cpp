#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Shader.h"
#include "Texture.h"
#include "Cube.h"
#include "Camera.h"

bool pressed;

float WIDTH = 1920, HEIGHT = 1080;

glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 1.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

float deltaTime = 0.0f;
float lastFrame = 0.0f;

float pitch = 0.0f, yaw = 0.0f;

bool firstMouse = true;
float lastX = WIDTH / 2;
float lastY = HEIGHT / 2;

glm::vec3 direction = glm::vec3(0.0f);

Camera camera;

void mouse_callback(GLFWwindow* window, double xPos, double yPos)
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

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	std::cout << "Width: " << width << std::endl << "Height: " << height << std::endl;
	WIDTH = width;
	HEIGHT = height;
}

void randomColor()
{
	float r, g, b;
	r = (float)rand() / (float)(RAND_MAX);
	g = (float)rand() / (float)(RAND_MAX);
	b = (float)rand() / (float)(RAND_MAX);
	glClearColor(r, g, b, 1.0f);
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS && !pressed)
	{
		randomColor();
		pressed = true;
	}
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_RELEASE && pressed)
	{
		randomColor();
		pressed = false;
	}

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
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "test", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW Window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetInputMode(window, GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);

	Texture texture1("grid.jpg", GL_RGB);
	Texture texture2("twitter.png", GL_RGBA);

	Shader shader("unlit_textured.shader");
	shader.AttachTextureToSlot(texture1, 0);
	shader.AttachTextureToSlot(texture2, 1);

	Cube cube;

	glEnable(GL_DEPTH_TEST);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	while (!glfwWindowShouldClose(window))
	{
		float currentFrame = static_cast<float>(glfwGetTime());
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		processInput(window);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		camera.setCamera(90.0f, WIDTH, HEIGHT, 0.01f, 100.0f, shader);
		camera.SetPosition(cameraPos);

		cube.draw(shader, glm::vec3(0.0f, 0.0f, 0.0f));
		cube.SetRotation(40.0f, glm::vec3(0.0f, 1.0f, 0.0f));

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	cube.clearData();
	shader.Delete();

	glfwTerminate();
	return 0;
}

