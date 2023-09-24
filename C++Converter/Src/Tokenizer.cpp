#include "Tokenizer.h"

#include <iostream>
#include <string>

Tokenizer::Tokenizer(const char* data) {
	code = data;
	file_size = strlen(data);

	for (character_index = 0; character_index < file_size; character_index++) {
		if (IsIdentifierCharacter(GetCurrentChar(), false)) {
			//Start of Identifier
			std::string identifier(1, GetCurrentChar());
			while (true) {
				character_index++;
				if (IsIdentifierCharacter(GetCurrentChar(), true)) {
					identifier += GetCurrentChar();
					continue;
				}

				break;
			}

			std::cout << identifier << std::endl;
		}
	}
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