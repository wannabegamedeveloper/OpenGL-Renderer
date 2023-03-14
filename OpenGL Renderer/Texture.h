#pragma once
#include <glad/glad.h>

class Texture
{
private:
	GLuint ID;

	void GenerateTexture();

	void CreateTexture(GLint format);

public:
	unsigned char* data;
	int width, height, nrChannels;

	Texture(const char* texturePath, GLint format);

	void BindTexture();
};