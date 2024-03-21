#include <iostream>

void print_data(const char& data) { std::cout << data; }

void stack::print_data(const stack::data& a) { ::print_data(a); }

void queue::print_data(const queue::data& a) { ::print_data(a); }

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <word>" << std::endl;
		return 1;
	}

	const char* word = argv[1];

	stack::Stack stack;
	stack::init(stack);

	queue::Queue queue;
	queue::init(queue);

	for (int i = 0; word[i] != '\0' && i != 100; i++) {
		stack::push(word[i], stack);
	}

	for (int i = 0; word[i] != '\0' && i != 100; i++) {
		queue::enqueue(queue, word[i]);
	}

	for (int i = 0; word[i] != '\0' && i != 100; i++) {
		char endChar, startChar;
		queue::front(queue, startChar);
		stack::top(endChar, stack);

		if (endChar != startChar) {
			std::cout << "Not palindrome" << std::endl;
			return 1;
		}

		queue::dequeue(queue);
		stack::pop(stack);
	}

	std::cout << "Palindrome" << std::endl;

	queue::deinit(queue);
	stack::deinit(stack);

	return 0;
}
