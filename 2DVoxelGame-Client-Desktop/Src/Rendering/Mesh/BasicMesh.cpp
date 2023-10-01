#include "BasicMesh.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

void BasicMesh::CreateMesh(float* vertices, int* indices, int vertex_size, int index_size) {
	//Generating vertex object and buffers
	glGenVertexArrays(1, &vao_id);
	glGenBuffers(1, &vbo_id);
	glGenBuffers(1, &ebo_id);

	glBindVertexArray(vao_id);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_id);
	AddAttribute(0, 2, GL_ARRAY_BUFFER, GL_FLOAT, vertices, vertex_size);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, index_size * sizeof(unsigned int), indices, GL_STATIC_DRAW);

	glBindVertexArray(0);

	index_count = index_size;
}
void BasicMesh::CleanUp(){
	glBindVertexArray(0);
	glDeleteBuffers(1, &ebo_id);
	glDeleteBuffers(1, &vbo_id);
	glDeleteVertexArrays(1, &vao_id);
}
void BasicMesh::Draw(){
	glBindVertexArray(vao_id);
	
	glEnableVertexAttribArray(0);
	glDrawElements(GL_TRIANGLES, index_count, GL_UNSIGNED_INT, nullptr);
	glDisableVertexAttribArray(0);

	glBindVertexArray(0);
}