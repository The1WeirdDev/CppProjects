#include "FileReader.h"

#include "Game.h"
#include <iostream>
#include <fstream>

ShaderData FileReader::ReadFileAsShader(const char* location) {
	std::ifstream file(location);

	if (!file) {
		std::cout << "Unable to read file at " << location << "\nTerminating Program" << std::endl;
		Game::CleanUp();
		std::exit(-1);
	}
	//1 - Vertex | 2 - Fragment
	std::string current_line, vertex_data, fragment_data;
	short mode = -1;
	while (std::getline(file, current_line)) {
		if (current_line.starts_with("#VERTEX"))
			mode = 1;
		else if (current_line.starts_with("#FRAGMENT"))
			mode = 2;
		else {
			if (mode == 1)
				vertex_data += current_line += "\n";
			else if (mode == 2)
				fragment_data += current_line += "\n";
		}
	}
	file.close();

	ShaderData data;
	data.vertex_data = vertex_data;
	data.fragment_data = fragment_data;
	return data;
}