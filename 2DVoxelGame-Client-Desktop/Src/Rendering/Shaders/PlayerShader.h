#pragma once

#include "../Shader.h"

class PlayerShader : public Shader {
public:
	PlayerShader();

	void Load() override;

	int projection_matrix_location = -1;
	int view_matrix_location = -1;
	int transformation_matrix_location = -1;
};