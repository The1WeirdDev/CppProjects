#VERTEX
#version 400 core

in vec2 position;

void main()
{
    gl_Position = vec4(position, 0, 1.0);
}

#FRAGMENT
#version 400 core

out vec4 color;

void main()
{
    color = vec4(0.5, 0.5, 0.5, 1.0);

}