#include "Chunk.h"

Chunk::Chunk(int chunk_x, int chunk_y) {
	this->chunk_x = chunk_x;
	this->chunk_y = chunk_y;
}

void Chunk::CleanUp() {
	mesh.CleanUp();
}

void Chunk::CreateMesh() {
	unsigned int current_vertex = 0;

	for (unsigned int x = 0; x < 40; x++) {
		for (unsigned int y = 0; y < 40; y++) {
			vertices.push_back(x);
			vertices.push_back(y);
			vertices.push_back(x);
			vertices.push_back(y + 1);
			vertices.push_back(x + 1);
			vertices.push_back(y);
			vertices.push_back(x + 1);
			vertices.push_back(y + 1);

			indices.push_back(current_vertex);
			indices.push_back(current_vertex + 1);
			indices.push_back(current_vertex + 2);
			indices.push_back(current_vertex + 2);
			indices.push_back(current_vertex + 1);
			indices.push_back(current_vertex + 3);
			current_vertex += 4;
		}
	}

	mesh.CreateMesh(vertices.data(), indices.data(), vertices.size(), indices.size());
}
void Chunk::Draw() {
	mesh.Draw();
}