#include "Chunk.h"

#include <cstdint>

void Chunk::Create() {
	uint8_t distance = 0;
	mesh.Create(new uint8_t[12]{ 0, 0, distance, 0, 1, distance, 1, 0, distance, 1, 1, distance }, new uint32_t[6]{ 0, 1, 2, 2, 1, 3 }, 12, 6);
}

void Chunk::Draw() {
	mesh.Draw();
}
void Chunk::CleanUp() {
	mesh.CleanUp();
}