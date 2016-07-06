#include <iostream>
#include <fstream>
#include "lexer.h"

typedef uint32_t i32;

using namespace std;

// functions
vector<i32> compileToInstructions(strings s);
bool isInteger(string s);
bool isPrimimitive(string s);
i32 mapToNumber(string s); 

int main(int argc, char *argv[]) {
	// check for input errors
	if (argc != 2) {
		cout << "Usage: " << argv[0] << " <sasm-filename>" << endl;
		exit(1);
	}

	// read input file
	ifstream infile;
	infile.open(argv[1]);
	if (!infile.is_open()) {
		cout << "Error: could not open [" << argv[1] << "]" << endl;
		exit(1);
	}
	string line;
	string contents;
	while (getline(infile, line)) {
		contents += line + "\n";
	}
	infile.close();

	// parse file
	Lexer lexer;
	strings lexemes = lexer.lex(contents);

	// compile to binary
	vector<i32> instructions = compileToInstructions(lexemes);

	// write to binary file
	ofstream ofile;
	ofile.open("out.bin", ios::binary);
	for (i32 i = 0; i < instructions.size(); i++) {
		ofile.write(reinterpret_cast<char *>(&instructions[i]), sizeof(i32));
	}
	ofile.close();
	return 0;
}

vector<i32> compileToInstructions(strings s) {
	vector<i32> instructions;
	for (i32 i = 0; i < s.size(); i++) {
		if (isInteger(s[i])) {
			instructions.push_back(stoi(s[i]));
		} else {
			i32 instruction = mapToNumber(s[i]);
			if (instruction != -1) {
				instructions.push_back(instruction);
			} else {
				cout << "Error: Invalid instruction [" << s[i] << "]" << endl;
			}
		}
	}
	instructions.push_back(0x40000000); // always halt at the end
	return instructions;
}
bool isInteger(string s) {
	for (i32 i = 0; i < s.length(); i++) {
		if (!isdigit(s[i])) {
			return false;
		}
	}
	return true;
}
i32 mapToNumber(string s) {
	if (s == "+") {
		return 0x40000001;
	} else if (s == "-") {
		return 0x40000002;
	} else if (s == "*") {
		return 0x40000003;
	} else if (s == "/") {
		return 0x40000004;
	}
	return -1; // invalid instruction
}
