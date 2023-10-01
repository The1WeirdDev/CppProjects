#VERTEX
#version 400 core

in vec2 position;

in vec2 in_texture_coord;
out vec2 texture_coord;

uniform mat4 projection_matrix;
uniform mat4 view_matrix;
uniform mat4 transformation_matrix;

void main(){
    texture_coord = in_texture_coord;
    gl_Position = projection_matrix * view_matrix * transformation_matrix * vec4(position, -0.4, 1.0);
}

#FRAGMENT
#version 400 core

uniform sampler2D texture_pack;
in vec2 texture_coord;
out vec4 color;

void main()
{
    color = vec4(0.8, 0.8, 0.0, 1.0);
}