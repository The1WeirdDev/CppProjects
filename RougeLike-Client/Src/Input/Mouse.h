#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
class Mouse{
public:
	static void Init();

	static void Update();
	
	static void OnButtonClicked(GLFWwindow* window, int button, int action, int mods);
	static void OnCursorMoved(GLFWwindow* window, double xpos, double ypos);

	static double GetDeltaX();
	static double GetDeltaY();
private:
	static double mouse_x;
	static double mouse_y;
	static double last_mouse_x;
	static double last_mouse_y;
	static double mouse_delta_x;
	static double mouse_delta_y;
};