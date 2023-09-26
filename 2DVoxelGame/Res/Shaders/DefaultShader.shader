#VERTEX
#version 400 core

in vec2 position;

uniform mat4 projection_matrix;

void main()
{
    gl_Position = projection_matrix * vec4(position, -0.5, 1.0);
}

#FRAGMENT
#version 400 core

out vec4 color;

void main()
{
    color = vec4(0, 1, 0, 1.0);

}