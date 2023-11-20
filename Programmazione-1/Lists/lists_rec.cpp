#include "lists.hpp"
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

void print(node* head) {
	static int i = 0;
	if (empty(head))
		return;

	std::cout << "Element: " << i++ << ": " << head->data << std::endl;
	print(head->next);
}

int length(node* head) {
	if (empty(head))
		return 0;

	return length(head->next) + 1;
}

static node* create_node(node* next, int data) {
	node* new_node = new node;
	new_node->data = data;
	new_node->next = next;
	return new_node;
}

void insert_first(node*& head, int data) {
	node* new_node = create_node(head, data);
	head = new_node;
}

void insert_last(node*& head, int data) {
	if (!empty(head)) {
		return insert_last(head->next, data);
	}

	head = create_node(nullptr, data);
}

void insert_order(node*& head, int data) {
	if (empty(head) || data <= head->data)
		return insert_first(head, data);

	if (empty(head->next) && head->next->data <= data) {
		head->next = create_node(head->next, data);
		return;
	}

	insert_order(head->next, data);
}

void remove_first(node*& head) {
	if (empty(head))
		return;

	node* tmp = head;
	head = head->next;
	delete tmp;
}

void remove_element(node*& head, int data) {
	if (empty(head)) {
		return;
	}

	if (head->data == data) {
		node* to_delete = head;
		head = head->next;
		return delete to_delete;
	}

	if (empty(head->next) && head->next->data == data) {
		node* to_delete = head->next;
		head->next = head->next->next;
		return delete to_delete;
	}

	remove_element(head->next, data);
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

	node* new_node = create_node(list, head->data);
	return reverse_copy_helper(head->next, new_node);
}

node* reverse_copy(node* head) { return reverse_copy_helper(head, nullptr); }

node* find_node(node* head, int index) {
	if (index <= 0 || empty(head))
		return head;

	return find_node(head->next, index - 1);
}

node* prev_node(node* head, node* x) {
	if (empty(head))
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
	copied->data = head->data;
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
	concat_list->data = head1->data;
	concat_list->next = concat_copy(head1->next, head2);
	return concat_list;
}

} // namespace list
