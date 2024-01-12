#pragma once

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

class Entity{
public:

	virtual void Update();
	virtual void Draw();

	virtual void GenerateMatrices();

	void GenerateTransformationMatrix();
public:
	glm::vec3 position;
	glm::vec3 rotation;

	glm::mat4x4 transformation_matrix;
};