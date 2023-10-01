#VERTEX
#version 400 core

in vec2 position;

in vec2 in_texture_coord;
out vec2 texture_coord;

void main(){
    texture_coord = in_texture_coord;
    gl_Position = vec4(position, -0.5, 1.0);
}

#FRAGMENT
#version 400 core

uniform sampler2D texture_pack;
in vec2 texture_coord;
out vec4 color;

void main()
{
    color = texture(texture_pack, texture_coord);
    if(color.a==0.0) discard;
}