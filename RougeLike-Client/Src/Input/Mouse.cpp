#include "Mouse.h"

#include <cstdio>

#include "Rendering/GameWindow.h"

double Mouse::mouse_x;
double Mouse::mouse_y;
double Mouse::last_mouse_x;
double Mouse::last_mouse_y;
double Mouse::mouse_delta_x;
double Mouse::mouse_delta_y;

void Mouse::Init() {
	glfwSetMouseButtonCallback(GameWindow::GetWindow(), Mouse::OnButtonClicked);
	glfwSetCursorPosCallback(GameWindow::GetWindow(), Mouse::OnCursorMoved);

	glfwGetCursorPos(GameWindow::GetWindow(), &mouse_x, &mouse_y);
	last_mouse_x = mouse_x;
	last_mouse_y = mouse_y;
	mouse_delta_x = 0;
	mouse_delta_y = 0;
}

void Mouse::Update() {
}
void Mouse::OnButtonClicked(GLFWwindow* window, int button, int action, int mods) {
	
}

void Mouse::OnCursorMoved(GLFWwindow* window, double xpos, double ypos) {
	mouse_x = xpos;
	mouse_y = ypos;
	mouse_delta_x = mouse_x - last_mouse_x;
	mouse_delta_y = mouse_y - last_mouse_y;
	last_mouse_x = xpos;
	last_mouse_y = ypos;
}
double Mouse::GetDeltaX() {
	return mouse_delta_x;
}
double Mouse::GetDeltaY(){
	return mouse_delta_y;
}