#pragma once

#include <deque>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

struct KeyChange {
public:
	int key;
	short value;
};

class Keyboard{
public:
	static void Init();
	static void CleanUp();
	static void Update();

public:
	static bool IsKeyPressed(int key);
	static bool IsKeyDown(int key);

	static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

private:
	static std::vector<short> keys;
	static std::deque<KeyChange> key_changes;
};