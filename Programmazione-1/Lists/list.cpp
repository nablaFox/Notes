#include "list.hpp"
#include <iostream>

static bool empty(list::Node*& head) { return head == nullptr; }

static list::Node* create_node(list::Node* next, list::data data) {
	list::Node* new_node = new list::Node;
	new_node->c_data = data;
	new_node->next = next;
	return new_node;
}

namespace list {

void init(Node*& head) { head = nullptr; }

void deinit(Node*& head) {
	while (!empty(head)) {
		Node* tmp = head;
		head = head->next;
		delete tmp;
	}
}

void print(Node* head) {
	int i = 0;
	for (; !empty(head); head = head->next) {
		std::cout << "Element " << i++ << ": ";
		print_data(head->c_data);
		std::cout << std::endl;
	}
}

int length(Node* head) {
	int result = 0;

	for (; !empty(head); head = head->next)
		result++;

	return result;
}

void insert_first(Node*& head, data data) {
	Node* new_node = create_node(head, data);
	head = new_node;
}

void insert_last(Node*& head, data data) {
	if (empty(head)) {
		return insert_first(head, data);
	}

	Node* tmp = head;
	while (tmp->next != nullptr)
		tmp = tmp->next;

	tmp->next = create_node(nullptr, data);
}

void insert_order(Node*& head, data data) {
	if (empty(head) || compare_data(data, head->c_data) <= 0)
		return insert_first(head, data);

	Node* tmp = head;
	while (tmp->next != nullptr && compare_data(data, tmp->next->c_data) > 0)
		tmp = tmp->next;

	tmp->next = create_node(tmp->next, data);
}

void insert_at(Node*& head, data data, int index) {
	if (index <= 0 || empty(head))
		return insert_first(head, data);

	Node* tmp = head;
	while (tmp->next != nullptr && index != 0) {
		tmp = tmp->next;
		index--;
	}

	tmp->next = create_node(tmp->next, data);
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

	Node* tmp = head;
	while (tmp->next->next != nullptr)
		tmp = tmp->next;

	delete tmp->next;
	tmp->next = nullptr;
}

void remove_at(Node*& head, int index) {
	if (index <= 0 || empty(head))
		return remove_first(head);

	Node* tmp = head;
	while (tmp->next->next != nullptr && index != 1) {
		tmp = tmp->next;
		index--;
	}

	Node* to_delete = tmp->next;
	tmp->next = tmp->next->next;
	delete to_delete;
}

void remove_element(Node*& head, data data) {
	if (empty(head))
		return;

	Node* tmp = head;
	while (tmp->next != nullptr) {
		if (compare_data(tmp->c_data, data) == 0) {
			head = head->next;
			return delete tmp;
		}
		if (compare_data(tmp->next->c_data, data) == 0) {
			Node* to_delete = tmp->next;
			tmp->next = tmp->next->next;
			delete to_delete;
			return;
		}
		if (tmp->next != nullptr) {
			tmp = tmp->next;
		}
	}
}

Node* reverse(Node* head) {
	Node* prev = nullptr;
	Node* curr = head;
	Node* next = nullptr;

	while (curr != nullptr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	return prev;
}

Node* reverse_copy(Node* head) {
	Node* list = nullptr;

	while (!empty(head)) {
		Node* new_node = create_node(list, head->c_data);
		list = new_node;
		head = head->next;
	}

	return list;
}

Node* find_node(Node* head, int index) {
	if (index < 0 || empty(head))
		return nullptr;

	for (int i = 0; !empty(head) && i < index; i++) {
		head = head->next;
	}

	return head;
}

Node* prev_node(Node* head, Node* x) {
	if (empty(head) || head == x)
		return nullptr;

	Node* prev = head;
	while (!empty(head) && head != x) {
		prev = head;
		head = head->next;
	}

	if (empty(head))
		return nullptr;

	return prev;
}

Node* copy(Node* head) {
	if (empty(head))
		return nullptr;

	Node* copied = create_node(nullptr, head->c_data);
	Node* new_head = copied;

	while (!empty(head->next)) {
		copied->next = create_node(nullptr, head->next->c_data);
		copied = copied->next;
		head = head->next;
	}

	return new_head;
}

Node* concat(Node* head1, Node* head2) {
	if (empty(head1))
		return head2;
	if (empty(head2))
		return head1;

	Node* tmp = head1;

	while (tmp != nullptr && tmp->next != nullptr)
		tmp = tmp->next;

	tmp->next = head2;

	return head1;
}

Node* concat_copy(Node* head1, Node* head2) {
	if (empty(head1)) {
		return copy(head2);
	}
	if (empty(head2)) {
		return copy(head1);
	}

	Node* new_list = copy(head1);

	Node* tmp = new_list;
	while (tmp != nullptr && tmp->next != nullptr)
		tmp = tmp->next;

	tmp->next = copy(head2);

	return new_list;
}

} // namespace list
