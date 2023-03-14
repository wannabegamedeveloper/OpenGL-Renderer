#include "VAO.h"
#include "VBO.h"

VAO::VAO()
{
	glGenVertexArrays(1, &ID);
}

void VAO::LinkAttributesToShader(GLuint layout, GLint size, GLenum type, GLsizei stride, const void* pointer)
{
	glVertexAttribPointer(layout, size, type, GL_FALSE, stride, pointer);
	glEnableVertexAttribArray(layout);
}

void VAO::Bind()
{
	glBindVertexArray(ID);
}

void VAO::Unbind()
{
	glBindVertexArray(0);
}

void VAO::Delete()
{
	glDeleteVertexArrays(1, &ID);
}