#pragma once

#include "Rendering/Shader.h"

#include <string>
class FileReader{
public:
	static ShaderData ReadFileAsShader(const char* location);
};