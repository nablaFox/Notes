#pragma once

namespace stack {

enum result { OK, FAIL };

struct Node {
	data c_data;
	Node* next;
};

typedef Node* Stack;

void init(Stack&);
void deinit(Stack&);
void print_data(const data& data);
int compare_data(const data&, const data&);
void print(const Stack&);
result top(data&, const Stack&);
result push(data, Stack&);
result pop(Stack&);

} // namespace stack
