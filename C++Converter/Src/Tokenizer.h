#pragma once

#include <iostream>
#include <vector>
#include <cmath>

enum Type {
	Identifier, //type (const char*)
	
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
	Tokenizer(const char* code);

	bool IsIdentifierCharacter(char c, bool status);

	std::vector<Token> tokens;
private:
	//File
	const char* code = nullptr;

	uint32_t file_size = 0;
private:
	//For character iteration
	uint32_t character_index = 0;

	char GetPrevChar();
	char GetCurrentChar();
	char GetNextChar();
};