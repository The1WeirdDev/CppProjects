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
			std::string identifier(1, current_character);

			while (true) {
				if (IsIdentifierCharacter(GetNextChar(), true)) {
					identifier += GetNextChar();
					character_index++;
					continue;
				}

				break;
			}

			//Potential Memory Leak
			char* p2 = new char[identifier.size()];
			strcpy_s(p2, identifier.size() * 2, identifier.c_str());
			AddToken(CheckIfKeyword(identifier.c_str()), (void*)(p2));
			continue;
		}

		if (isdigit(current_character)) {
			std::string number_string(1, current_character);
			while (true) {
				if (isdigit(GetNextChar())) {
					number_string += GetNextChar();
					character_index++;
					continue;
				}

				break;
			}
			int number = std::stoi(number_string);
			AddToken(Type::Int, (void*)(number));
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
			//Potential Memory Leak
			char* p2 = new char[string_data.size()];
			strcpy_s(p2, string_data.size() *2, string_data.c_str());
			AddToken(Type::String, (void*)(p2));
			break;
		}
		case ' ':
			break;
		case'\n':
			line++;
			break;
		case'\t':
			break;
		case '+':
			AddToken(Type::Operator, (void*)'+');
			break;
		case '-':
			AddToken(Type::Operator, (void*)'-');
			break;
		case'(':
			AddToken(Type::Punctuator, (void*)'(');
			break;							  	
		case')':							  	
			AddToken(Type::Punctuator, (void*)')');
			break;							  	
		case'{':							  	
			AddToken(Type::Punctuator, (void*)'{');
			break;							  	
		case'}':							  	
			AddToken(Type::Punctuator, (void*)'}');
			break;							  	
		case'=':							  	
			AddToken(Type::Operator, (void*)'=');
			break;							  	
		case';':							  	
			AddToken(Type::Punctuator, (void*)';');
			break;
		default:
			printf("Unrecognized character (\"%c\") at (%d)\n", GetCurrentChar(), character_index);
			std::exit(-1);
		}
	}
}

Type Tokenizer::CheckIfKeyword(std::string data) {
	if (data == "print" || data == "void" || data == "var") {
		return Type::Keyword;
	}
	return Type::Identifier;
}

void Tokenizer::ReadTokens() {
	/*
	for (int i = 0; i < tokens.size(); i++) {
		Token t = tokens[i];

		if (t.type == Type::Identifier) {
			char* test = ((char*)(tokens[i].data));
			std::string identifier = "";
			for (int i = 0; i < strlen(test); i++)
				identifier += test[i];

			std::cout << "Identifier:" << identifier << "\n";
		}
		else if (t.type == Type::Keyword) {
			char* test = ((char*)(tokens[i].data));
			std::string identifier = "";
			for (int i = 0; i < strlen(test); i++)
				identifier += test[i];

			std::cout << "Keyword:" << identifier << "\n";
		}
		else if (t.type == Type::Punctuator) {
			char test = ((char)(tokens[i].data));

			std::cout << "Punctuator:" << test << "\n";
		}
		else if (t.type == Type::String) {
			char* test = ((char*)(tokens[i].data));
			std::string string_data = "";
			for (int i = 0; i < strlen(test); i++) {
				string_data += test[i];
			}

			std::cout << "String:" << string_data << "\n";
		}
		else if (t.type == Type::Int) {
			int test = (int)tokens[i].data;
			std::cout << "Int:" << test << std::endl;
		}
	}
	*/
}
void Tokenizer::AddToken(Type type, void* data) {
	tokens.push_back(Token(type, data));
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