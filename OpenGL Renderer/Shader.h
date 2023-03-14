#pragma once

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "Texture.h"

class Shader 
{
private:
	GLuint ID;	

public:
	Shader(const char* fragmentPath);

	void Use();

	void Delete();

	GLuint GetID();

	void AttachTextureToSlot(Texture texture, GLint slot);
};