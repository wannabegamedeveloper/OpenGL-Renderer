#include "Texture.h"
#include <iostream>

#include "stb_image.h"

Texture::Texture(const char* texturePath, GLint format)
{
	stbi_set_flip_vertically_on_load(true);
	data = stbi_load(texturePath, &width, &height, &nrChannels, 0);
	if (!data)
		std::cout << "FAILED TO GENERATE TEXTURE \n" << stbi_failure_reason();

	GenerateTexture();
	BindTexture();
	CreateTexture(format);
}

void Texture::GenerateTexture()
{
	glGenTextures(1, &ID);
}

void Texture::BindTexture()
{
	glBindTexture(GL_TEXTURE_2D, ID);
}

void Texture::CreateTexture(GLint format)
{
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(data);
}
