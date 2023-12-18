#include "list.hpp"
#include <iostream>

static bool empty(list::node*& head) { return head == nullptr; }

static list::node* create_node(list::node* next, list::data data) {
	list::node* new_node = new list::node;
	new_node->c_data = data;
	new_node->next = next;
	return new_node;
}

namespace list {

void init(node*& head) { head = nullptr; }

void deinit(node*& head) {
	while (!empty(head)) {
		node* tmp = head;
		head = head->next;
		delete tmp;
	}
}

void print(node* head) {
	int i = 0;
	for (; !empty(head); head = head->next) {
		std::cout << "Element " << i++ << ": ";
		print_data(head->c_data);
		std::cout << std::endl;
	}
}

int length(node* head) {
	int result = 0;

	for (; !empty(head); head = head->next)
		result++;

	return result;
}

void insert_first(node*& head, data data) {
	node* new_node = create_node(head, data);
	head = new_node;
}

void insert_last(node*& head, data data) {
	if (empty(head)) {
		return insert_first(head, data);
	}

	node* tmp = head;
	while (tmp->next != nullptr)
		tmp = tmp->next;

	tmp->next = create_node(nullptr, data);
}

void insert_order(node*& head, data data) {
	if (empty(head) || compare_data(data, head->c_data) <= 0)
		return insert_first(head, data);

	node* tmp = head;
	while (tmp->next != nullptr && compare_data(data, tmp->next->c_data) > 0)
		tmp = tmp->next;

	tmp->next = create_node(tmp->next, data);
}

void insert_at(node*& head, data data, int index) {
	if (index <= 0 || empty(head))
		return insert_first(head, data);

	node* tmp = head;
	while (tmp->next != nullptr && index != 0) {
		tmp = tmp->next;
		index--;
	}

	tmp->next = create_node(tmp->next, data);
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

	node* tmp = head;
	while (tmp->next->next != nullptr)
		tmp = tmp->next;

	delete tmp->next;
	tmp->next = nullptr;
}

void remove_at(node*& head, int index) {
	if (index <= 0 || empty(head))
		return remove_first(head);

	node* tmp = head;
	while (tmp->next->next != nullptr && index != 1) {
		tmp = tmp->next;
		index--;
	}

	node* to_delete = tmp->next;
	tmp->next = tmp->next->next;
	delete to_delete;
}

void remove_element(node*& head, data data) {
	if (empty(head))
		return;

	node* tmp = head;
	while (tmp->next != nullptr) {
		if (compare_data(tmp->c_data, data) == 0) {
			head = head->next;
			return delete tmp;
		}
		if (compare_data(tmp->next->c_data, data) == 0) {
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
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	return prev;
}

node* reverse_copy(node* head) {
	node* list = nullptr;

	while (!empty(head)) {
		node* new_node = create_node(list, head->c_data);
		list = new_node;
		head = head->next;
	}

	return list;
}

node* find_node(node* head, int index) {
	if (index < 0 || empty(head))
		return nullptr;

	for (int i = 0; !empty(head) && i < index; i++) {
		head = head->next;
	}

	return head;
}

node* prev_node(node* head, node* x) {
	if (empty(head) || head == x)
		return nullptr;

	node* prev = head;
	while (!empty(head) && head != x) {
		prev = head;
		head = head->next;
	}

	if (empty(head))
		return nullptr;

	return prev;
}

node* copy(node* head) {
	if (empty(head))
		return nullptr;

	node* copied = create_node(nullptr, head->c_data);
	node* new_head = copied;

	while (!empty(head->next)) {
		copied->next = create_node(nullptr, head->next->c_data);
		copied = copied->next;
		head = head->next;
	}

	return new_head;
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
