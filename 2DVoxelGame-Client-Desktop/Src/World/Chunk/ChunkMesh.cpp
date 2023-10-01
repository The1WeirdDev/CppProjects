#include "ChunkMesh.h"

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

ChunkMesh::ChunkMesh() {
}

void ChunkMesh::CreateMesh(float* vertices, float* texture_coords, int* indices, int vertex_count, int texture_coords_size, int index_count) {
	glGenVertexArrays(1, &vao_id);
	glGenBuffers(1, &vbo_id);
	glGenBuffers(1, &tbo_id);
	glGenBuffers(1, &ebo_id);

	glBindVertexArray(vao_id);

	//Vertices
	glBindBuffer(GL_ARRAY_BUFFER, vbo_id);
	glBufferData(GL_ARRAY_BUFFER, vertex_count*sizeof(float), vertices, GL_STATIC_DRAW);//sizeof(vertices) / sizeof(float)
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);

	//Texture Coordinates
	glBindBuffer(GL_ARRAY_BUFFER, tbo_id);
	glBufferData(GL_ARRAY_BUFFER, texture_coords_size * sizeof(float), texture_coords, GL_STATIC_DRAW);//sizeof(vertices) / sizeof(float)
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);


	//Triangle Data
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, index_count*sizeof(unsigned int), indices, GL_STATIC_DRAW);

	this->index_count = index_count;
}
void ChunkMesh::Draw() {
	glBindVertexArray(vao_id);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glDrawElements(GL_TRIANGLES, index_count, GL_UNSIGNED_INT, nullptr);
	//glDisableVertexAttribArray(0);

	//glBindVertexArray(0);
}
void ChunkMesh::CleanUp() {

}