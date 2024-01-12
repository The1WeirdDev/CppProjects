#include <iostream>

#ifdef _WIN32
#define _WIN_WINNT 0x0A00
#endif

#define ASIO_STANDALONE

#include <math.h>

#include <asio.hpp>
#include <asio/ts/buffer.hpp>
#include <asio/ts/internet.hpp>

#include "Rendering/GameWindow.h"
#include "Game/Game.h"

//#define DISABLE_PRINTF

#ifdef DISABLE_PRINTF
#define printf(fmt, ...) (0)
#endif

#ifdef TRACKING_HEAP_ALLOCATIONS
void* operator new (size_t size, char* file, int line, char* function)
{
	// add tracking code here...
	std::cout << "ALLOCATING " << size << std::endl;
	return malloc(size);
}
#endif

int main(int argc, char** argv) {
	printf("Creating Window\n");
	Game::Init();

	while (GameWindow::CanUpdateWindow()) {
		Game::Update();
		Game::Draw();
	}
	Game::CleanUp();
	return 0;
}