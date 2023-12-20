#pragma once

namespace stack {

enum result { OK, FAIL };

struct Stack {
	int index;
	data* c_data;
};

void init(Stack&);
void deinit(Stack&);
void print_data(const data& data);
int compare_data(const data&, const data&);
void print(const Stack&);
result top(data&, const Stack&);
result push(data, Stack&);
result pop(Stack&);

} // namespace stack
