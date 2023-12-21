#pragma once

namespace queue {

enum result { OK, FAIL };

struct Node {
	data c_data;
	Node* next;
};

struct Queue {
	Node* tail;
	Node* head;
};

void init(Queue&);
void deinit(Queue&);
void print(const Queue&);
void print_data(const data&);
result enqueue(Queue&, data);
result dequeue(Queue&);
result front(const Queue&, data&);

} // namespace queue
