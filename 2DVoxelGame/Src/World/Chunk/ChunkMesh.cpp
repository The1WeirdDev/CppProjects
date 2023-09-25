#include "ChunkMesh.h"

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

ChunkMesh::ChunkMesh() {
}

void ChunkMesh::CreateMesh(float* vertices, int* indices) {
	glGenVertexArrays(1, &vao_id);
	glGenBuffers(1, &vbo_id);
	glGenBuffers(1, &ebo_id);

	//Vertex Data
	glBindBuffer(GL_ARRAY_BUFFER, vbo_id);
	glBufferData(GL_ARRAY_BUFFER, 8*sizeof(float), vertices, GL_STATIC_DRAW);//sizeof(vertices) / sizeof(float)
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, false, 0, 0);
	glDisableVertexAttribArray(0);

	//Triangle Data
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6*sizeof(int), indices, GL_STATIC_DRAW);
}
void ChunkMesh::Draw() {
	glBindVertexArray(vao_id);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_id);

	glEnableVertexAttribArray(0);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
	glDisableVertexAttribArray(0);

	glBindVertexArray(0);
}
void ChunkMesh::CleanUp() {

}