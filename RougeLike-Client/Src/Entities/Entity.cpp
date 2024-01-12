#include "Entity.h"

#include <glm/gtc/matrix_transform.hpp>

void Entity::GenerateMatrices() {

}
void Entity::GenerateTransformationMatrix() {
	transformation_matrix = glm::mat4x4();
	transformation_matrix = glm::translate(transformation_matrix, position);

	transformation_matrix = glm::rotate(transformation_matrix, glm::radians(rotation.x), glm::vec3(1, 0, 0));
	transformation_matrix = glm::rotate(transformation_matrix, glm::radians(rotation.y), glm::vec3(0, 1, 0));
	transformation_matrix = glm::rotate(transformation_matrix, glm::radians(rotation.z), glm::vec3(0, 0, 1));
}