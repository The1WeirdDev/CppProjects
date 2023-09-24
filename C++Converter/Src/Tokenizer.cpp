#include "Tokenizer.h"

#include <iostream>
#include <string>
#include <fstream>

Tokenizer::Tokenizer(const char* location) {
	//Reading File
	std::ifstream f(location, std::ios::in);

	if (!f) {
		std::cout << "Unable to read file" << std::endl;
		std::exit(-1);
	}

	std::string line_of_code;
	while (std::getline(f, line_of_code)) {
		code += line_of_code += '\n';
	}
	file_size = code.size();
	//Tokenizing

	for (character_index = 0; character_index < file_size; character_index++) {
		char current_character = GetCurrentChar();
		if (IsIdentifierCharacter(current_character, false)) {
			//Start of Identifier
			std::string identifier(1, current_character);

			while (true) {
				if (IsIdentifierCharacter(GetNextChar(), true)) {
					identifier += GetNextChar();
					character_index++;
					continue;
				}

				break;
			}

			std::cout << identifier << std::endl;
			continue;
		}

		switch (current_character) {
		case '\"': {
			//Start of Identifier
			std::string string_data;
			character_index++;
			while (true) {
				if (GetCurrentChar() != '\"' && character_index < file_size) {
					string_data += GetCurrentChar();
					character_index++;
					continue;
				}
				if (character_index >= file_size) {
					printf("Reached end of file before end of string\nTerminating Compilation\n");
					std::exit(-1);
				}
				character_index++;
				break;
			}

			AddToken(Type::String, (void*)string_data.c_str());
			continue;
		}
		case ' ':
			continue;
		case'\n':
			line++;
			continue;
		default:
			printf("Unrecognized character (\"%c\") at (%d)\n", GetCurrentChar(), character_index);
			std::exit(-1);
		}
	}
}

void Tokenizer::AddToken(Type type, void* data) {
	std::cout << (const char*)data << std::endl;
}

bool Tokenizer::IsIdentifierCharacter(char c, bool status) {
	return isalpha(c) || (isdigit(c) && status);
}

char Tokenizer::GetPrevChar() {
	if (character_index <= 0)
		return 0;
	return code[character_index - 1];
}

char Tokenizer::GetCurrentChar() {
	return code[character_index];
}

char Tokenizer::GetNextChar() {
	if (character_index + 1 >= file_size)
		return 0;
	return code[character_index + 1];
}