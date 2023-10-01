#include "Mesh.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

void Mesh::Draw() {}
void Mesh::CleanUp(){}

void Mesh::AddAttribute(int attribute, int dimensions, int buffer_type, int data_type, void* data, int size) {
	glBufferData(buffer_type, size * sizeof(data_type), data, GL_STATIC_DRAW);
	glVertexAttribPointer(attribute, dimensions, data_type, false, 0, nullptr);
}