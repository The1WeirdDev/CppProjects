#include "Keyboard.h"

#include <iostream>

void Keyboard::Init() {}
void Keyboard::CleanUp() {}
void Keyboard::Update() {}
void Keyboard::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (action == GLFW_PRESS) {
		printf("%d was pressed\n", key);
	}
	else if (action == GLFW_RELEASE) {
		printf("%d was released\n", key);
	}
}