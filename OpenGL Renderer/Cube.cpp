#include "Cube.h"

Cube::Cube()
{
	GLfloat vertices[] =
	{
		-0.5f, -0.5f, -0.5f,	0.0f, 0.0f,		0.0f,  0.0f, -1.0f,
		 0.5f, -0.5f, -0.5f,	1.0f, 0.0f,		0.0f,  0.0f, -1.0f,
		 0.5f,  0.5f, -0.5f,	1.0f, 1.0f,		0.0f,  0.0f, -1.0f,
		 0.5f,  0.5f, -0.5f,	1.0f, 1.0f,		0.0f,  0.0f, -1.0f,
		-0.5f,  0.5f, -0.5f,	0.0f, 1.0f,		0.0f,  0.0f, -1.0f,
		-0.5f, -0.5f, -0.5f,	0.0f, 0.0f,		0.0f,  0.0f, -1.0f,

		-0.5f, -0.5f,  0.5f,	0.0f, 0.0f,		0.0f,  0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,	1.0f, 0.0f,		0.0f,  0.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,	1.0f, 1.0f,		0.0f,  0.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,	1.0f, 1.0f,		0.0f,  0.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,	0.0f, 1.0f,		0.0f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,	0.0f, 0.0f,		0.0f,  0.0f, 1.0f,

		-0.5f,  0.5f,  0.5f,	1.0f, 0.0f,		-1.0f,  0.0f,  0.0f,
		-0.5f,  0.5f, -0.5f,	1.0f, 1.0f,		-1.0f,  0.0f,  0.0f,
		-0.5f, -0.5f, -0.5f,	0.0f, 1.0f,		-1.0f,  0.0f,  0.0f,
		-0.5f, -0.5f, -0.5f,	0.0f, 1.0f,		-1.0f,  0.0f,  0.0f,
		-0.5f, -0.5f,  0.5f,	0.0f, 0.0f,		-1.0f,  0.0f,  0.0f,
		-0.5f,  0.5f,  0.5f,	1.0f, 0.0f,		-1.0f,  0.0f,  0.0f,

		 0.5f,  0.5f,  0.5f,	1.0f, 0.0f,		1.0f,  0.0f,  0.0f,
		 0.5f,  0.5f, -0.5f,	1.0f, 1.0f,		1.0f,  0.0f,  0.0f,
		 0.5f, -0.5f, -0.5f,	0.0f, 1.0f,		1.0f,  0.0f,  0.0f,
		 0.5f, -0.5f, -0.5f,	0.0f, 1.0f,		1.0f,  0.0f,  0.0f,
		 0.5f, -0.5f,  0.5f,	0.0f, 0.0f,		1.0f,  0.0f,  0.0f,
		 0.5f,  0.5f,  0.5f,	1.0f, 0.0f,		1.0f,  0.0f,  0.0f,
		
		-0.5f, -0.5f, -0.5f,	0.0f, 1.0f,		0.0f, -1.0f,  0.0f,
		 0.5f, -0.5f, -0.5f,	1.0f, 1.0f,		0.0f, -1.0f,  0.0f,
		 0.5f, -0.5f,  0.5f,	1.0f, 0.0f,		0.0f, -1.0f,  0.0f,
		 0.5f, -0.5f,  0.5f,	1.0f, 0.0f,		0.0f, -1.0f,  0.0f,
		-0.5f, -0.5f,  0.5f,	0.0f, 0.0f,		0.0f, -1.0f,  0.0f,
		-0.5f, -0.5f, -0.5f,	0.0f, 1.0f,		0.0f, -1.0f,  0.0f,

		-0.5f,  0.5f, -0.5f,	0.0f, 1.0f,		0.0f,  1.0f,  0.0f,
		 0.5f,  0.5f, -0.5f,	1.0f, 1.0f,		0.0f,  1.0f,  0.0f,
		 0.5f,  0.5f,  0.5f,	1.0f, 0.0f,		0.0f,  1.0f,  0.0f,
		 0.5f,  0.5f,  0.5f,	1.0f, 0.0f,		0.0f,  1.0f,  0.0f,
		-0.5f,  0.5f,  0.5f,	0.0f, 0.0f,		0.0f,  1.0f,  0.0f,
		-0.5f,  0.5f, -0.5f,	0.0f, 1.0f,		0.0f,  1.0f,  0.0f
	};

	vao.Bind();
	vbo.Bind();

	vbo.AddBufferData(sizeof(vertices), vertices, GL_STATIC_DRAW);

	vao.LinkAttributesToShader(0, 3, GL_FLOAT, 8 * sizeof(GL_FLOAT), (void*)0);
	vao.LinkAttributesToShader(1, 2, GL_FLOAT, 8 * sizeof(GL_FLOAT), 
		(void*)(3 * sizeof(float)));
	vao.LinkAttributesToShader(2, 3, GL_FLOAT, 8 * sizeof(GL_FLOAT),
		(void*)(5 * sizeof(float)));

	vbo.Unbind();
	vao.Unbind();
}

void Cube::draw(Shader shader, glm::vec2 tiling)
{
	shader.Use();

	GLint modelLoc1 = glGetUniformLocation(shader.GetID(), "defaultColor");
	glUniform3fv(modelLoc1, 1, glm::value_ptr(defaultColor));

	GLint loc = glGetUniformLocation(shader.GetID(), "tiling");
	glUniform2fv(loc, 1, glm::value_ptr(tiling));

	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, _position);
	model = glm::rotate(model, glm::radians(_angle), _axis);
	model = glm::scale(model, _scale);

	modelLoc = glGetUniformLocation(shader.GetID(), "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	vao.Bind();
	glDrawArrays(GL_TRIANGLES, 0, 36);
}

void Cube::SetPosition(glm::vec3 newPosition)
{
	_position = newPosition;
}

void Cube::SetRotation(float angle, glm::vec3 axis)
{
	_angle = angle;
	_axis = axis;
}

void Cube::SetScale(glm::vec3 newScale)
{
	_scale = newScale;
}

void Cube::SetColor(glm::vec3 newColor)
{
	defaultColor = newColor;
}

void Cube::clearData()
{
	vao.Delete();
	vbo.Delete();
}

float Cube::getPositionZ()
{
	return _position.z;
}