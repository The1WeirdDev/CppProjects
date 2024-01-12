#pragma once

#include <string>
#include <glm/mat4x4.hpp>

struct ShaderData {
	std::string vertex_data;
	std::string fragment_data;
};

class Shader {
public:
	Shader();
	Shader(ShaderData data);

	void Create(ShaderData data);
	int LoadShader(int type, const char* source);

	void Start();
	static void Stop();

	void CleanUp();

	int GetUniformLocation(const char* name);
	void BindAttribute(int index, const char* name);

	void LoadMatrix4x4(int location, glm::mat4x4& matrix);
private:
	int program_id = 0;
	int vertex_shader_id = 0;
	int fragment_shader_id = 0;
};