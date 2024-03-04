#include <fstream>
#include <iostream>

using namespace std;

bool checkHalf(const char* word, int start, int end) {
	int length = 0;

	if (word[start] == '.' || word[end] == '.')
		return false;

	for (int i = start; i < end && word[i] != '\0'; i++) {
		const int w = (int)word[i];

		const bool isEmail =
			(w >= 'A' && w <= 'Z') || (w >= 'a' && w <= 'z') || (w >= '0' && w <= '9') || w == '_' || w == '.';

		if (!isEmail)
			return false;

		length++;
	}

	return length;
}

bool isEmail(const char* word, int maxLength) {
	int index = 0;
	for (int i = 0; word[i] != '\0'; i++) {
		if (word[i] == '@')
			index = i;
	}

	if (!index)
		return false;

	if (!checkHalf(word, 0, index - 1) || !checkHalf(word, index + 1, maxLength))
		return false;

	return true;
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		cout << "Usage: " << argv[0] << " <filename>" << endl;
		return 1;
	}

	fstream input;
	input.open(argv[1], ios::in);

	if (!input.is_open()) {
		cout << "Error: Could not open file " << argv[1] << endl;
		return 1;
	}

	char word[255];
	while (input >> word) {
		isEmail(word, 255) ? cout << word << " is an email" << endl : cout << word << " is not an email" << endl;
	}

	input.close();

	return 0;
}
