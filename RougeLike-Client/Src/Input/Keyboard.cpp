#include "Keyboard.h"

#include <cstdio>
std::array<unsigned short, 400> Keyboard::keys;

void Keyboard::Init() {
	keys.fill(0);
}

void Keyboard::Update() {
}

void Keyboard::OnKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key >= 0 && key < 400) {
		keys[key] = action;
	}
}

bool Keyboard::IsKeyPressed(int key) {
	return keys[key] != 0;
}