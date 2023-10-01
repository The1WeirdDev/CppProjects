#include "PlayerShader.h"

#include "Utils/FileReader.h"

PlayerShader::PlayerShader() : Shader(){}

void PlayerShader::Load() {
	ShaderData data = FileReader::ReadFileAsShader("Res/Shaders/PlayerShader.shader");
	Create(data.vertex_data, data.fragment_data);

	projection_matrix_location = GetUniformLocation("projection_matrix");
	view_matrix_location = GetUniformLocation("view_matrix");
	transformation_matrix_location = GetUniformLocation("transformation_matrix");
}