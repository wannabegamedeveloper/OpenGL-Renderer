#pragma once
#include <glad/glad.h>

class VAO
{
private:
	GLuint ID;

public:
	VAO();

	void Bind();
	void Unbind();
	
	void LinkAttributesToShader(GLuint layout, GLint size, GLenum type, GLsizei stride, const void *pointer);
	
	void Delete();
};
