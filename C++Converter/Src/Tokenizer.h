#pragma once

#include <iostream>
#include <vector>
#include <cmath>

enum Type {
	Identifier, //type (const char*)
	String, //type (const char*)
	
};
class Token {
public:
	void** data;
	Token(void** data) {
		this->data = data;
	}
};

class Tokenizer {
public:
	Tokenizer(const char* location);

	void AddToken(Type type, void* data);

	bool IsIdentifierCharacter(char c, bool status);

	std::vector<Token> tokens;
private:
	//File
	std::string code;

	uint32_t file_size = 0;
	uint32_t line = 1;
private:
	//For character iteration
	uint32_t character_index = 0;

	char GetPrevChar();
	char GetCurrentChar();
	char GetNextChar();
};