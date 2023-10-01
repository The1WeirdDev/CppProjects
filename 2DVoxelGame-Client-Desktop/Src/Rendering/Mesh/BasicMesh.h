#pragma once

#include "Rendering/Mesh.h"

class BasicMesh : public Mesh{
public:
	void CreateMesh(float* vertices, int* indices, int vertex_size, int index_size);
	void CleanUp()override;
	void Draw()override;

private:
	unsigned int ebo_id = 0;
};