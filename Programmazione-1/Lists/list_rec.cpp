#include "list.hpp"
#include <iostream>

static bool empty(list::node*& head) { return head == nullptr; }

namespace list {

void init(node*& head) { head = nullptr; }

void deinit(node*& head) {
	if (!empty(head)) {
		deinit(head->next);
	}

	delete head;
}

static void print_helper(node* head, int i) {
	if (empty(head))
		return;

	std::cout << "Element " << i << ": ";
	print_data(head->c_data);
	std::cout << std::endl;
	print_helper(head->next, i + 1);
}

void print(node* head) { print_helper(head, 0); }

int length(node* head) {
	if (empty(head))
		return 0;

	return length(head->next) + 1;
}

static node* create_node(node* next, data data) {
	node* new_node = new node;
	new_node->c_data = data;
	new_node->next = next;
	return new_node;
}

void insert_first(node*& head, data data) {
	node* new_node = create_node(head, data);
	head = new_node;
}

void insert_last(node*& head, data data) {
	if (!empty(head)) {
		return insert_last(head->next, data);
	}

	head = create_node(nullptr, data);
}

void insert_order(node*& head, data data) {
	if (empty(head) || compare_data(data, head->c_data) <= 0)
		return insert_first(head, data);

	if (!empty(head->next) && compare_data(data, head->next->c_data) <= 0) {
		head->next = create_node(head->next, data);
		return;
	}

	insert_order(head->next, data);
}

void insert_at(node*& head, data data, int index) {
	if (index <= 0 || empty(head))
		return insert_first(head, data);

	if (index > 0)
		return insert_at(head->next, data, index - 1);

	head->next = create_node(head->next, data);
}

void remove_first(node*& head) {
	if (empty(head))
		return;

	node* tmp = head;
	head = head->next;
	delete tmp;
}

void remove_last(node*& head) {
	if (empty(head))
		return;

	if (empty(head->next)) {
		delete head;
		head = nullptr;
		return;
	}

	remove_last(head->next);
}

void remove_at(node*& head, int index) {
	if (index <= 0 || empty(head))
		return remove_first(head);

	if (index > 1 && !empty(head->next->next))
		return remove_at(head->next, index - 1);

	node* to_delete = head->next;
	head->next = head->next->next;
	delete to_delete;
}

void remove_element(node*& head, data data) {
	if (empty(head))
		return;

	if (compare_data(head->c_data, data) == 0) {
		node* to_delete = head;
		head = head->next;
		delete to_delete;
	} else {
		remove_element(head->next, data);
	}
}

static node* reverse_helper(node* curr, node* prev) {
	if (empty(curr))
		return prev;

	node* next = curr->next;
	curr->next = prev;
	return reverse_helper(next, curr);
}

node* reverse(node* head) { return reverse_helper(head, nullptr); }

static node* reverse_copy_helper(node* head, node* list) {
	if (empty(head)) {
		return list;
	}

	node* new_node = create_node(list, head->c_data);
	return reverse_copy_helper(head->next, new_node);
}

node* reverse_copy(node* head) { return reverse_copy_helper(head, nullptr); }

node* find_node(node* head, int index) {
	if (empty(head) || index < 0) {
		return nullptr;
	}

	return index == 0 ? head : find_node(head->next, index - 1);
}

node* prev_node(node* head, node* x) {
	if (empty(head) || empty(x))
		return nullptr;

	if (!empty(head) && head->next == x) {
		return head;
	}

	return prev_node(head->next, x);
}

node* copy(node* head) {
	if (empty(head)) {
		return nullptr;
	}

	node* copied = new node;
	copied->c_data = head->c_data;
	copied->next = copy(head->next);
	return copied;
}

node* concat(node* head1, node* head2) {
	if (empty(head1))
		return head2;

	if (empty(head2))
		return head1;

	head1->next = concat(head1->next, head2);
	return head1;
}

node* concat_copy(node* head1, node* head2) {
	if (empty(head1))
		return copy(head2);

	node* concat_list = new node;
	concat_list->c_data = head1->c_data;
	concat_list->next = concat_copy(head1->next, head2);
	return concat_list;
}

} // namespace list
