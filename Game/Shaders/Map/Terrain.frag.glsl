#version 330 core

out vec4 FragColor;

in vec4 UV;

in float weight0;
in float weight1;
in float weight2;
in float weight3;
in float weight4;
in float weight5;
in float weight6;
in float weight7;

uniform sampler2d texture0;
uniform sampler2d texture1;
uniform sampler2d texture2;
uniform sampler2d texture3;
uniform sampler2d texture4;
uniform sampler2d texture5;
uniform sampler2d texture6;
uniform sampler2d texture7;

void main()
{
    vec3 c0 = texture2D(texture0, UV);
    vec3 c1 = texture2D(texture1, UV);
    vec3 c2 = texture2D(texture2, UV);
    vec3 c3 = texture2D(texture3, UV);
    vec3 c4 = texture2D(texture4, UV);
    vec3 c5 = texture2D(texture5, UV);
    vec3 c6 = texture2D(texture6, UV);
    vec3 c7 = texture2D(texture7, UV);

    vec3 color = vec3(0,0,0);
    color = lerp(color, c0, weight0);
    color = lerp(color, c1, weight1);
    color = lerp(color, c2, weight2);
    color = lerp(color, c3, weight3);
    color = lerp(color, c4, weight4);
    color = lerp(color, c5, weight5);
    color = lerp(color, c6, weight6);
    color = lerp(color, c7, weight7);

    FragColor = vec4(color, 0);
}
