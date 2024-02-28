#include "caesar.hpp"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	if (argc != 4) {
		cout << "Usage: " << argv[0] << " input_file"
			 << " output_file"
			 << " e/d" << endl;
		return 1;
	}

	const char* inFile = argv[1];
	const char* outFile = argv[2];
	const char type = argv[3][0];
	int key;

	cout << "key: ";
	cin >> key;

	caesarize(inFile, outFile, key, type);

	return 0;
}
