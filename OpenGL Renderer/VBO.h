#pragma once
#include <glad/glad.h>

class VBO
{
private:
	GLuint ID;

public:
	void CreateVBO();

	void BindVBO();
	void UnbindVBO();

	void AddBufferData(int size, const void* data, GLenum usage);

	void DeleteVBO();
};