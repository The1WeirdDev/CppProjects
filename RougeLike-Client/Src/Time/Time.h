#pragma once

class Time{
public:
	static void Init();
	static void Update();

	static float GetDeltaTime();
private:
	static float current_time;
	static float last_time;
	static float delta_time;
};