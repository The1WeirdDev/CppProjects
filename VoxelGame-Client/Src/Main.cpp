#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <Display/Window/GameWindow.h>
#include <Display/Mesh/ChunkMesh.h>
#include <Display/Shader/Shader.h>
#include <World/World.h>
#include <Utils/Time.h>

int main(int argc, char** argv) {
	if (!glfwInit()) {
		printf("Unable to initialize glfw\n");
		return -1;
	}

	GameWindow::Create();

	//uint8_t* vertices = new uint8_t[12]{ 0,0,0, 0, 1, 0, 1, 0, 0, 1, 1, 0 };
	//uint32_t* indices = new uint32_t[6]{ 0, 1, 2, 2, 1, 3};
	World world;
	world.Init();

	const char* vert_source = "#version 400 core \n in vec3 pos; void main(){gl_Position = vec4(pos, 1.0);} ";
	const char* frag_source = "#version 400 core \n out vec4 color; void main(){color = vec4(0.5, 0, 1.0, 1.0);} ";
		
	Shader shader;
	shader.CreateShader(vert_source, frag_source);
	//ChunkMesh mesh;
	//mesh.Create(vertices, indices, 12, 6);

	Time::Init();

	while (!GameWindow::ShouldClose()) {
		GameWindow::PreRender();
		Time::Update();
		shader.Bind();
		world.Draw();
	}

	shader.CleanUp();
	world.CleanUp();
	//mesh.CleanUp();

	GameWindow::CleanUp();
	glfwTerminate();
}