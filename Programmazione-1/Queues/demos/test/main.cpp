#include <iostream>

void queue::print_data(const int& data) { std::cout << data; };

int main(int argc, char* argv[]) {
	queue::Queue queue;

	init(queue);

	std::cout << "Initial: \n";
	for (int i = 0; i < 10; i++)
		enqueue(queue, i);

	print(queue);
	dequeue(queue);
	std::cout << "After dequeue: \n";
	print(queue);

	deinit(queue);
	return 0;
}
