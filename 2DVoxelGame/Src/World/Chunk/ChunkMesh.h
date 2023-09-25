#pragma once
class ChunkMesh {
public:
	ChunkMesh();

	void CreateMesh(float* vertices, int* indices);
	void Draw();
	void CleanUp();

protected:
	unsigned int vao_id = 0;
	unsigned int vbo_id = 0;
	unsigned int ebo_id = 0;
};