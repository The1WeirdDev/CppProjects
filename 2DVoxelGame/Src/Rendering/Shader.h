#pragma once

#include <string>

struct ShaderData {
public:
	std::string vertex_data;
	std::string fragment_data;
};
class Shader{
public:
	Shader();

	void Create(std::string vertex_data, std::string fragment_data);
	void CleanUp();

	void Start();
	void Stop();
public:
	void BindAttribute(int location, const char* value);
	int GetUniformLocation(const char* value);
public:
	void Load4x4Matrix(int location, float* data);
public:
	static int LoadShader(int type, const char* data);
protected:
	int program_id = 0;
	int vertex_shader_id = 0;
	int fragment_shader_id = 0;
};