#include "VAO.h"
#include "VBO.h"

void VAO::CreateVAO()
{
	glGenVertexArrays(1, &ID);
}

void VAO::LinkAttributesToShader(GLuint layout, GLint size, GLenum type, GLsizei stride, const void* pointer)
{
	glVertexAttribPointer(layout, size, type, GL_FALSE, stride, pointer);
	glEnableVertexAttribArray(layout);
}

void VAO::BindVAO()
{
	glBindVertexArray(ID);
}

void VAO::UnbindVAO()
{
	glBindVertexArray(0);
}

void VAO::DeleteVAO()
{
	glDeleteVertexArrays(1, &ID);
}