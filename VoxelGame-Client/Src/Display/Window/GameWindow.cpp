#include "GameWindow.h"

#include <cstdlib>
#include <cstdio>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

GLFWwindow* GameWindow::window = nullptr;
int GameWindow::width = 1280;
int GameWindow::height = 720;

void GameWindow::Create() {
	glfwWindowHint(GLFW_DOUBLEBUFFER, GL_FALSE);
	window = glfwCreateWindow(width, height, "Window", nullptr, nullptr);
	if (!window) {
		glfwDestroyWindow(window);
		glfwTerminate();
		std::exit(-1);
	}

	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK) {
		printf("Failed to initialize glew\n");
		std::exit(-1);
	}

	GLFWvidmode* video_mode = (GLFWvidmode*)glfwGetVideoMode(glfwGetPrimaryMonitor());
	glfwSetWindowPos(window, (video_mode->width - width) / 2, (video_mode->height - height) / 2);


	glfwSetWindowSizeCallback(window, GameWindow::OnWindowResizeCallback);

	glfwSwapInterval(0);
	glViewport(0, 0, width, height);

	glClearColor(0, 0.8, 1, 1);
}

void GameWindow::CleanUp() {
	glfwDestroyWindow(window);
}
void GameWindow::PreRender() {
	glFinish();
	glClear(GL_COLOR_BUFFER_BIT);
	//glfwSwapBuffers(window);
	glfwPollEvents();
}

bool GameWindow::ShouldClose() {
	return glfwWindowShouldClose(window);
}
void GameWindow::OnWindowResizeCallback(GLFWwindow* window, int width, int height) {
	GameWindow::width = width;
	GameWindow::height = height;
	glViewport(0, 0, width, height);
}