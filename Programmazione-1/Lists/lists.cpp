#include "lists.hpp"
#include <iostream>

static bool empty(list::node*& head) { return head == nullptr; }

static list::node* create_node(list::node* next, int data) {
	list::node* new_node = new list::node;
	new_node->data = data;
	new_node->next = next;
	return new_node;
}

namespace list {

void init(node*& head) { head = nullptr; }

void deinit(node*& head) {
	while (head != nullptr) {
		node* tmp = head;
		head = head->next;
		delete tmp;
	}
}

void print(node* head) {
	int i = 0;
	for (; head != nullptr; head = head->next) {
		std::cout << "Alement " << i++ << ": " << head->data << std::endl;
	}
}

int length(node* head) {
	int result = 0;

	for (; head != nullptr; head = head->next)
		result++;

	return result;
}

void insert_first(node*& head, int data) {
	node* new_node = create_node(head, data);
	head = new_node;
}

void insert_last(node*& head, int data) {
	node* new_node = create_node(nullptr, data);

	if (empty(head)) {
		head = new_node;
		return;
	}

	node* tmp = head;
	while (tmp->next != nullptr)
		tmp = tmp->next;

	tmp->next = new_node;
}

void insert_order(node*& head, int data) {
	if (empty(head) || data <= head->data) {
		return insert_first(head, data);
	}

	node* tmp = head;

	while ((tmp->next != nullptr) && (tmp->next->data <= data))
		tmp = tmp->next;

	node* new_node = create_node(tmp->next, data);
	tmp->next = new_node;
}

void remove_first(node*& head) {
	if (empty(head))
		return;

	node* tmp = head;
	head = head->next;
	delete tmp;
}

void remove_element(node*& head, int data) {
	if (empty(head))
		return;

	node* tmp = head;
	while (tmp->next != nullptr) {
		if (tmp->data == data) {
			head = head->next;
			return delete tmp;
		}
		if (tmp->next->data == data) {
			node* to_delete = tmp->next;
			tmp->next = tmp->next->next;
			delete to_delete;
			return;
		}
		if (tmp->next != nullptr) {
			tmp = tmp->next;
		}
	}
}

node* reverse(node* head) {
	node* prev = nullptr;
	node* curr = head;
	node* next = nullptr;

	while (curr != nullptr) {
		next = curr->next; // Store next
		curr->next = prev; // Reverse current node's pointer
		prev = curr;	   // Move pointers one position ahead.
		curr = next;	   // Move pointers one position ahead.
	}

	return prev;
}

node* reverse_copy(node* head) {
	node* list = nullptr;

	while (head != nullptr) {
		node* new_node = create_node(list, head->data);
		list = new_node;
		head = head->next;
	}

	return list;
}

node* find_node(node* head, int index) {
	if (index < 0 || empty(head))
		return nullptr;

	for (int i = 0; head != nullptr && i < index; i++) {
		head = head->next;
	}

	return head;
}

node* prev_node(node* head, node* x) {
	if (head == nullptr || head == x)
		return nullptr;

	node* prev = head;
	while (head != nullptr && head != x) {
		prev = head;
		head = head->next;
	}

	if (head == nullptr)
		return nullptr;

	return prev;
}

node* copy(node* head) {
	if (empty(head))
		return nullptr;

	node* list = nullptr;

	while (head != nullptr) {
		insert_last(list, head->data);
		head = head->next;
	}

	return list;
}

node* concat(node* head1, node* head2) {
	if (empty(head1))
		return head2;
	if (empty(head2))
		return head1;

	node* tmp = head1;

	while (tmp != nullptr && tmp->next != nullptr)
		tmp = tmp->next;

	tmp->next = head2;

	return head1;
}

node* concat_copy(node* head1, node* head2) {
	if (empty(head1)) {
		return copy(head2);
	}
	if (empty(head2)) {
		return copy(head1);
	}

	node* new_list = copy(head1);

	node* tmp = new_list;
	while (tmp != nullptr && tmp->next != nullptr)
		tmp = tmp->next;

	tmp->next = copy(head2);

	return new_list;
}

} // namespace list
