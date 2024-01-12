#include "Game.h"

#include <iostream>

#include <math.h>

#include "Rendering/Mesh/Mesh.h"
#include "Rendering/GameWindow.h"
#include "Rendering/Shader/Shader.h"
#include "Networking/Client/TCPClient.h"
#include "Input/Mouse.h"
#include "Input/Keyboard.h"
#include "Time/Time.h"
#include "Utils/FileHandler.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

# define M_PI           3.14159265358979323846

Mesh Game::mesh;
Shader Game::shader;
int Game::projection_matrix_location;
int Game::view_matrix_location;
int Game::transform_matrix_location;

LocalPlayer Game::player;

void Game::Init() {
	GameWindow::CreateGameWindow(1280, 720, "RougeLike - Client");
	glfwSwapInterval(0);
	//TCPClient client;
	//client.Connect();

	printf("Creating Shaders\n");
	ShaderData f = FileHandler::ReadFileAsShaderData("Res/Shaders/DefaultShader.shader");
	shader.Create(f);

	glfwSetKeyCallback(GameWindow::GetWindow(), Keyboard::OnKeyCallback);

	float* vertices = new float[12] {0, 0, -1, 0, 1, -1, 1, 0, -1, 1, 1, -1};
	int* indices = new int[6] {0, 1, 2, 2, 1, 3};

	mesh.CreateMesh(vertices, indices, 12, 6);

	glm::mat4x4 projection_matrix(1.0);
	projection_matrix = glm::perspective(((float)M_PI / 180.0f) * 90.0f, (16.0f / 9.0f), 0.01f, 1000.0f);

	glm::mat4x4 view_matrix(1.0);
	view_matrix = glm::translate(view_matrix, glm::vec3(0, 0, 0));

	glm::mat4x4 transform_matrix(1.0);
	transform_matrix = glm::translate(transform_matrix, glm::vec3(-0.5, 0, -10));

	projection_matrix_location = shader.GetUniformLocation("projection_matrix");
	view_matrix_location = shader.GetUniformLocation("view_matrix");
	transform_matrix_location = shader.GetUniformLocation("transform_matrix");

	shader.Start();
	shader.LoadMatrix4x4(projection_matrix_location, projection_matrix);
	shader.LoadMatrix4x4(view_matrix_location, view_matrix);
	shader.LoadMatrix4x4(transform_matrix_location, transform_matrix);


	Keyboard::Init();
	Mouse::Init();
	Time::Init();
}
void Game::Update() {
	Time::Update();

	Keyboard::Update();
	Mouse::Update();
	std::cout << Mouse::GetDeltaX() << " " << Mouse::GetDeltaY() << std::endl;
	player.Update();
}
void Game::Draw() {
	player.Draw();
	shader.Start();
	shader.LoadMatrix4x4(view_matrix_location, player.GetViewMatrix());
	mesh.Draw();
	GameWindow::Update();
}
void Game::CleanUp() {
	mesh.CleanUp();
	shader.CleanUp();
	GameWindow::CleanUp();
	printf("Exiting Successfully\n");

}

void Game::LoadProjectionMatrix() {

}