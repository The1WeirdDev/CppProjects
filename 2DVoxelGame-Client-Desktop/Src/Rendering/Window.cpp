#include "Window.h"

#include <iostream>

#include "Game.h";
#include "Input/Keyboard.h"

GLFWwindow* Window::window = nullptr;
void  Window::Init() {
	window = glfwCreateWindow(1280, 720, "2D Voxel Game", nullptr, nullptr);
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK) {
		glfwDestroyWindow(window);
		glfwTerminate();
		window = nullptr;
		std::exit(-1);
	}

	GLFWvidmode* video_mode = (GLFWvidmode*)glfwGetVideoMode(glfwGetPrimaryMonitor());
	glfwSetWindowPos(window, (video_mode->width - 1280) / 2, (video_mode->height - 720) / 2);

	//Set Callbacks
	glfwSetWindowSizeCallback(window, Window::WindowSizeCallback);
	glfwSetKeyCallback(window, Keyboard::KeyCallback);

	glClearColor(0.5, 0.5, 0.5, 1.0);
	glfwSetWindowAspectRatio(window, 16, 9);
}
void Window::CleanUp() {
	glfwDestroyWindow(window);
	window = nullptr;
}
void Window::Update() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void Window::Draw() {
	glfwSwapBuffers(window);
	glfwPollEvents();
}

void Window::WindowSizeCallback(GLFWwindow* window, int width, int height){
	glViewport(0, 0, width, height);
	Game::Update();
	Game::Draw();
}

bool Window::ShouldUpdate() {
	return !glfwWindowShouldClose(window);
}