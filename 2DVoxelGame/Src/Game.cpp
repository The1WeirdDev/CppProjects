#include "Game.h"

void Game::Init() {
	Window::Init();
}
void Game::CleanUp() {
	Window::CleanUp();
	glfwTerminate();
}
void Game::Update() {
	Window::Update();
}
void Game::Draw() {
	Window::Draw();
}