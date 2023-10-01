#pragma once

#include "Rendering/Window.h"
#include "Rendering/Shader.h"
#include "Rendering/Shaders/PlayerShader.h"

#include "World/World.h"
#include "World/Chunk/Chunk.h"
#include "World/Chunk/ChunkMesh.h"
#include "Entities/Player/Player.h"

class Game{
public:
	static World world;
	static Shader shader;
	static PlayerShader player_shader;
	static Player player;

	static int transformation_matrix_location;
	static int view_matrix_location;
public:
	static void Init();
	static void CleanUp();
	static void Update();
	static void Draw();
};