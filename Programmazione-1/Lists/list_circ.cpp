#include "list.hpp"
#include <iostream>
#include <iterator>

static bool empty(list::Node*& head) { return head == nullptr; }

static bool single(list::Node*& head) { return head->next == head; }

static list::Node* create_node(list::Node* next, list::data data) {
	list::Node* new_node = new list::Node;
	new_node->c_data = data;
	new_node->next = next;
	return new_node;
}

namespace list {

void init(Node*& head) { head = nullptr; }

void deinit(Node*& head) {
	if (empty(head))
		return;

	Node* start = head;

	do {
		Node* tmp = head;
		head = head->next;
		delete tmp;
	} while (head != start);
}

int length(Node* head) {
	if (empty(head))
		return 0;

	int count = 0;
	Node* start = head;

	do {
		head = head->next;
		count++;
	} while (head != start);

	return count;
}

void print(Node* head) {
	if (empty(head))
		return;

	int count = 0;
	Node* start = head;

	do {
		std::cout << "Element " << count++ << ": ";
		print_data(head->c_data);
		std::cout << std::endl;
		head = head->next;
	} while (head != start);
}

static void insert_at_empty(Node*& head, data data) {
	if (!empty(head))
		return;

	head = new Node;
	head->c_data = data;
	head->next = head;
}

void insert_first(Node*& head, data data) {
	if (empty(head)) {
		return insert_at_empty(head, data);
	}

	Node* tmp = head;
	while (tmp->next != head) {
		tmp = tmp->next;
	}

	Node* new_node = create_node(head, data);
	head = new_node;
	tmp->next = new_node;
}

void insert_last(Node*& head, data data) {
	if (empty(head)) {
		return insert_at_empty(head, data);
	}

	Node* tmp = head;
	while (tmp->next != head) {
		tmp = tmp->next;
	}

	Node* new_node = create_node(tmp->next, data);
	tmp->next = new_node;
}

void insert_at(Node*& head, data data, int index) {
	if (empty(head) || index <= 0)
		return insert_first(head, data);

	Node* tmp = head;
	while (index != 0) {
		tmp = tmp->next;
		index--;
	}

	tmp->next = create_node(tmp->next, data);
}

void insert_order(Node*& head, data data) {
	if (empty(head) || compare_data(data, head->c_data) <= 0) {
		return insert_first(head, data);
	}

	Node* curr = head;
	while (curr->next != head && compare_data(data, curr->next->c_data) > 0) {
		curr = curr->next;
	}

	curr->next = create_node(curr->next, data);
};

static void delete_single(Node*& head) {
	delete head;
	head = nullptr;
}

void remove_first(Node*& head) {
	if (empty(head))
		return;

	if (single(head))
		return delete_single(head);

	Node* to_delete = head;
	head = head->next;

	Node* curr = head;
	while (curr->next != to_delete)
		curr = curr->next;

	curr->next = head;
	delete to_delete;
}

void remove_last(Node*& head) {
	if (empty(head))
		return;

	if (single(head))
		return delete_single(head);

	Node* curr = head;
	while (curr->next->next != head)
		curr = curr->next;

	Node* to_delete = curr->next;
	curr->next = head;
	delete to_delete;
}

void remove_at(Node*& head, int index) {
	if (empty(head))
		return;

	if (single(head))
		return delete_single(head);

	index = index < 0 ? -index : index;

	Node* prev = head;
	Node* curr = head->next;

	while (index != 1 && index != 0) {
		prev = curr;
		curr = curr->next;
		index--;
	}

	if (curr == head)
		return remove_last(head);

	if (curr == head->next)
		return remove_first(head);

	prev->next = curr->next;
	delete curr;
}

void remove_element(Node*& head, data data) {
	if (empty(head))
		return;

	if (single(head) && compare_data(head->c_data, data) == 0) {
		return delete_single(head);
	}

	if (compare_data(head->c_data, data) == 0)
		return remove_first(head);

	Node* prev = head;
	Node* curr = head->next;

	while (curr != head && compare_data(curr->c_data, data) != 0) {
		prev = curr;
		curr = curr->next;
	}

	if (curr == head)
		return;

	prev->next = curr->next;
	delete curr;
}

Node* reverse(Node* head) {
	if (empty(head) || single(head))
		return head;

	Node* prev = nullptr;
	Node* curr = head;
	Node* next = nullptr;

	do {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	} while (curr != head);

	head->next = prev;
	return prev;
}

Node* reverse_copy(Node* head) {
	if (empty(head))
		return head;

	Node* list = nullptr;
	Node* curr = head;

	do {
		list = create_node(list, curr->c_data);
		curr = curr->next;
	} while (curr != head);

	Node* list_tail = list;
	while (list_tail->next != nullptr)
		list_tail = list_tail->next;

	list_tail->next = list;

	return list;
}

Node* find_node(Node* head, int index) {
	if (empty(head))
		return nullptr;

	index = index > 0 ? index : -index;

	Node* curr = head;
	while (index != 0) {
		index--;
		curr = curr->next;
	}

	return curr;
}

Node* prev_node(Node* head, Node* x) {
	if (empty(head) || single(x))
		return head;

	Node* curr = head;
	while (curr->next != head && curr->next != x)
		curr = curr->next;

	return curr;
}

Node* copy(Node* head) {
	if (empty(head))
		return nullptr;

	Node* copied = nullptr;
	insert_at_empty(copied, head->c_data);

	Node* new_head = copied;
	Node* curr = head->next;

	while (curr != head) {
		copied->next = create_node(new_head, curr->c_data);
		copied = copied->next;
		curr = curr->next;
	}

	return new_head;
}

Node* concat(Node* head1, Node* head2) {
	if (empty(head1))
		return head2;

	if (empty(head2))
		return head1;

	Node* curr = head1;
	while (curr->next != head1)
		curr = curr->next;
	curr->next = head2;

	curr = head2;
	while (curr->next != head2)
		curr = curr->next;
	curr->next = head1;

	return head1;
}

Node* concat_copy(Node* head1, Node* head2) {
	if (empty(head1))
		return copy(head2);

	if (empty(head2))
		return copy(head1);

	Node* copied1 = copy(head1);
	Node* curr = copied1;

	while (curr->next != copied1)
		curr = curr->next;

	Node* copied2 = copy(head2);
	curr->next = copied2;
	curr = copied2;

	while (curr->next != copied2)
		curr = curr->next;
	curr->next = copied1;

	return copied1;
}

} // namespace list
