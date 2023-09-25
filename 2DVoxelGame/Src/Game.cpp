#include "Game.h"

#include <iostream>
#include "Utils/FileReader.h"

ChunkMesh Game::mesh;
Shader Game::shader;

void Game::Init() {
	Window::Init();

	ShaderData data = FileReader::ReadFileAsShader("Res/Shaders/DefaultShader.shader");
	shader.Create(data.vertex_data, data.fragment_data);

	float* vertices = new float[8]{
		0, 0,
		1, 0,
		0, 1,
		1, 1
	};
	int* indices = new int[6] {
		0,1,2,
		2,1,3
	};
	mesh.CreateMesh(vertices, indices);
}
void Game::CleanUp() {
	mesh.CleanUp();
	Window::CleanUp();
	glfwTerminate();
}
void Game::Update() {
	Window::Update();

	shader.Start();
	mesh.Draw();
	shader.Stop();
}
void Game::Draw() {
	Window::Draw();
}