#include "ChunkMesh.h"

#include <cstdio>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

void ChunkMesh::Create(uint8_t* vertices, uint32_t* indices, unsigned int vertices_length, unsigned int indices_length) {
	vao_id = CreateVertexArrayObject();
	glBindVertexArray(vao_id);

	vbo_id = CreateBuffer();
	glBindBuffer(GL_ARRAY_BUFFER, vbo_id);
	glBufferData(GL_ARRAY_BUFFER, vertices_length * sizeof(uint8_t), vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_UNSIGNED_BYTE, false, 3 * sizeof(uint8_t), nullptr);

	ebo_id = CreateBuffer();
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices_length * sizeof(uint32_t), indices, GL_STATIC_DRAW);

	vertex_count = indices_length;
}

void ChunkMesh::Draw() {
	glBindVertexArray(vao_id);
	glDrawElements(GL_TRIANGLES, vertex_count, GL_UNSIGNED_INT, nullptr);
}
void ChunkMesh::CleanUp() {
	glDeleteBuffers(1, &vbo_id);
	glDeleteBuffers(1, &ebo_id);
	glDeleteVertexArrays(1, &vao_id);

	vao_id = 0;
	vbo_id = 0;
	ebo_id = 0;
}