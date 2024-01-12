#pragma once

#include <cstdint>

class Mesh{
public:
	void CreateMesh(float* vertices,  int* indices, unsigned int vertex_count, unsigned int indices_count);

	virtual void Draw();
	virtual void CleanUp();
private:
	unsigned int vertex_count = 0;

	unsigned int vao_id = 0;
	unsigned int vbo_id = 0;
	unsigned int ebo_id = 0;
};