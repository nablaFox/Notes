#include <iostream>
#include "stack.hpp"

static bool empty(const stack::Stack& stack) { return stack.index == 0; }
static bool full(const stack::Stack& stack) { return stack.index == stack::MAX_SIZE; }

namespace stack {

void init(Stack& stack) {
	stack.index = 0;
	stack.c_data = new data[MAX_SIZE];
}

void deinit(Stack& stack) {
	delete[] stack.c_data;
	stack.index = 0;
}

void print(const Stack& stack) {
	for (int i = stack.index; i > 0; i--) {
		std::cout << "Element " << i << ": ";
		print_data(stack.c_data[i - 1]);
		std::cout << std::endl;
	}
}

result top(data& data, const Stack& stack) {
	if (empty(stack))
		return FAIL;

	data = stack.c_data[stack.index - 1];
	return OK;
}

result push(data data, Stack& stack) {
	if (full(stack))
		return FAIL;

	stack.c_data[stack.index] = data;
	stack.index++;
	return OK;
}

result pop(Stack& stack) {
	if (empty(stack))
		return FAIL;

	stack.index--;
	return OK;
}

} // namespace stack
