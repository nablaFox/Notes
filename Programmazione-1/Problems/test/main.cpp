#include <iostream>

int main(int argc, char* argv[]) {
	list::Node* list;
	list::init(list);

	stack::Stack stack;
	stack::init(stack);

	queue::Queue queue;
	queue::init(queue);

	for (int i = 0; i < 10; ++i) {
		Custom data = {i, i};
		list::insert_order(list, data);
		stack::push(data, stack);
		queue::enqueue(queue, data);
	}

	std::cout << "List: " << std::endl;
	list::print(list);

	std::cout << "Stack: " << std::endl;
	stack::print(stack);

	std::cout << "Queue: " << std::endl;
	queue::print(queue);

	list::deinit(list);
	stack::deinit(stack);
	queue::deinit(queue);

	return 0;
}
