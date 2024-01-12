#include "LocalPlayer.h"

#include "Input/Keyboard.h"
#include "Time/Time.h"

#include <glm/ext/matrix_transform.hpp>

void LocalPlayer::Update() {
	float delta_time = Time::GetDeltaTime();
	float rad = glm::radians(rotation.y);
	float right_angle = glm::radians(90.0f);
	if (Keyboard::IsKeyPressed(GLFW_KEY_W)) {
		position.x += sin(rad) * delta_time;
		position.z -= cos(rad) * delta_time;
	}
	if (Keyboard::IsKeyPressed(GLFW_KEY_S)) {
		position.x -= sin(rad) * delta_time;
		position.z += cos(rad) * delta_time;
	}
	if (Keyboard::IsKeyPressed(GLFW_KEY_A)) {
		position.x -= sin(rad + right_angle) * delta_time;
		position.z += cos(rad + right_angle) * delta_time;
	}
	if (Keyboard::IsKeyPressed(GLFW_KEY_D)) {
		position.x += sin(rad + right_angle) * delta_time;
		position.z -= cos(rad + right_angle) * delta_time;
	}

	GenerateMatrices();
}
void LocalPlayer::Draw() {

}

void LocalPlayer::GenerateMatrices() {
	view_matrix = glm::mat4(1.0);
	view_matrix = glm::translate(view_matrix, -position);
}

glm::mat4x4& LocalPlayer::GetViewMatrix() {
	return view_matrix;
}