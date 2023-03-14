#pragma once
#include <glad/glad.h>

class VBO
{
private:
	GLuint ID;

public:
	VBO();

	void Bind();
	void Unbind();

	void AddBufferData(int size, const void* data, GLenum usage);

	void Delete();
};