#pragma once

#include "ChunkMesh.h"

#include <vector>

class Chunk{
public:
	Chunk(int chunk_x = 0, int chunk_y = 0);

	void CleanUp();
	void CreateMesh();
	void Draw();

	void SetChunkPosition(int chunk_x, int chunk_y) { this->chunk_x = chunk_x; this->chunk_y = chunk_y; }
	int GetChunkX() { return chunk_x; }
	int GetChunkY() { return chunk_y; }

private:
	ChunkMesh mesh;
	int chunk_x = 0;
	int chunk_y = 0;

	std::vector<int> vertices;
	std::vector<int> indices;
};