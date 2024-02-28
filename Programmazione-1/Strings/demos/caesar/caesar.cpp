#include "caesar.hpp"
#include "fstream"
#include <fstream>
#include <iostream>

void crypt(char* word, int key) {
	for (int i = 0; word[i] != '\0'; i++) {
		int encrypted = (int)word[i] + key;

		if (encrypted > (int)'z')
			encrypted = 'a' + encrypted - 'z' - 1;

		word[i] = (char)encrypted;
	}
}

void decrypt(char* word, int key) {
	for (int i = 0; word[i] != '\0'; i++) {
		int encrypted = (int)word[i] - key;

		if (encrypted < (int)'a')
			encrypted = 'z' + 'a' - encrypted + 1;

		word[i] = (char)encrypted;
	}
}

void caesarize(const char* inFile, const char* outFile, int key, const char type) {
	std::fstream input, output;

	input.open(inFile, std::ios::in);
	output.open(outFile, std::ios::out);

	if (input.fail()) {
		std::cout << "Failed to open " << inFile << std::endl;
		return;
	}

	char word[256];
	while (input >> word) {
		if (type == 'e')
			crypt(word, key);
		else if (type == 'd')
			decrypt(word, key);

		output << word << " ";
	}

	output.close();
	input.close();
}
