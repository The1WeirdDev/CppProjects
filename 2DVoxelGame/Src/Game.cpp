#include "Game.h"

#include <iostream>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Utils/FileReader.h"
#include "Input/Keyboard.h"

Chunk Game::chunk;
Shader Game::shader;

void Game::Init() {
	Window::Init();

	ShaderData data = FileReader::ReadFileAsShader("Res/Shaders/DefaultShader.shader");
	shader.Create(data.vertex_data, data.fragment_data);

	int projection_matrix_location = shader.GetUniformLocation("projection_matrix");
	shader.Start();
	float aspect_ratio = 1920.0f / 1080.0f;
	glm::mat4x4 matrix = glm::ortho(-aspect_ratio * 35, aspect_ratio * 35, -1.0f * 35, 1.0f * 35, 0.01f, 1.0f);
	shader.Load4x4Matrix(projection_matrix_location, &matrix[0][0]);
	shader.Stop();

	chunk.CreateMesh();

	Keyboard::Init();
}
void Game::CleanUp() {
	chunk.CleanUp();

	shader.CleanUp();

	Keyboard::CleanUp();
	Window::CleanUp();
	glfwTerminate();
}
void Game::Update() {
	Window::Update();
	Keyboard::Update();

	shader.Start();
	chunk.Draw();
	shader.Stop();
}
void Game::Draw() {
	Window::Draw();
}