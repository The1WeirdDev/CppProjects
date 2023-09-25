#pragma once

#include "Rendering/Window.h"

class Game{
public:
	static void Init();
	static void CleanUp();
	static void Update();
	static void Draw();
};