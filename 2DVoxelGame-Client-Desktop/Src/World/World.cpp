#include "World.h"

#include <iostream>

#include "Game.h"

World::World(){}

void World::Init(){
	chunks.clear();

	srand(time(0));
	perlin.SetData(2, 3.0f, 0.5f, rand() % 99999);

	texture.Load("Res/texture_pack.png");
	texture.Bind();
}
void World::CleanUp(){
	for (auto i = chunks.begin(); i != chunks.end(); i++) {
		i->second->CleanUp();
		delete i->second;
	}
}

void World::Update(){
	int px = floor(Game::player.GetPosition().x / 40.0f);
	int py = floor(Game::player.GetPosition().y / 40.0f);

	for (int x = px - 3; x < px + 3; x++) {
		for (int y = py - 2; y < py + 3; y++) {
			if (GetChunk(x, y) == nullptr)
				GenerateChunk(x, y);
		}
	}

	//chunk.GenerateBlockData();
	//chunk.CreateMesh();
}
void World::Draw(){

	Game::shader.Start();
	int px = floor(Game::player.GetPosition().x / 40.0f);
	int py = floor(Game::player.GetPosition().y / 40.0f);

	for (int x = px -3; x < px + 3; x++) {
		for (int y = py -2; y < py + 3; y++) {
			Chunk* chunk = GetChunk(x, y);
			if (chunk != nullptr) {
				chunk->Draw();
			}
		}
	}
	Game::shader.Stop();
}

Chunk* World::GetChunk(int x, int y) {
	std::unordered_map<std::string, Chunk*>::iterator pos = chunks.find(std::to_string(x) + "," + std::to_string(y));
	if (pos != chunks.end()) {
		return pos->second;
	}

	return nullptr;
}

void World::GenerateChunk(int x, int y) {
	Chunk* chunk = new Chunk(this, x, y);
	chunk->GenerateBlockData();
	chunk->CreateMesh();
	chunks.insert(std::pair<std::string, Chunk*>(std::to_string(x) + "," + std::to_string(y), chunk));
}