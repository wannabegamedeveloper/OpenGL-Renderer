#version 330 core

in vec2 texCoord;
in vec4 color;

out vec4 fragColor;

uniform vec3 defaultColor;

void main()
{
	fragColor = vec4(defaultColor, 1.0);
}