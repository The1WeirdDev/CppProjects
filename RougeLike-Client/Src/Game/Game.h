#pragma once

#include <glm/mat4x4.hpp>

#include "Entities/Player/LocalPlayer.h"

class Shader;
class Mesh;
class Game{
public:
	static void Init();
	static void Update();
	static void Draw();
	static void CleanUp();

	static void LoadProjectionMatrix();
private:
	static Mesh mesh;
	static Shader shader;

	static int projection_matrix_location;
	static int view_matrix_location;
	static int transform_matrix_location;

	static glm::mat4x4 projection_matrix;

	static LocalPlayer player;
};