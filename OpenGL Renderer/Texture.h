#pragma once
#include <glad/glad.h>

class Texture
{
private:
	GLuint ID;

public:
	unsigned char* data;
	int width, height, nrChannels;

	Texture(const char* texturePath);

	void GenerateTexture();

	void BindTexture();

	void CreateTexture(GLint format);
};