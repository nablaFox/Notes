#pragma once

namespace queue {

enum result { OK, FAIL };

struct Queue {
	int head, tail;
	data* c_data;
	int size;
};

void init(Queue&);
void deinit(Queue&);
void print(const Queue&);
void print_data(const data&);
result enqueue(Queue&, data);
result dequeue(Queue&);
result front(const Queue&, data&);

} // namespace queue
