#version 330 core

in vec2 texCoord;
in vec4 color;

out vec4 fragColor;

uniform sampler2D tex1;

void main()
{
	fragColor = texture(tex1, texCoord) * color;
}