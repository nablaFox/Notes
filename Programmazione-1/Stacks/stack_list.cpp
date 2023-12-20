#include <iostream>
#include "stack_list.hpp"

static bool empty(const stack::Stack& stack) { return stack == nullptr; }

static int length(const stack::Stack& stack) {
	int i = 0;
	stack::Node* curr = stack;

	while (!empty(curr))
		curr = curr->next, i++;

	return i;
}

namespace stack {

void init(Stack& stack) { stack = nullptr; }

void deinit(Stack& stack) {
	while (!empty(stack))
		pop(stack);
}

void print(const Stack& stack) {
	Node* curr = stack;
	int i = length(stack);

	for (; !empty(curr); curr = curr->next, i--) {
		std::cout << "Element: " << i << ": ";
		print_data(curr->c_data);
		std::cout << std::endl;
	}
}

result top(data& data, const Stack& stack) {
	if (empty(stack))
		return FAIL;

	data = stack->c_data;
	return OK;
}

result push(data data, Stack& stack) {
	Node* new_node = new (std::nothrow) Node;
	if (new_node == nullptr)
		return FAIL;

	new_node->c_data = data;
	new_node->next = stack;
	stack = new_node;
	return OK;
}

result pop(Stack& stack) {
	if (empty(stack))
		return FAIL;

	Node* first = stack;
	stack = stack->next;
	delete first;
	return OK;
}

} // namespace stack
