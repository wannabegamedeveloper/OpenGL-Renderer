#include "Camera.h"

void Camera::setCamera()
{
	glm::vec3 front;
	front.x = cos(glm::radians(-90.0f + cameraRot.x)) * cos(glm::radians(cameraRot.y));
	front.y = sin(glm::radians(cameraRot.y));
	front.z = sin(glm::radians(-90.0f + cameraRot.x)) * cos(glm::radians(cameraRot.y));
	cameraFront = glm::normalize(front);

	glClearColor(r, g, b, 1.0f);
}

void Camera::SetPosition(glm::vec3 newPosition)
{
	cameraPos = newPosition;
}

void Camera::SetRotation(glm::vec3 newRotation)
{
	cameraRot = newRotation;
}

void Camera::SetBackgroundColor(float r, float g, float b)
{
	this->r = r;
	this->g = g;
	this->b = b;
}

void Camera::AttachShader(float FOV, float WIDTH, float HEIGHT, float near, float far, Shader shader)
{
	glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

	glm::mat4 projection = glm::perspective(glm::radians(FOV), WIDTH / HEIGHT, near, far);

	GLuint viewLoc = glGetUniformLocation(shader.GetID(), "view");
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

	GLuint projLoc = glGetUniformLocation(shader.GetID(), "projection");
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
}

glm::vec3 Camera::GetForward()
{
	return cameraFront;
}
