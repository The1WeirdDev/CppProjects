#pragma once

#include <glm/mat4x4.hpp>

class Shader{
public:
	void CreateShader(const char* vertex_data, const char* fragment_data);

	void Bind();
	static void UnBind();
	void CleanUp();

	static int CreateShader(int shader_type, const char* shader_data);
	
	static void LoadMatrix4x4(int location, glm::mat4x4& matrix);
protected:
	int program_id = 0;
	int vertex_shader_id = 0;
	int fragment_shader_id = 0;
};