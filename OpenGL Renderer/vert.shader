#version 330 core

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec2 aTexCoord;

out vec2 texCoord;
out vec4 color;

uniform vec2 selectedVertex;

void main()
{
	gl_Position = vec4(aPos, 1.0);
	texCoord = aTexCoord;

	if (aPos.xy == selectedVertex)
		color = vec4(0.1f, 0.1f, 0.1f, 1.0f);
	else
		color = vec4(1.0f);
}