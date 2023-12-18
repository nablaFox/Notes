#include "list.hpp"
#include <iostream>

static bool empty(list::Node*& head) { return head == nullptr; }

namespace list {

void init(Node*& head) { head = nullptr; }

void deinit(Node*& head) {
	if (!empty(head)) {
		deinit(head->next);
	}

	delete head;
}

static void print_helper(Node* head, int i) {
	if (empty(head))
		return;

	std::cout << "Element " << i << ": ";
	print_data(head->c_data);
	std::cout << std::endl;
	print_helper(head->next, i + 1);
}

void print(Node* head) { print_helper(head, 0); }

int length(Node* head) {
	if (empty(head))
		return 0;

	return length(head->next) + 1;
}

static Node* create_node(Node* next, data data) {
	Node* new_node = new Node;
	new_node->c_data = data;
	new_node->next = next;
	return new_node;
}

void insert_first(Node*& head, data data) {
	Node* new_node = create_node(head, data);
	head = new_node;
}

void insert_last(Node*& head, data data) {
	if (!empty(head)) {
		return insert_last(head->next, data);
	}

	head = create_node(nullptr, data);
}

void insert_order(Node*& head, data data) {
	if (empty(head) || compare_data(data, head->c_data) <= 0)
		return insert_first(head, data);

	if (!empty(head->next) && compare_data(data, head->next->c_data) <= 0) {
		head->next = create_node(head->next, data);
		return;
	}

	insert_order(head->next, data);
}

void insert_at(Node*& head, data data, int index) {
	if (index <= 0 || empty(head))
		return insert_first(head, data);

	if (index > 0)
		return insert_at(head->next, data, index - 1);

	head->next = create_node(head->next, data);
}

void remove_first(Node*& head) {
	if (empty(head))
		return;

	Node* tmp = head;
	head = head->next;
	delete tmp;
}

void remove_last(Node*& head) {
	if (empty(head))
		return;

	if (empty(head->next)) {
		delete head;
		head = nullptr;
		return;
	}

	remove_last(head->next);
}

void remove_at(Node*& head, int index) {
	if (index <= 0 || empty(head))
		return remove_first(head);

	if (index > 1 && !empty(head->next->next))
		return remove_at(head->next, index - 1);

	Node* to_delete = head->next;
	head->next = head->next->next;
	delete to_delete;
}

void remove_element(Node*& head, data data) {
	if (empty(head))
		return;

	if (compare_data(head->c_data, data) == 0) {
		Node* to_delete = head;
		head = head->next;
		delete to_delete;
	} else {
		remove_element(head->next, data);
	}
}

static Node* reverse_helper(Node* curr, Node* prev) {
	if (empty(curr))
		return prev;

	Node* next = curr->next;
	curr->next = prev;
	return reverse_helper(next, curr);
}

Node* reverse(Node* head) { return reverse_helper(head, nullptr); }

static Node* reverse_copy_helper(Node* head, Node* list) {
	if (empty(head)) {
		return list;
	}

	Node* new_node = create_node(list, head->c_data);
	return reverse_copy_helper(head->next, new_node);
}

Node* reverse_copy(Node* head) { return reverse_copy_helper(head, nullptr); }

Node* find_node(Node* head, int index) {
	if (empty(head) || index < 0) {
		return nullptr;
	}

	return index == 0 ? head : find_node(head->next, index - 1);
}

Node* prev_node(Node* head, Node* x) {
	if (empty(head) || empty(x))
		return nullptr;

	if (!empty(head) && head->next == x) {
		return head;
	}

	return prev_node(head->next, x);
}

Node* copy(Node* head) {
	if (empty(head)) {
		return nullptr;
	}

	Node* copied = new Node;
	copied->c_data = head->c_data;
	copied->next = copy(head->next);
	return copied;
}

Node* concat(Node* head1, Node* head2) {
	if (empty(head1))
		return head2;

	if (empty(head2))
		return head1;

	head1->next = concat(head1->next, head2);
	return head1;
}

Node* concat_copy(Node* head1, Node* head2) {
	if (empty(head1))
		return copy(head2);

	Node* concat_list = new Node;
	concat_list->c_data = head1->c_data;
	concat_list->next = concat_copy(head1->next, head2);
	return concat_list;
}

} // namespace list
