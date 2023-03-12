#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

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

void UpdateVertexPosition(VBO vbo, GLfloat glPosX, GLfloat glPosY, int index, glm::mat4 translate)
{
	vbo.BindVBO();

	glm::vec4 vert = glm::vec4(glPosX, glPosY, 0.0f, 1.0f);
	vert = translate * vert;

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

void FindClosestVertex(float posX, float posY, int dataSize, float* vertices, float threshold, int* index, glm::mat4 translate)
{
	float distance = 0.0f;
	float leastDistance = 200.0f;
	int closestIndex = -1;

	for (int i = 0; i < dataSize; i += 5)
	{
		glm::vec4 vert = glm::vec4(vertices[i], vertices[i + 1], vertices[i + 2], 1.0f);
		vert = translate * vert;

		float distance = sqrt(pow(posX - vert.x, 2) + pow(posY - vert.y, 2) + pow(0.5f - vert.z, 2));

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
	//GLfloat vertices[] =
	//{
	//	//  positions			//  tex coords
	//	0.5f,  0.5f, 0.0f,		1.0f, 1.0f,
	//	0.5f, -0.5f, 0.0f,		1.0f, 0.0f,
	//   -0.5f, -0.5f, 0.0f,		0.0f, 0.0f,
	//   -0.5f,  0.5f, 0.0f,		0.0f, 1.0f
	//};

	//GLuint indices[] =
	//{
	//	0, 1, 3,
	//	1, 2, 3
	//};

	GLfloat vertices[] =
	{
		//  positions			//  tex coords
		-0.5f, -0.5f, -0.5f,	0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f,	1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,	1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,	1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,	0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,	0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,	0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,	1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,	1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,	1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,	0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,	0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f,	1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,	1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,	0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,	0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,	0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,	1.0f, 0.0f,

		 0.5f,  0.5f,  0.5f,	1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,	1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,	0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,	0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,	0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,	1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,	0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,	1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,	1.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,	1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,	0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,	0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,	0.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,	1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,	1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,	1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,	0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,	0.0f, 1.0f
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

	Texture texture1("grid.jpg");
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

	/*ebo.BindEBO();
	ebo.AddBufferData(sizeof(indices), indices, GL_STATIC_DRAW);*/

	vao.LinkAttributesToShader(0, 3, GL_FLOAT, 5 * sizeof(GL_FLOAT), (void*)0);
	vao.LinkAttributesToShader(1, 2, GL_FLOAT, 
		5 * sizeof(GL_FLOAT), (void*)(3 * sizeof(GL_FLOAT)));

	vbo.UnbindVBO();

	glEnable(GL_DEPTH_TEST);

	shader.Use();
	glUniform1i(glGetUniformLocation(shader.GetID(), "tex1"), 0);
	glUniform1i(glGetUniformLocation(shader.GetID(), "tex2"), 1);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	float glPosX = 0.0f;
	float glPosY = 0.0f;

	int index;

	float threshold = 0.1f;

	/*bool clicked = false;
	float factorX = 0.0f;
	float factorY = 0.0f;
	float lastX = 0.5f;
	float lastY = 0.5f;*/

	bool clicked = false;
	glm::vec2 oldPos = glm::vec2(0.0f);
	glm::vec2 newPos = glm::vec2(0.0f);
	glm::vec3 cross = glm::vec3(0.0f, 0.0f, 1.0f);

	double mousePosX, mousePosY;

	bool test = false;

	GLfloat angle = 0.0f;
	GLfloat oldAngle = 0.0f;
	glm::vec3 oldCross = glm::vec3(0.0f);

	float time = 10.0f;

	while (!glfwWindowShouldClose(window))
	{
		processInput(window);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glActiveTexture(GL_TEXTURE0);
		texture1.BindTexture();

		glActiveTexture(GL_TEXTURE1);
		texture2.BindTexture();

		shader.Use();

		double xPos, yPos;
		glfwGetCursorPos(window, &xPos, &yPos);

		normalizeData(xPos, &glPosX, WIDTH);
		normalizeData(yPos, &glPosY, HEIGHT);

		glPosY *= -1;

		glm::mat4 model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.5, 0.5, 0.5));

		model = glm::rotate(model, glm::radians(angle), cross);

		glm::mat4 view = glm::mat4(1.0f);
		view = glm::translate(view, glm::vec3(0.0f, -0.3f, -1.0f));

		glm::mat4 projection = glm::mat4(1.0f);
		projection = glm::perspective(glm::radians(90.0f), WIDTH / HEIGHT, 0.1f, 100.0f);

		/*if (!clicked)
		{
			FindClosestVertex(glPosX, glPosY,
				sizeof(vertices) / sizeof(float), vertices, threshold, &index, projection * view * model);

			if (index != -1)
				glUniform2f(glGetUniformLocation(shader.GetID(), "selectedVertex"),
					vertices[index], vertices[index + 1]);
			else
				glUniform2f(glGetUniformLocation(shader.GetID(), "selectedVertex"),
					20.0f, 20.0f);
		}*/

		/*if (glfwGetMouseButton(window, 0) == GLFW_PRESS)
		{
			if (index != -1)
			{
				if (!clicked)
				{
					lastX = vertices[index];
					lastY = vertices[index + 1];

					glm::vec4 mousePosition = glm::vec4(glPosX, glPosY, 0.0f, 1.0f);
					mousePosition = model * mousePosition;

					factorX = 2 * mousePosition.x - lastX;
					factorY = 2 * mousePosition.y - lastY;

					std::cout << glPosX << " " << glPosY << std::endl;

					clicked = true;
				}

				glm::vec4 mousePosition = glm::vec4(glPosX, glPosY, 0.0f, 1.0f);
				mousePosition = model * mousePosition;

				UpdateVertexPosition(vbo, 2 * mousePosition.x - factorX, 2 * mousePosition.y - factorY, index, model);
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
		{
		}*/

		if (glfwGetMouseButton(window, 0) == GLFW_PRESS)
		{
			if (!clicked)
			{
				glfwGetCursorPos(window, &mousePosX, &mousePosY);
				oldPos = glm::vec2(mousePosX, mousePosY);
				clicked = true;
			}

			if (clicked)
			{
				double newPosX, newPosY;
				glfwGetCursorPos(window, &newPosX, &newPosY);

				newPos = glm::vec2(newPosX, newPosY);

				if (glm::all(glm::notEqual(oldPos, newPos)))
				{
					glm::vec3 moveDirection = 
						glm::vec3(newPos.x - oldPos.x, newPos.y - oldPos.y, 0.0f);
					if (!test)
					{
						cross = glm::cross(moveDirection, glm::vec3(0.0f, 0.0f, 1.0f));
						cross = glm::normalize(cross);
						cross.y *= -1;
					}
					else
					{
						cross = glm::vec3(0.0f, 1.0f, 0.0f);
					}

					angle = glm::distance(newPos, oldPos) / 10.0f + oldAngle;
				}
			}
		}
		else if (glfwGetMouseButton(window, 0) != GLFW_PRESS)
		{
			if (clicked)
			{
				//test = true;
			}
			clicked = false;

			oldAngle = angle;
			oldPos = newPos;
			oldCross = cross;

			if (angle > 0.0f)
				angle -= 2.0f;
		}

		GLuint modelLoc = glGetUniformLocation(shader.GetID(), "model");
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

		GLuint viewLoc = glGetUniformLocation(shader.GetID(), "view");
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

		GLuint projectionLoc = glGetUniformLocation(shader.GetID(), "projection");
		glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

		glDrawArrays(GL_TRIANGLES, 0, 36);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	vao.DeleteVAO();
	vbo.DeleteVBO();
	shader.Delete();

	glfwTerminate();
	return 0;
}

