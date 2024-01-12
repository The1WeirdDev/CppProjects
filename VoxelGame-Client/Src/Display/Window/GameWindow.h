#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class GameWindow{
public:
	static void Create();
	static void CleanUp();
	static void PreRender();

	static bool ShouldClose();

	static void OnWindowResizeCallback(GLFWwindow* window, int width, int height);
private:
	static int width;
	static int height;
	static GLFWwindow* window;
};