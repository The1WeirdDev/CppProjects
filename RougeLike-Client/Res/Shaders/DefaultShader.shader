#VERTEX
#version 400 core

uniform mat4x4 projection_matrix;
uniform mat4x4 view_matrix;
uniform mat4x4 transform_matrix;

in vec3 pos;

void main(){
	gl_Position = projection_matrix * view_matrix * transform_matrix * vec4(pos, 1.0);
}

#FRAGMENT
#version 400 core

out vec4 color;

void main(){
	color = vec4(0.5, 0.5, 0.5, 1.0);
}