#include "queue_list.hpp"
#include <iostream>

static bool empty(const queue::Node* node) { return node == nullptr; }
static queue::Node* create_node(queue::data data, queue::Node* next) {
	queue::Node* new_node = new (std::nothrow) queue::Node;
	new_node->c_data = data;
	new_node->next = next;
	return new_node;
}

namespace queue {

void init(Queue& q) { q.head = q.tail = nullptr; }

void deinit(Queue& q) {
	while (!empty(q.head))
		dequeue(q);
}

void print(const Queue& q) {
	Node* curr = q.head;

	for (int i = 0; curr != nullptr; curr = curr->next, i++) {
		std::cout << "Element " << i << ": ";
		print_data(curr->c_data);
		std::cout << std::endl;
	}
}

result enqueue(Queue& q, data data) {
	Node* new_node = create_node(data, nullptr);

	if (empty(new_node))
		return FAIL;

	if (empty(q.tail)) {
		q.head = q.tail = new_node;
		return OK;
	}

	q.tail->next = new_node;
	q.tail = new_node;
	return OK;
}

result dequeue(Queue& q) {
	if (empty(q.head))
		return FAIL;

	Node* to_delete = q.head;
	q.head = q.head->next;

	if (empty(q.head))
		q.tail = nullptr;

	delete to_delete;
	return OK;
}

} // namespace queue
