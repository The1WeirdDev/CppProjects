#include "Player.h"

#include "Game.h"
#include "Input/Keyboard.h"

#include <glm/gtc/matrix_transform.hpp>

Player::Player(){}

void Player::Init(){
	float* vertices = new float[8] {
		0, 0,
			0, 1,
			1, 0,
			1, 1
	};

	int* indices = new int[6] {
		0, 1, 2,
			2, 1, 3
	};

	mesh.CreateMesh(vertices, indices, 8, 6);
}
void Player::CleanUp(){
	mesh.CleanUp();
}
void Player::Update(){
	if (Keyboard::IsKeyDown(GLFW_KEY_A))
		position.x -= 0.1f;
	if (Keyboard::IsKeyDown(GLFW_KEY_D))
		position.x += 0.1f;

	view_matrix = glm::mat4x4(1.0f);
	view_matrix = glm::translate(view_matrix, glm::vec3(-position.x, 0, 0));

	transformation_matrix = glm::mat4x4(1.0f);
	transformation_matrix = glm::translate(transformation_matrix, glm::vec3(position.x, 0, 0));
}
void Player::Draw(){
	Game::shader.Start();
	Game::shader.Load4x4Matrix(Game::view_matrix_location, &view_matrix[0][0]);
	Game::shader.Stop();

	Game::player_shader.Start();
	Game::player_shader.Load4x4Matrix(Game::player_shader.view_matrix_location, &view_matrix[0][0]);
	Game::player_shader.Load4x4Matrix(Game::player_shader.transformation_matrix_location, &transformation_matrix[0][0]);
	mesh.Draw();
	Game::player_shader.Stop();
}