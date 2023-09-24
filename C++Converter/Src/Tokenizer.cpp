#include "Tokenizer.h"

#include <iostream>
#include <string>
#include <fstream>

#define _CRT_SECURE_NO_WARNINGS

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

			char* p2 = new char[identifier.size()];
			strcpy_s(p2, identifier.size() * 2, identifier.c_str());
			AddToken(Type::Identifier, (void*)(p2));
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
			char* p2 = new char[string_data.size()];
			strcpy_s(p2, string_data.size() *2, string_data.c_str());
			AddToken(Type::String, (void*)(p2));
			continue;
		}
		case ' ':
			continue;
		case'\n':
			line++;
			continue;
		case'=': {
			continue;
		}
		default:
			printf("Unrecognized character (\"%c\") at (%d)\n", GetCurrentChar(), character_index);
			std::exit(-1);
		}
	}

	AddToken(Type::Int, (void*)5);
}

void Tokenizer::ReadTokens() {
	for (int i = 0; i < tokens.size(); i++) {
		Token* t = tokens[i];

		if (t->type == Type::Identifier) {
			char* test = ((char*)(tokens[i]->data));
			std::string identifier = "";
			for (int i = 0; i < strlen(test); i++) {
				identifier += test[i];
			}

			std::cout << "Identifier:" << identifier << "\n";
		}
		else if (t->type == Type::String) {
			char* test = ((char*)(tokens[i]->data));
			std::string string_data = "";
			for (int i = 0; i < strlen(test); i++) {
				string_data += test[i];
			}

			std::cout << "String:" << string_data << "\n";
		}
		else if (t->type == Type::Int) {
			int test = (int)tokens[i]->data;
			std::cout << "Int:" << test << std::endl;
		}

		delete tokens[i];
	}
}
void Tokenizer::AddToken(Type type, void* data) {
	tokens.push_back(new Token(type, data));
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