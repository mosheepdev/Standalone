#version 330 core

out vec4 FragColor;

in vec4 UV;

uniform sampler2d mainTexture;

void main()
{
    vec4 color = texture2D(mainTexture, UV);
    FragColor = vec4(1.0, 1.0, 1.0, 0) - color;
    FragColor.w = color.w;
}
