#include "VBO.h"
#include <iostream>

VBO::VBO()
{
	glGenBuffers(1, &ID);
}

void VBO::AddBufferData(int size, const void* data, GLenum usage)
{
	glBufferData(GL_ARRAY_BUFFER, size, data, usage);
}

void VBO::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VBO::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::Delete()
{
	glDeleteBuffers(1, &ID);
}