#include "Time.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

double Time::elapsed_time = 0;
double Time::last_elapsed_time = 0;
double Time::delta_time = 0;

void Time::Init() {
	elapsed_time = glfwGetTime();
	last_elapsed_time = elapsed_time;
	delta_time = 0;
}
void Time::Update(){
	elapsed_time = glfwGetTime();
	delta_time = elapsed_time - last_elapsed_time;
	last_elapsed_time = elapsed_time;
}

double Time::GetDeltaTime() { return delta_time; }