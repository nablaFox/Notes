#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void stack::print_data(const int& data) { cout << data; };

int main(int argc, char* argv[]) {
	stack::Stack stack;
	stack::init(stack);

	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " file" << std::endl;
	}

	fstream file;
	file.open(argv[1]);

	if (file.fail())
		std::cout << "Failed to open file" << std::endl;

	int res;
	while (file >> res) {
		stack::push(res, stack);
	}

	file.close();
	stack::deinit(stack);
}
