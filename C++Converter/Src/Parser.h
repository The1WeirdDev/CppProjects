#pragma once

#include "Tokenizer.h"

#include <cmath>

class Parser{
public:
	Parser(std::vector<Token>* tokens);

	void Parse();

private:
	Token GetToken(uint16_t i);
	Token GetPrevToken();
	Token GetNextToken();
private:
	std::vector<Token>* tokens;

	uint16_t token_index = 0;
};