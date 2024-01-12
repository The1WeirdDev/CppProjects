#pragma once

#include <map>
#include <vector>

#include "Chunk/Chunk.h"

class World{
public:
	std::map<int, Chunk*> chunks;
public:
	void Init();
	void Draw();
	void CleanUp();
};