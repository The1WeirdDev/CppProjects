#include "Shader.h"

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

Shader::Shader() {
	
}

void Shader::Create(std::string vertex_data, std::string fragment_data) {
	vertex_shader_id = LoadShader(GL_VERTEX_SHADER, vertex_data.c_str());
	fragment_shader_id = LoadShader(GL_FRAGMENT_SHADER, fragment_data.c_str());

	program_id = glCreateProgram();
	glAttachShader(program_id, vertex_shader_id);
	glAttachShader(program_id, fragment_shader_id);

	glLinkProgram(program_id);
	glValidateProgram(program_id);

	glDetachShader(program_id, vertex_shader_id);
	glDetachShader(program_id, fragment_shader_id);
}

int Shader::LoadShader(int type, const char* data) {
	int shader = glCreateShader(type);
	glShaderSource(shader, 1, &data, nullptr);
	glCompileShader(shader);

	int status = 0;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);

	if (status == GL_FALSE) {
		std::cout << "Error compiling shader" << std::endl;
	}
	return shader;
}

void Shader::Create() {

}
void Shader::Start() {
	glUseProgram(program_id);
}
void Shader::Stop() {
	glUseProgram(0);
}