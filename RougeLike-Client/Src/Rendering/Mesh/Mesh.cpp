#include "Mesh.h"

#include <cstdio>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

void Mesh::CreateMesh(float* vertices, int* indices, unsigned int vertex_count, unsigned int indices_count) {
	//Creating Buffers
	glGenVertexArrays(1, &vao_id);
	glGenBuffers(1, &vbo_id);
	glGenBuffers(1, &ebo_id);

	glBindVertexArray(vao_id);

	//Creating Vertices
	glBindBuffer(GL_ARRAY_BUFFER, vbo_id);
	glBufferData(GL_ARRAY_BUFFER, vertex_count * sizeof(float), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(float) * 3, nullptr);

	//Creating Indices
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices_count * sizeof( int), indices, GL_STATIC_DRAW);

	this->vertex_count = vertex_count;
	glBindVertexArray(0);
}

void Mesh::Draw() {
	glBindVertexArray(vao_id);
	glEnableVertexAttribArray(0);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
}
void Mesh::CleanUp() {
	glDeleteBuffers(1, &ebo_id);
	glDeleteBuffers(1, &vbo_id);
	glDeleteVertexArrays(1, &vao_id);

	ebo_id = 0;
	vbo_id = 0;
	vao_id = 0;
}