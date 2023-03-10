#pragma once
#include <glad/glad.h>

class VAO
{
private:
	GLuint ID;

public:
	void CreateVAO();

	void BindVAO();
	void UnbindVAO();
	
	void LinkAttributesToShader(GLuint layout, GLint size, GLenum type, GLsizei stride, const void *pointer);
	
	void DeleteVAO();
};
