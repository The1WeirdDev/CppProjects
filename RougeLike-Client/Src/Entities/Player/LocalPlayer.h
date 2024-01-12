#pragma once

#include "../Entity.h"

#include <glm/mat4x4.hpp>

class LocalPlayer : public Entity{
public:
	void Update();
	void Draw();

	void GenerateMatrices();

	glm::mat4x4& GetViewMatrix();
private:
	glm::mat4x4 view_matrix;
};