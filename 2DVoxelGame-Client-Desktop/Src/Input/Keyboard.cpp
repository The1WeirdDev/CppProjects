#include "Keyboard.h"

#include <iostream>

std::vector<short> Keyboard::keys;
std::deque<KeyChange> Keyboard::key_changes;

void Keyboard::Init() {
	keys.resize(400);
	std::fill(keys.begin(), keys.end(), 0);
}
void Keyboard::CleanUp() {

}
void Keyboard::Update() {
	//TODO : Stop being lazy and make more efficient way to do this
	for (int i = 0; i < keys.size(); i++) {
		if (keys[i] == 2)
			keys[i] = 1;
	}

	//Update new key changes
	for (int i = 0; i < key_changes.size(); i++) {
		KeyChange key_change = key_changes[i];
		keys[key_change.key] = key_change.value;
		key_changes.pop_front();
	}
}
bool Keyboard::IsKeyPressed(int key) {
	if (key >= 0 && key < keys.size())
		return keys[key] == 2;

	return false;
}
bool Keyboard::IsKeyDown(int key) {
	if (key >= 0 && key < keys.size())
		return keys[key] != 0;

	return false;
}
void Keyboard::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (action == GLFW_PRESS) {
		KeyChange change;
		change.key = key;
		change.value = 2;
		key_changes.push_back(change);
		//printf("%d was pressed\n", key);
	}
	else if (action == GLFW_RELEASE) {
		KeyChange change;
		change.key = key;
		change.value = 0;
		key_changes.push_back(change);
		//printf("%d was released\n", key);
	}
}