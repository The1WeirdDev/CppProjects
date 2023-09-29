#include "Vector.h"

Vector2::Vector2() {
	x = 0;
	y = 0;
}
Vector2::Vector2(float x, float y) {
	this->x = x;
	this->y = y;
}
Vector2 Vector2::operator+(Vector2 vector) {
	Vector2 result;
	result.x = this->x + vector.x;
	result.y = this->x + vector.y;
	return result;
}
Vector2 Vector2::operator-(Vector2 vector) {
	Vector2 result;
	result.x = this->x - vector.x;
	result.y = this->x - vector.y;
	return result;
}
Vector2 Vector2::operator*(Vector2 vector) {
	Vector2 result;
	result.x = this->x * vector.x;
	result.y = this->x * vector.y;
	return result;
}
Vector2 Vector2::operator/(Vector2 vector) {
	Vector2 result;
	result.x = this->x / vector.x;
	result.y = this->x / vector.y;
	return result;
}