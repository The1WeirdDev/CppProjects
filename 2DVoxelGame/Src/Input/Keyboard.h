#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Keyboard{
public:
	static void Init();
	static void CleanUp();
	static void Update();

	static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
};