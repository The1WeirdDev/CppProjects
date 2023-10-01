#pragma once

#include <glm/mat4x4.hpp>

#include "Utils/Vector.h"
#include "Rendering/Mesh/BasicMesh.h"

class Player{
public:
	Player();

	void Init();
	void CleanUp();
	void Update();
	void Draw();

	Vector2& GetPosition() { return position; }
	glm::mat4x4& GetViewMatrix() { return view_matrix; }
	glm::mat4x4& GetTransformationMatrix() { return transformation_matrix; }
private:
	Vector2 position;
	glm::mat4x4 view_matrix;
	glm::mat4x4 transformation_matrix;

	BasicMesh mesh;
};