#include "Chunk.h"

#include <iostream>

#include <glm/gtc/matrix_transform.hpp>

#include "Game.h"
#include "World/World.h"

Chunk::Chunk(World* world, int chunk_x, int chunk_y) {
	this->world = world;
	this->chunk_x = chunk_x;
	this->chunk_y = chunk_y;

	matrix = glm::mat4x4(1.0);
	matrix = glm::translate(matrix, glm::vec3(chunk_x * 40, chunk_y * 40, 0));

	std::fill(block_data.begin(), block_data.end(), 0);
}

void Chunk::CleanUp() {
	mesh.CleanUp();
}

void Chunk::Draw() {
	Game::shader.Load4x4Matrix(Game::transformation_matrix_location, &matrix[0][0]);
	mesh.Draw();
}

void Chunk::GenerateBlockData() {
	int _x = (chunk_x * 40);
	int _y = (chunk_y * 40);

	for (int x = 0; x < 40; x++) {
		float px = (((x + _x) + 0.01f) / 20.0f);
		int height = (int)floor((world->perlin.Get(px, 0.025f) * 10.0f) + 2);

		for (int y = 0; y < 40; y++) {
			if (y + _y < height)
				SetBlockId(x, y, 2);
			else if (y + _y == height)
				SetBlockId(x, y, 1);
		}
	}
}
void Chunk::CreateMesh() {
	unsigned int current_vertex = 0;

	for (unsigned int x = 0; x < 40; x++) {
		for (unsigned int y = 0; y < 40; y++) {
			uint8_t id = GetBlockId(x, y);
			if (id == 0)
				continue;

			vertices.push_back(x);
			vertices.push_back(y);
			vertices.push_back(x);
			vertices.push_back(y + 1);
			vertices.push_back(x + 1);
			vertices.push_back(y);
			vertices.push_back(x + 1);
			vertices.push_back(y + 1);

			float size = (16.0 / 256.0);
			float x_pos = (float)(id - 1) * size;
			float y_pos = 0;
			float half_pixel = (0.025 / 256.0f);

			texture_coords.push_back(x_pos + size - half_pixel);
			texture_coords.push_back(y_pos + size);
			texture_coords.push_back(x_pos + size - half_pixel);
			texture_coords.push_back(y_pos);
			texture_coords.push_back(x_pos);
			texture_coords.push_back(y_pos + size - half_pixel);
			texture_coords.push_back(x_pos);
			texture_coords.push_back(y_pos);
			/*
			texture_coords.push_back(x_pos + size - half_pixel);
			texture_coords.push_back(size);
			texture_coords.push_back(x_pos + size - half_pixel);
			texture_coords.push_back(0);
			texture_coords.push_back(x_pos);
			texture_coords.push_back(size);
			texture_coords.push_back(x_pos);
			texture_coords.push_back(0);
			*/

			indices.push_back(current_vertex);
			indices.push_back(current_vertex + 1);
			indices.push_back(current_vertex + 2);
			indices.push_back(current_vertex + 2);
			indices.push_back(current_vertex + 1);
			indices.push_back(current_vertex + 3);
			current_vertex += 4;
		}
	}

	mesh.CreateMesh(vertices.data(), texture_coords.data(), indices.data(), vertices.size(), texture_coords.size(), indices.size());
}

uint8_t Chunk::GetBlockId(uint8_t x, uint8_t y) {
	if (IsInsideChunk(x, y))
		return block_data[(x * 40) + y];

	return 0;
}

void Chunk::SetBlockId(uint8_t x, uint8_t y, uint8_t id) {
	if (IsInsideChunk(x, y))
		block_data[(x * 40) + y] = id;
}


bool Chunk::IsInsideChunk(uint8_t x, uint8_t y) {
	return (x >= 0 && x < 40 && y >= 0 && y < 40);
}