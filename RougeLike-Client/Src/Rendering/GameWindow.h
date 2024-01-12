#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class GameWindow{
public:
	static void CreateGameWindow(int width, int height, const char* title);
	static void Update();
	static void CleanUp();

	static bool CanUpdateWindow();

	static void OnWindowResize(GLFWwindow* window, int width, int height);

	static void CenterWindow();

	static GLFWwindow* GetWindow();

	static int GetWidth();
	static int GetHeight();
private:
	static GLFWwindow* window;
	static int window_width;
	static int window_height;
};