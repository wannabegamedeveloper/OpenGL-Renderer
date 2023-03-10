#version 330 core

in vec2 texCoord;
in vec4 color;

out vec4 fragColor;

uniform sampler2D tex1;
uniform sampler2D tex2;
uniform vec4 mouseColor;

void main()
{
	fragColor = mix(texture(tex1, texCoord), 
		texture(tex2, texCoord), 0.2) * color;
}