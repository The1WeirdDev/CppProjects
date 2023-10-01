#pragma once

class Mouse{
public:
	static void Init();
	static void CleanUp();
	static void Update();

public:
	static double GetMouseX() { return mouse_position_x; }
	static double GetMouseY() { return mouse_position_y; }
	static double GetLastMouseX() { return last_mouse_position_y; }
	static double GetLastMouseY() { return last_mouse_position_y; }
	static double GetDeltaX() { return mouse_delta_x; }
	static double GetDeltaY() { return mouse_delta_y; }
private:
	static double mouse_position_x;
	static double mouse_position_y;
	static double last_mouse_position_x;
	static double last_mouse_position_y;
	static double mouse_delta_x;
	static double mouse_delta_y;
};