#version 330 core

out vec4 FragColor;

in vec4 UV;

uniform sampler2d mainTexture;

void main()
{
    FragColor = texture2D(mainTexture, UV);
}
