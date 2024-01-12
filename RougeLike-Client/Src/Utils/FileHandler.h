#pragma once

#include "Rendering/Shader/Shader.h"

class FileHandler {
public:
	static ShaderData ReadFileAsShaderData(const char* location);
};