#pragma once

#include "Tokenizer.h"

#include <cmath>
#include <map>
#include <string>

class VariableData {
public:
	Type type;
	void* data;
	VariableData() {}
	VariableData(Type type, void* data) {
		this->type = type;
		this->data = data;
	}
};
class Parser{
public:
	Parser(std::vector<Token>* tokens);

	void Parse();

	std::map<std::string, VariableData> variable_data;

private:
	Token GetToken(uint16_t i);
	Token GetPrevToken();
	Token GetNextToken();
private:
	std::vector<Token>* tokens;

	uint16_t token_index = 0;
};