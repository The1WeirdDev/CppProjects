#include <iostream>

#include "Tokenizer.h"
#include "Parser.h"

const char* code = "Iden balls\"im into balls\"\n";

int main(int argc, char** argv) {
	Tokenizer t("Res/Test.txt");
	t.ReadTokens();

	/*
	std::vector<Token>& tokens = t.tokens;
	for (int i = 0; i < tokens.size(); i++) {
		Token t = tokens[i];

		if (t.type == Type::Identifier) {
			char* test = ((char*)(tokens[i].data));
			std::string identifier = "";
			for (int i = 0; i < strlen(test); i++)
				identifier += test[i];

			std::cout << "Identifier: " << identifier << "\n";
		}
		else if (t.type == Type::Keyword) {
			char* test = ((char*)(tokens[i].data));
			std::string identifier = "";
			for (int i = 0; i < strlen(test); i++)
				identifier += test[i];
			std::cout << "Keyword: " << identifier << "\n";
		}
		else if (t.type == Type::Punctuator) {
			char test = ((char)(tokens[i].data));

			std::cout << "Punctuator: " << test << "\n";
		}
		else if (t.type == Type::String) {
			char* test = ((char*)(tokens[i].data));
			std::string string_data = "";
			for (int i = 0; i < strlen(test); i++) {
				string_data += test[i];
			}

			std::cout << "String: " << string_data << "\n";
		}
		else if (t.type == Type::Int) {
			int test = (int)tokens[i].data;
			std::cout << "Int: " << test << std::endl;
		}
	}
	*/

	Parser p(&t.tokens);
	p.Parse();
}