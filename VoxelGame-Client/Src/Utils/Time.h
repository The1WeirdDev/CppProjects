#pragma once

class Time{
public:
	static void Init();
	static void Update();

	static double GetDeltaTime();
private:
	static double elapsed_time;
	static double last_elapsed_time;
	static double delta_time;
};