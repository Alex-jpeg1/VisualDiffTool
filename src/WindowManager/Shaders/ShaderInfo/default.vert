#version 330 core
layout (location = 0) in vec2 aPos;

uniform mat4 Projection;

void main()
{
   gl_Position = Projection * vec4(aPos, 0, 1.0);

}