#include <iostream>
#include "queue.hpp"

static bool empty(const queue::Queue& q) { return q.head == q.tail; }
static int next(int index, const queue::Queue& q) { return (index + 1) % q.size; }
static bool full(const queue::Queue& q) { return next(q.tail, q) == q.head; }

namespace queue {

void init(Queue& q) {
	q.size = SIZE + 1;
	q.tail = q.head = 0;
	q.c_data = new data[SIZE];
}

void deinit(Queue& q) { delete[] q.c_data; }

void print(const Queue& q) {
	if (empty(q)) {
		return;
	}

	for (int i = q.head, j = 0; i != q.tail; i = next(i, q), j++) {
		std::cout << "Element " << j << ": ";
		print_data(q.c_data[i]);
		std::cout << '\n';
	}
}

result enqueue(Queue& q, data data) {
	if (full(q))
		return FAIL;

	q.c_data[q.tail] = data;
	q.tail = next(q.tail, q);
	return OK;
}

result dequeue(Queue& q) {
	if (empty(q))
		return FAIL;

	q.head = next(q.head, q);
	return OK;
}

result front(const Queue& q, data& data) {
	if (empty(q))
		return FAIL;

	data = q.c_data[q.head];
	return OK;
}

} // namespace queue
