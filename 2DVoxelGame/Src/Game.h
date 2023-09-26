#pragma once

#include "Rendering/Window.h"
#include "Rendering/Shader.h"

#include "World/Chunk/Chunk.h"
#include "World/Chunk/ChunkMesh.h"

class Game{
public:
	static Chunk chunk;
	static Shader shader;
public:
	static void Init();
	static void CleanUp();
	static void Update();
	static void Draw();
};