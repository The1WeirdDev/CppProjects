#include "Game.h"

#include <iostream>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Rendering/Texture.h"
#include "Utils/FileReader.h"
#include "Input/Keyboard.h"
#include "Input/Mouse.h"

#include "Utils/Vector.h"

World Game::world;
Shader Game::shader;
PlayerShader Game::player_shader;
Player Game::player;

int Game::view_matrix_location = 0;
int Game::transformation_matrix_location = 0;

void Game::Init() {
	Window::Init();

	ShaderData data = FileReader::ReadFileAsShader("Res/Shaders/DefaultShader.shader");
	shader.Create(data.vertex_data, data.fragment_data);
	shader.BindAttribute(0, "position");

	//Getting Locations
	int projection_matrix_location = shader.GetUniformLocation("projection_matrix");
	view_matrix_location = shader.GetUniformLocation("view_matrix");
	transformation_matrix_location = shader.GetUniformLocation("transformation_matrix");

	shader.Start();
	float aspect_ratio = 1920.0f / 1080.0f;
	float blocks = 34;
	glm::mat4x4 matrix = glm::ortho(-aspect_ratio * blocks, aspect_ratio * blocks, -1.0f * blocks, 1.0f * blocks, 0.01f, 1.0f);
	shader.Load4x4Matrix(projection_matrix_location, &matrix[0][0]);
	shader.Stop();

	player_shader.Load();
	player_shader.Start();
	player_shader.Load4x4Matrix(player_shader.projection_matrix_location, &matrix[0][0]);
	player_shader.Load4x4Matrix(player_shader.transformation_matrix_location, &glm::mat4x4(1.0)[0][0]);
	player_shader.Stop();

	world.Init();
	player.Init();

	Keyboard::Init();
	Mouse::Init();
}
void Game::CleanUp() {
	player.CleanUp();
	world.CleanUp();

	shader.CleanUp();

	Keyboard::CleanUp();
	Mouse::CleanUp();
	Texture::CleanUp();
	Window::CleanUp();
	glfwTerminate();
}
void Game::Update() {
	Window::Update();
	Keyboard::Update();
	Mouse::Update();

	world.Update();
	player.Update();
}
void Game::Draw() {
	world.Draw();
	player.Draw();
	Window::Draw();
}