#pragma once

namespace stack {

enum result { OK, FAIL };

struct Stack {
	int index;
	data c_data[MAX_SIZE];
};

void init(Stack&);
void deinit(Stack&);
void print_data(const data& data);
void print(const Stack&);
result top(data&, const Stack&);
result push(data, Stack&);
result pop(Stack&);

} // namespace stack
