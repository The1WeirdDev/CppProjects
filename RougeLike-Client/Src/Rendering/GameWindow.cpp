#include "GameWindow.h"

#include <cstdlib>
#include <cstdio>


GLFWwindow* GameWindow::window = nullptr;
int GameWindow::window_width = 0;
int GameWindow::window_height = 0;

void GameWindow::CreateGameWindow(int width, int height, const char* title) {
	if (!glfwInit()) {
		printf("Unable to initialize glfw\n");
		std::exit(-1);
	}

	window_width = width;
	window_height = height;
	window = glfwCreateWindow(window_width, window_height, title, nullptr, nullptr);

	if (window == nullptr) {
		printf("Unable to create window.\n Size %d %d\n title %s\n", width, height, title);
		glfwTerminate();
		std::exit(-1);
	}

	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK) {
		printf("Unable to initialize GLEW\n");
		glfwTerminate();
		std::exit(-1);
	}
	
	glfwSetWindowSizeCallback(window, GameWindow::OnWindowResize);
	
	CenterWindow();

	glClearColor(0, 0.8, 1, 1);
	glViewport(0, 0, window_width, window_height);
}
void GameWindow::Update() {
	glfwSwapBuffers(window);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwPollEvents();
}
void GameWindow::CleanUp() {
	glfwDestroyWindow(window);
	window = nullptr;

	glfwTerminate();
}

bool GameWindow::CanUpdateWindow() {
	return !glfwWindowShouldClose(window);
}

void GameWindow::OnWindowResize(GLFWwindow* window, int width, int height) {
	window_width = width;
	window_height = height;
	glViewport(0, 0, window_width, window_height);
}

void GameWindow::CenterWindow() {
	GLFWvidmode* video_mode = (GLFWvidmode*)glfwGetVideoMode(glfwGetPrimaryMonitor());
	glfwSetWindowPos(window, (video_mode->width - GameWindow::window_width) / 2, (video_mode->height - GameWindow::window_height) / 2);
}


GLFWwindow* GameWindow::GetWindow() {
	return window;
}
int GameWindow::GetWidth() { return window_width; }
int GameWindow::GetHeight() { return window_height; }