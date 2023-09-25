#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Window{
public:
	static void Init();
	static void CleanUp();
	static void Update();
	static void Draw();

	static void WindowSizeCallback(GLFWwindow* window, int width, int height);

	static bool ShouldUpdate();
	
	static constexpr GLFWwindow* GetWindow() { return window; }
private:
	static GLFWwindow* window;
};