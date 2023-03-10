#include "VBO.h"
#include <iostream>

void VBO::CreateVBO()
{
	glGenBuffers(1, &ID);
}

void VBO::AddBufferData(int size, const void* data, GLenum usage)
{
	glBufferData(GL_ARRAY_BUFFER, size, data, usage);
}

void VBO::BindVBO()
{
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VBO::UnbindVBO()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::DeleteVBO()
{
	glDeleteBuffers(1, &ID);
}