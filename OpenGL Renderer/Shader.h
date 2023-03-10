#pragma once

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader 
{
private:
	GLuint ID;	

public:
	Shader(const char* vertexPath, const char* fragmentPath);

	void Use();

	void Delete();

	GLuint GetID();
};