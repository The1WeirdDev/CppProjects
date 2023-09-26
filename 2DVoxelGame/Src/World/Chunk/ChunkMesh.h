#pragma once
class ChunkMesh {
public:
	ChunkMesh();

	void CreateMesh(int* vertices, int* indices, int vertex_count, int index_count);
	void Draw();
	void CleanUp();

protected:
	unsigned int vao_id = 0;
	unsigned int vbo_id = 0;
	unsigned int ebo_id = 0;

	int index_count = 0;
};