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
	static int LoadShader(int type, const char* data);
	void Create();
	void Start();
	void Stop();
protected:
	int program_id = 0;
	int vertex_shader_id = 0;
	int fragment_shader_id = 0;
};