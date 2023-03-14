#include "EBO.h"

#include <iostream>

EBO::EBO()
{
	glGenBuffers(1, &ID);
}

void EBO::AddBufferData(int sizeOfData, const void* data, GLenum usage)
{
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeOfData, data, usage);
}

void EBO::BindEBO()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

void EBO::UnbindEBO()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void EBO::DeleteEBO()
{
	glDeleteBuffers(1, &ID);
}