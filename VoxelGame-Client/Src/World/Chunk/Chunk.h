#pragma once

#include <Display/Mesh/ChunkMesh.h>

class Chunk{
public:
	ChunkMesh mesh;

	void Create();
	void Draw();
	void CleanUp();
};