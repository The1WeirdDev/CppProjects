#pragma once

#include <vector>
#include <array>
#include <cstdint>

#include "ChunkMesh.h"

#include <glm/mat4x4.hpp>
class World;

class Chunk{
public:
	Chunk(World* world, int chunk_x = 0, int chunk_y = 0);

	void CleanUp();
	void Draw();

	void GenerateBlockData();
	void CreateMesh();

	uint8_t GetBlockId(uint8_t x, uint8_t y);
	void SetBlockId(uint8_t x, uint8_t y, uint8_t id);

	static bool IsInsideChunk(uint8_t x, uint8_t y);

	void SetChunkPosition(int chunk_x, int chunk_y) { this->chunk_x = chunk_x; this->chunk_y = chunk_y; }
	int GetChunkX() { return chunk_x; }
	int GetChunkY() { return chunk_y; }

private:
	glm::mat4x4 matrix;
	ChunkMesh mesh;
	int chunk_x = 0;
	int chunk_y = 0;

private:
	World* world = nullptr;
	std::array<uint8_t, 40 * 40> block_data;

	std::vector<float> vertices;
	std::vector<float> texture_coords;
	std::vector<int> indices;
};