#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>

#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "Shader.h"
#include "Texture.h"

bool pressed;

float WIDTH = 1920, HEIGHT = 1080;

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
}

void UpdateVertexPosition(VBO vbo, GLfloat glPosX, GLfloat glPosY, int index)
{
	vbo.BindVBO();
	GLfloat vertices2[] =
	{
		glPosX,  glPosY
	};
	glBufferSubData(GL_ARRAY_BUFFER, index * sizeof(GLfloat), 2 * sizeof(GLfloat), vertices2);
}

void normalizeData(float value, float* result, float MAX)
{
	*result = ((value - (MAX / 2)) / (MAX / 2));
}

int test = 0;

void FindClosestVertex(float posX, float posY, int dataSize, float* vertices, float threshold, int* index)
{
	float distance = 0.0f;
	float leastDistance = 200.0f;
	int closestIndex = -1;

	for (int i = 0; i < dataSize; i += 5)
	{
		float distance = sqrt(pow(posX - vertices[i], 2) + pow(posY - vertices[i + 1], 2));

		if (distance < leastDistance && distance < threshold)
		{
			leastDistance = distance;
			closestIndex = i;
		}
	}

	*index = closestIndex;
}

int main()
{
	GLfloat vertices[] =
	{
		//  positions			//  tex coords
		0.5f,  0.5f, 0.0f,		1.0f, 1.0f,
		0.5f, -0.5f, 0.0f,		1.0f, 0.0f,
	   -0.5f, -0.5f, 0.0f,		0.0f, 0.0f,
	   -0.5f,  0.5f, 0.0f,		0.0f, 1.0f
	};

	GLuint indices[] =
	{
		0, 1, 3,
		1, 2, 3
	};

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

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	Shader shader("vert.shader", "frag.shader");

	VAO vao;
	vao.CreateVAO();

	VBO vbo;
	vbo.CreateVBO();

	EBO ebo;
	ebo.CreateEBO();

	Texture texture1("container.jpg");
	texture1.GenerateTexture();
	texture1.BindTexture();
	texture1.CreateTexture(GL_RGB);

	Texture texture2("twitter.png");
	texture2.GenerateTexture();
	texture2.BindTexture();
	texture2.CreateTexture(GL_RGBA);

	//TRIANGLE 1
	vao.BindVAO();

	vbo.BindVBO();
	vbo.AddBufferData(sizeof(vertices), vertices, GL_STATIC_DRAW);

	ebo.BindEBO();
	ebo.AddBufferData(sizeof(indices), indices, GL_STATIC_DRAW);

	vao.LinkAttributesToShader(0, 3, GL_FLOAT, 5 * sizeof(GL_FLOAT), (void*)0);
	vao.LinkAttributesToShader(1, 2, GL_FLOAT, 
		5 * sizeof(GL_FLOAT), (void*)(3 * sizeof(GL_FLOAT)));

	vbo.UnbindVBO();

	shader.Use();
	glUniform1i(glGetUniformLocation(shader.GetID(), "tex1"), 0);
	glUniform1i(glGetUniformLocation(shader.GetID(), "tex2"), 1);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	bool clicked = false;
	float factorX = 0.0f;
	float factorY = 0.0f;
	float lastX = 0.5f;
	float lastY = 0.5f;
	float glPosX = 0.0f;
	float glPosY = 0.0f;

	int index;

	float threshold = 0.1f;

	while (!glfwWindowShouldClose(window))
	{
		processInput(window);
		glClear(GL_COLOR_BUFFER_BIT);

		glActiveTexture(GL_TEXTURE0);
		texture1.BindTexture();

		glActiveTexture(GL_TEXTURE1);
		texture2.BindTexture();

		shader.Use();

		double xPos, yPos;
		glfwGetCursorPos(window, &xPos, &yPos);

		glUniform4f(glGetUniformLocation(shader.GetID(), "mouseColor"), 
			xPos / WIDTH, yPos / HEIGHT, xPos / HEIGHT, 1.0f);

		normalizeData(xPos, &glPosX, WIDTH);
		normalizeData(yPos, &glPosY, HEIGHT);

		glPosY *= -1;

		if (!clicked)
		{
			FindClosestVertex(glPosX, glPosY,
				sizeof(vertices) / sizeof(float), vertices, threshold, &index);

			if (index != -1)
				glUniform2f(glGetUniformLocation(shader.GetID(), "selectedVertex"),
					vertices[index], vertices[index + 1]);
			else
				glUniform2f(glGetUniformLocation(shader.GetID(), "selectedVertex"),
					20.0f, 20.0f);
		}

		if (glfwGetMouseButton(window, 0) == GLFW_PRESS)
		{
			if (index != -1)
			{
				if (!clicked)
				{
					lastX = vertices[index];
					lastY = vertices[index + 1];

					factorX = glPosX - lastX;
					factorY = glPosY - lastY;
					clicked = true;
				}

				UpdateVertexPosition(vbo, glPosX - factorX, glPosY - factorY, index);
			}
		}
		else
		{
			if (clicked)
			{
				glGetBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);

				lastX = glPosX - factorX;
				lastY = glPosY - factorY;

				clicked = false;
			}
		}

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	vao.DeleteVAO();
	vbo.DeleteVBO();
	shader.Delete();

	glfwTerminate();
	return 0;
}

