#include "Mesh.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

void Mesh::Draw() {

}
void Mesh::CleanUp() {

}
unsigned int Mesh::CreateVertexArrayObject() {
	unsigned int vao;
	glCreateVertexArrays(1, &vao);
	return vao;
}
unsigned int Mesh::CreateBuffer() {
	unsigned int buffer = 0;
	glCreateBuffers(1, &buffer);
	return buffer;
}