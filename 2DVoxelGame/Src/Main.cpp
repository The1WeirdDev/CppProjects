#include <iostream>

#include "Game.h"
#include "Game.h"

int main(int argc, char** argv) {
	if (!glfwInit()) {
		printf("Unable to initialize glfw\n");
		return -1;
	}

	Game::Init();

	while (Window::ShouldUpdate()) {
		Game::Update();
		Game::Draw();
	}
	Game::CleanUp();
	return 0;
}