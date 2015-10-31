#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <vector>

typedef uint8_t byte;
typedef std::vector<std::string> strings;

enum State : byte {
	START,
	READCHAR,
	READBLOCK,
	SKIP,
	DUMP,
	COMMENT,
	END
}

class Lexer {
	bool my_issspace(char c);
	bool isspecial(char c);
	bool isgroup(char c);
	char end_char, beg_char;
	public:
	strings lex(std::string s);
};

#endif
