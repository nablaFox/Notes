#include <iostream>
#include <string.h>

// TODO: add function to check if uppercase as an utility
bool isUpperCase(char letter) { return letter >= 'A' && letter <= 'Z'; }

void helper(char* string, char* output, int index) {
	if (string[index] == '\0') {
		string[index] = '\0';
		return;
	}

	output[index] = ' ';
	if (isUpperCase(string[index])) {
		output[index] = string[index];
	}

	helper(string, output, index + 1);
}

const char* getUpLetters(char* string, int length) {
	char* output = new char[length];

	helper(string, output, 0);

	return output;
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " string" << std::endl;
		return 1;
	}

	const char* upperLetters = getUpLetters(argv[1], strlen(argv[1]));

	std::cout << upperLetters << std::endl;

	delete[] upperLetters;
	return 0;
}
