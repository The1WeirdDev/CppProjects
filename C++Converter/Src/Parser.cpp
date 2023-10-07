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
		Token current_token = GetToken(token_index);

		switch (current_token.type) {
		case Type::Int: {
			Token placeholder = GetToken(token_index + 1);
			char op = (char)placeholder.data;
			if (placeholder.type != Type::Operator) {
				printf("Syntax Error\n");
				std::exit(-1);
			}
			placeholder = GetToken(token_index + 2);
			if (placeholder.type == Type::Int) {
				if (op == '+')
					std::cout << ((int)current_token.data) + ((int)placeholder.data);
				else if (op == '-')
					std::cout << ((int)current_token.data) - ((int)placeholder.data);
				else if (op == '*')
					std::cout << ((int)current_token.data) * ((int)placeholder.data);
				else if (op == '/')
					std::cout << ((int)current_token.data) / ((int)placeholder.data);
			}

			token_index += 2;
			break;
		}
		case Type::Keyword: {
			/*
			VAR IDENTIFIER = VALUE;
			print(data);
			*/
			std::string keyword = (const char*)current_token.data;
			if (keyword == "print") {
				Token next_1 = GetToken(token_index + 1);
				if (next_1.type != Type::Punctuator && (char)next_1.data != '(') {
					printf("Syntax Error. Expected Identifier\n");
					std::exit(-1);
				}
				
				Token next_2 = GetToken(token_index + 2);
				if (next_2.type == Identifier) {
					Token next_3 = GetToken(token_index + 3);
					if (next_3.type != Type::Punctuator && (char)next_3.data != ')') {
						printf("Syntax Error. Expected Identifier\n");
						std::exit(-1);
					}

					Token next_4 = GetToken(token_index + 4);
					if ((char)next_4.data != ';') {
						printf("Syntax Error. Expected ;\n");
						std::exit(-1);
					}

					VariableData data = variable_data[(const char*)next_2.data];
					std::cout << "Code Says: " << (data.type == Type::Int ? std::to_string((int)data.data).c_str() : ((const char*)data.data)) << std::endl;
					token_index += 4;
				}
				else {
					printf("Syntax Error. Expected Identifier\n");
					std::exit(-1);
				}
			}
			else if (keyword == "var") {
				Token next_1 = GetToken(token_index + 1);
				if (next_1.type != Type::Identifier) {
					printf("Syntax Error. Expected Identifier\n");
					std::exit(-1);
				}

				Token next_2 = GetToken(token_index + 2);
				if (next_2.type != Type::Operator) {
					printf("Syntax Error. Excepted operator\n");
					std::exit(-1);
				}

				Token next_3 = GetToken(token_index + 3);
				if (next_3.type != Type::Identifier && next_3.type != Type::Int) {
					printf("Syntax Error. Expected Identifier or Integer Value\n");
					std::exit(-1);
				}

				Token next_4 = GetToken(token_index + 4);
				if ((char)next_4.data != ';') {
					printf("Syntax Error. Expected ;\n");
					std::exit(-1);
				}

				const char* variable_name = (const char*)next_1.data;
				variable_data[variable_name] = VariableData(Type::Int, next_3.data);
				printf("Variable {%s} set to {%d}\n", variable_name, (int)next_3.data);
				token_index += 4;
			}
			else if (keyword == "if") {
				Token next_1 = GetToken(token_index + 1);
				if (next_1.type != Type::Identifier && next_1.type != Type::Int && next_1.type != Type::String) {
					printf("Syntax Error. Expected Identifier, Integer, or String\n");
					std::exit(-1);
				}

				Token next_2 = GetToken(token_index + 2);
			}
			break;
		}
		default:
			printf("Syntax Error %s\n", (char*)current_token.data);
			std::exit(-1);
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