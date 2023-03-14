#include "Shader.h"

Shader::Shader(const char* fragmentPath)
{
	std::string vertexCode, fragmentCode;
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;

	vShaderFile.open("vert.shader");
	fShaderFile.open(fragmentPath);

	std::stringstream vShaderStream, fShaderStream;

	vShaderStream << vShaderFile.rdbuf();
	fShaderStream << fShaderFile.rdbuf();

	vShaderFile.close();
	fShaderFile.close();

	vertexCode = vShaderStream.str();
	fragmentCode = fShaderStream.str();

	const char* vShaderCode = vertexCode.c_str();
	const char* fShaderCode = fragmentCode.c_str();

	GLuint vertex, fragment;

	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);

	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, NULL);
	glCompileShader(fragment);

	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	glLinkProgram(ID);

	glDeleteShader(vertex);
	glDeleteShader(fragment);

	Use();
}

void Shader::Use()
{
	glUseProgram(ID);
}

void Shader::Delete()
{
	glDeleteProgram(ID);
}

void Shader::AttachTextureToSlot(Texture texture, GLint slot)
{
	Use();

	std::stringstream stream;
	stream << slot + 1;
	std::string numStr;
	stream >> numStr;
	std::string str = "tex" + numStr;
	const GLchar *textureName = str.c_str();

	glUniform1i(glGetUniformLocation(GetID(), textureName), slot);

	glActiveTexture(GL_TEXTURE0 + slot);
	texture.BindTexture();
}

GLuint Shader::GetID()
{
	return ID;
}
