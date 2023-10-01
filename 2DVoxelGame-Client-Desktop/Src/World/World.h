#pragma once

#include <unordered_map>
#include <string>

#include "Rendering/Texture.h"
#include "Utils/Libs/Perlin.h"
#include "Utils/Vector.h"
#include "Chunk/Chunk.h"

class World{
public:
	//Chunk chunk;
	World();

	void Init();
	void CleanUp();
	
	void Update();
	void Draw();

	Chunk* GetChunk(int x, int y);
	void GenerateChunk(int x, int y);

	Texture texture;
	Perlin perlin;
private:
	std::unordered_map<std::string, Chunk*> chunks;
};