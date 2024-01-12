#pragma once

#include <array>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Keyboard{
public:
	static void Init();

	static void Update();
	static void OnKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

	static bool IsKeyPressed(int key);
private:
	static std::array<unsigned short, 400> keys;
};