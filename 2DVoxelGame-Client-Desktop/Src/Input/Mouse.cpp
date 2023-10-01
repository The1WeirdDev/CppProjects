#include "Mouse.h"

#include "Rendering/Window.h"

double Mouse::mouse_position_x = 0;
double Mouse::mouse_position_y = 0;
double Mouse::last_mouse_position_x = 0;
double Mouse::last_mouse_position_y = 0;
double Mouse::mouse_delta_x = 0;
double Mouse::mouse_delta_y = 0;

void Mouse::Init() {
	mouse_delta_x = 0;
	mouse_delta_y = 0;
	glfwGetCursorPos(Window::GetWindow(), &mouse_position_x, &mouse_position_y);
}
void Mouse::CleanUp() {

}
void Mouse::Update() {
	glfwGetCursorPos(Window::GetWindow(), &mouse_position_x, &mouse_position_y);
	mouse_delta_x = mouse_position_x - last_mouse_position_x;
	mouse_delta_y = mouse_position_y - last_mouse_position_y;
	last_mouse_position_x = mouse_position_x;
	last_mouse_position_y = mouse_position_y;
}