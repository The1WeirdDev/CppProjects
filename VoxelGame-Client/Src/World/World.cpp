
#include "World.h"

void World::Init() {
    Chunk* chunk = new Chunk();
    chunk->Create();
	chunks.insert(std::pair<int, Chunk*>(0, chunk));

    //Maybe have chunks be stored with first 16 bits for x and next 16 for z
}
void World::Draw() {
    for (auto i = chunks.begin(); i
        != chunks.end(); i++) {
        i->second->Draw();
    }
}
void World::CleanUp() {
    for (auto i = chunks.begin(); i
        != chunks.end(); i++) {
        i->second->CleanUp();
    }
}