#pragma once

class Vector2 {
public:
	Vector2();
	Vector2(float x, float y);

	Vector2 operator+(Vector2 vector);
	Vector2 operator-(Vector2 vector);
	Vector2 operator*(Vector2 vector);
	Vector2 operator/(Vector2 vector);
public:
	float x = 0;
	float y = 0;
};