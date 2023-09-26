#include "Shader.h"

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

Shader::Shader() {
	
}

void Shader::Create(std::string vertex_data, std::string fragment_data) {
	//Loading Shaders
	vertex_shader_id = LoadShader(GL_VERTEX_SHADER, vertex_data.c_str());
	fragment_shader_id = LoadShader(GL_FRAGMENT_SHADER, fragment_data.c_str());

	//Attaching Shaders to the program
	program_id = glCreateProgram();
	glAttachShader(program_id, vertex_shader_id);
	glAttachShader(program_id, fragment_shader_id);

	//Linking the shaders
	glLinkProgram(program_id);
	glValidateProgram(program_id);

	//Detaching it after it was linked
	glDetachShader(program_id, vertex_shader_id);
	glDetachShader(program_id, fragment_shader_id);
}

void Shader::CleanUp() {
	glDeleteShader(vertex_shader_id);
	glDeleteShader(fragment_shader_id);

	glDeleteProgram(program_id);
}

int Shader::LoadShader(int type, const char* data) {
	int shader = glCreateShader(type);
	glShaderSource(shader, 1, &data, nullptr);
	glCompileShader(shader);

	int status = 0;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);

	if (status == GL_FALSE) {
		std::cout << "Error compiling " << (type == GL_VERTEX_SHADER ? "vertex" : (type == GL_FRAGMENT_SHADER ? "fragment" : "unknown")) << " shader" << std::endl;
	}
	return shader;
}

void Shader::Start() {
	glUseProgram(program_id);
}
void Shader::Stop() {
	glUseProgram(0);
}
void Shader::BindAttribute(int location, const char* value) {
	glBindAttribLocation(program_id, location, value);
}
int Shader::GetUniformLocation(const char* value) {
	return glGetUniformLocation(program_id, value);
}
void Shader::Load4x4Matrix(int location, float* data) {
	glUniformMatrix4fv(location, 1, false, data);
}