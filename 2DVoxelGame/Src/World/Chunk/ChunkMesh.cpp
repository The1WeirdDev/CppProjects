#include "ChunkMesh.h"

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

ChunkMesh::ChunkMesh() {
}

void ChunkMesh::CreateMesh(int* vertices, int* indices, int vertex_count, int index_count) {
	glGenVertexArrays(1, &vao_id);

	glBindVertexArray(vao_id);

	//Vertex Data
	glGenBuffers(1, &vbo_id);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_id);
	glBufferData(GL_ARRAY_BUFFER, vertex_count*sizeof(int), vertices, GL_STATIC_DRAW);//sizeof(vertices) / sizeof(float)
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_INT, GL_FALSE, 2 * sizeof(float), nullptr);

	//Triangle Data
	glGenBuffers(1, &ebo_id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, index_count*sizeof(unsigned int), indices, GL_STATIC_DRAW);

	this->index_count = index_count;
}
void ChunkMesh::Draw() {
	glBindVertexArray(vao_id);

	glEnableVertexAttribArray(0);
	glDrawElements(GL_TRIANGLES, index_count, GL_UNSIGNED_INT, 0);
	glDisableVertexAttribArray(0);

	glBindVertexArray(0);
}
void ChunkMesh::CleanUp() {

}