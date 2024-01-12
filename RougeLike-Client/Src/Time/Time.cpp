#include "Time.h"

#include <GL/Glew.h>
#include <GLFW/glfw3.h>

float Time::current_time = 0;
float Time::last_time = 0;
float Time::delta_time = 0;

void Time::Init() {
	current_time = glfwGetTime();
	last_time = current_time;
	delta_time = 0;
}
void Time::Update() {
	current_time = glfwGetTime();
	delta_time = current_time - last_time;
	last_time = current_time;
}

float Time::GetDeltaTime() {
	return delta_time;
}