#include <fstream>
#include <iostream>
#include <time.h>

void tree::print_data(const int& data) { std::cout << data << " "; }
int tree::compare_data(const int& a, const int& b) { return a - b; }

int main(int argc, char* argv[]) {
	srand(time(NULL));
	tree::Tree tree;
	std::fstream file;

	file.open("demos/test/input.txt", std::ios::in);

	init(tree);

	while (!file.eof()) {
		int data;
		file >> data;
		insert(tree, data);
	}

	file.close();

	std::cout << "\n\n";
	tree::print(tree);

	deinit(tree);

	return 0;
}
