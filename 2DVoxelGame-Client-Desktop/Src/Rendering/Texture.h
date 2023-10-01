#pragma once

#include <vector>

#define STB_IMAGE_IMPLEMENTATION
class Texture{
public:
	Texture();
	void Load(const char* location);

	void Bind();

	static void CleanUp();
private:
	static std::vector<unsigned int> textures;
	unsigned int texture_id = 0;
	int width = 0, height = 0, nr_channels = 0;
};