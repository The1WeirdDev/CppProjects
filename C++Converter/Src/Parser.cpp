#include "Parser.h"

Parser::Parser(std::vector<Token>* tokens) {
	this->tokens = tokens;
}

/*
Valid Statements
----------------

INT + INT;
*/

void Parser::Parse() {
	for (token_index = 0; token_index < tokens->size(); token_index++) {
		Token t = GetToken(token_index);

		if (t.type == Type::Int) {
			Token placeholder = GetToken(token_index + 1);
			char op = (char)placeholder.data;
			if (placeholder.type != Type::Operator) {
				printf("Syntax Error\n");
				std::exit(-1);
			}
			placeholder = GetToken(token_index + 2);
			if (placeholder.type == Type::Int) {
				if(op == '+')
					std::cout << ((int)t.data) + ((int)placeholder.data);
				else if (op == '-')
					std::cout << ((int)t.data) - ((int)placeholder.data);
				else if (op == '*')
					std::cout << ((int)t.data) * ((int)placeholder.data);
				else if (op == '/')
					std::cout << ((int)t.data) / ((int)placeholder.data);
			}

			token_index+=2;
			continue;
		}
	}
}
Token Parser::GetToken(uint16_t i) {
	if (i < 0 || i >= tokens->size())
		return Token(Type::OOF, nullptr);
	return tokens->at(i);
}
Token Parser::GetPrevToken() {
	if (token_index <= 0)
		return Token(Type::OOF, nullptr);
	return tokens->at(token_index - 1);
}
Token Parser::GetNextToken() {
	if (token_index + 1 >= tokens->size())
		return Token(Type::OOF, nullptr);
	return tokens->at(token_index + 1);
}