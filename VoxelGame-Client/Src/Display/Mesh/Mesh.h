#pragma once

/*
* Yeah the base mesh class is not going to have a default method for constructing its self
* Derived classes will do that for us
*/
class Mesh{
public:
	virtual void Draw();
	virtual void CleanUp();
protected:
	unsigned CreateVertexArrayObject();
	unsigned CreateBuffer();
protected:
	unsigned int vertex_count = 0;
	unsigned int vao_id = 0;

	unsigned int vbo_id = 0;
	unsigned int ebo_id = 0;
};