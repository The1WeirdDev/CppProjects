#include "Shader.h"

#include <cstdlib>
#include <cstdio>

#include <Display/Window/GameWindow.h>

void Shader::CreateShader(const char* vertex_data, const char* fragment_data) {
	vertex_shader_id = CreateShader(GL_VERTEX_SHADER, vertex_data);
	fragment_shader_id = CreateShader(GL_FRAGMENT_SHADER, fragment_data);

	program_id = glCreateProgram();

	glAttachShader(program_id, vertex_shader_id);
	glAttachShader(program_id, fragment_shader_id);

	glLinkProgram(program_id);

	int status = 0;
	glGetProgramiv(program_id, GL_LINK_STATUS, &status);
	if (status == GL_FALSE) {
		printf("Failed linking shader\n");
		GameWindow::CleanUp();
		glfwTerminate();
		std::exit(-1);
	}

	glValidateProgram(program_id);
	glGetProgramiv(program_id, GL_VALIDATE_STATUS, &status);
	if (status == GL_FALSE) {
		printf("Failed validating shader\n");
		GameWindow::CleanUp();
		glfwTerminate();
		std::exit(-1);
	}

	glDetachShader(program_id, vertex_shader_id);
	glDetachShader(program_id, fragment_shader_id);
}
void Shader::Bind() {
	glUseProgram(program_id);
}
void Shader::UnBind() {
	glUseProgram(0);
}

void Shader::CleanUp() {
	glDeleteShader(vertex_shader_id);
	glDeleteShader(fragment_shader_id);
	glDeleteProgram(program_id);
}

int Shader::CreateShader(int shader_type, const char* shader_data) {
	int shader = glCreateShader(shader_type);

	glShaderSource(shader, 1, &shader_data, nullptr);
	glCompileShader(shader);

	int status = 0;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);

	if (status == GL_FALSE) {
		printf("Could not create shader\n");

		int max_length = 0;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &max_length);

		GLchar* data = new GLchar[max_length];
		printf("Size %d\n", max_length);
		glGetShaderInfoLog(shader, max_length, nullptr, &data[0]);
		for (uint32_t i = 0; i < max_length; i++)
			printf("%c", data[i]);

		glDeleteShader(shader);
		delete[] data;
		return -1;
	}
	return shader;
}
void Shader::LoadMatrix4x4(int location, glm::mat4x4& matrix) {
	glUniformMatrix4fv(location, 1, false, &matrix[0][0]);
}