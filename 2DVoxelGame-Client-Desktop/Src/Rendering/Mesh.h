#pragma once

class Mesh{
public:
	virtual void Draw();
	virtual void CleanUp();

	void AddAttribute(int attribute, int dimensions, int buffer_type, int data_type, void* data, int size);
protected:
	unsigned int vao_id = 0;
	unsigned int vbo_id = 0;

	unsigned int index_count = 0;
};