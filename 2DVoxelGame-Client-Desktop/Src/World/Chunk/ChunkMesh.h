#pragma once

class ChunkMesh {
public:
	ChunkMesh();

	void CreateMesh(float* vertices, float* texture_coords, int* indices, int vertex_count, int texture_coords_size, int index_count);
	void Draw();
	void CleanUp();

protected:
	unsigned int vao_id = 0;
	unsigned int vbo_id = 0;
	unsigned int tbo_id = 0;
	unsigned int ebo_id = 0;

	int index_count = 0;
};