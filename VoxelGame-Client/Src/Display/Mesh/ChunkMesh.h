#pragma once

#include <cstdint>

#include "Mesh.h"

class ChunkMesh : public Mesh{
public:
	void Create(uint8_t* vertices, uint32_t* indices, unsigned int vertices_length, unsigned int indices_length);

	void Draw();
	void CleanUp();
};