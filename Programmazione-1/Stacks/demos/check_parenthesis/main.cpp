#include <iostream>

void stack::print_data(const char& data) { std::cout << data; };

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " string" << std::endl;
		return 1;
	}

	stack::Stack stack;
	stack::init(stack);

	const char* string = argv[1];

	for (int i = 0; string[i] != '\0'; i++) {
		stack::push(string[i], stack);

		if (string[i] == ')') {
			stack::pop(stack);
			stack::pop(stack);
		}
	}

	stack::empty(stack) ? std::cout << "Balanced" << std::endl : std::cout << "Not balanced" << std::endl;

	stack::deinit(stack);
	return 0;
}
