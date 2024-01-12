#include "Shader.h"

#include <iostream>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

Shader::Shader() {
	
}
Shader::Shader(ShaderData data) {
	Create(data);
}

void Shader::Create(ShaderData data) {
	vertex_shader_id = LoadShader(GL_VERTEX_SHADER, data.vertex_data.c_str());
	fragment_shader_id = LoadShader(GL_FRAGMENT_SHADER, data.fragment_data.c_str());
	program_id = glCreateProgram();

	glAttachShader(program_id, vertex_shader_id);
	glAttachShader(program_id, fragment_shader_id);

	glLinkProgram(program_id);
	glValidateProgram(program_id);

	glDetachShader(program_id, vertex_shader_id);
	glDetachShader(program_id, fragment_shader_id);
}
int Shader::LoadShader(int type, const char* source) {
	int shader = glCreateShader(type);

	glShaderSource(shader, 1, &source, nullptr);
	glCompileShader(shader);

	int status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);

	if (status == GL_FALSE) {
		std::cout << "Failed to load " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader" << std::endl;

		GLint maxLength = 0;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

		// The maxLength includes the NULL character
		std::vector<GLchar> errorLog(maxLength);
		glGetShaderInfoLog(shader, maxLength, &maxLength, &errorLog[0]);

		for (int i = 0; i < errorLog.size(); i++)
			std::cout << errorLog[i];

		// Provide the infolog in whatever manor you deem best.
		// Exit with failure.
		glDeleteShader(shader); // Don't leak the shader.
	}
	else {
		std::cout << "Loaded " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader" << std::endl;
	}

	return shader;
}
void Shader::Start() {
	glUseProgram(program_id);
}
void Shader::Stop() {
	glUseProgram(0);
}
void  Shader::CleanUp() {
	glDeleteShader(vertex_shader_id);
	glDeleteShader(fragment_shader_id);
	glDeleteProgram(program_id);
}

int Shader::GetUniformLocation(const char* name) {
	return glGetUniformLocation(program_id, name);
}
void Shader::BindAttribute(int index, const char* name) {
	glBindAttribLocation(program_id, index, name);
}
void Shader::LoadMatrix4x4(int location, glm::mat4x4& matrix) {
	glUniformMatrix4fv(location, 1, false, &matrix[0][0]);
}