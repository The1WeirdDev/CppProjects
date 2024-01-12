#include "FileHandler.h"

#include <fstream>
#include <string>
#include <sstream>

ShaderData FileHandler::ReadFileAsShaderData(const char* location) {
	std::ifstream file(location, std::ios::ate);
	int file_size = file.tellg();
	file.seekg(std::ios::beg);

	std::string str;
	if (!file) {
		printf("Could not read file %s\n", location);
		ShaderData data{ "", "" };
		return data;
	}
	
	ShaderData data;
	std::string line;
	std::string vertex_data = "", fragment_data = "";
	short mode = 0;
	while (std::getline(file, line)) {
		if (line.starts_with("#VERTEX")) {
			mode = 1;
		}else if (line.starts_with("#FRAGMENT")) {
			mode = 2;
		}
		else {
			switch (mode) {
			case 1:
				vertex_data += line + '\n';
				break;
			case 2:
				fragment_data += line + '\n';
				break;
			}
		}
	}
	file.close();

	data.vertex_data = vertex_data;
	data.fragment_data = fragment_data;
	return data;
}