#include "Texture.h"

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "stb/stbimage.h"

std::vector<unsigned int> Texture::textures;

Texture::Texture() {}
void Texture::Load(const char* location) {
	glGenTextures(1, &texture_id);
	glBindTexture(GL_TEXTURE_2D, texture_id);

	glActiveTexture(GL_TEXTURE0);

	//Setting Texture Options
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, 7);
	unsigned char* data = stbi_load(location, &width, &height, &nr_channels, 4);

	if (data) {
		//stbi__vertical_flip(data, width, height, 3);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

		glGenerateMipmap(GL_TEXTURE_2D);
		textures.push_back(texture_id);
	}
	else {
		std::cout << "Failed to load image" << std::endl;
	}
	stbi_image_free(data);
}

void Texture::Bind() {
	glBindTexture(GL_TEXTURE0, texture_id);
}

void Texture::CleanUp() {
	for (int i = 0; i < textures.size(); i++) 
		glDeleteTextures(1, &textures[i]);


}