#include "list.hpp"
#include <iostream>
#include <iterator>

static bool empty(list::node*& head) { return head == nullptr; }

static bool single(list::node*& head) { return head->next == head; }

static list::node* create_node(list::node* next, list::data data) {
	list::node* new_node = new list::node;
	new_node->c_data = data;
	new_node->next = next;
	return new_node;
}

namespace list {

void init(node*& head) { head = nullptr; }

void deinit(node*& head) {
	if (empty(head))
		return;

	node* start = head;

	do {
		node* tmp = head;
		head = head->next;
		delete tmp;
	} while (head != start);
}

int length(node* head) {
	if (empty(head))
		return 0;

	int count = 0;
	node* start = head;

	do {
		head = head->next;
		count++;
	} while (head != start);

	return count;
}

void print(node* head) {
	if (empty(head))
		return;

	int count = 0;
	node* start = head;

	do {
		std::cout << "Element " << count++ << ": ";
		print_data(head->c_data);
		std::cout << std::endl;
		head = head->next;
	} while (head != start);
}

static void insert_at_empty(node*& head, data data) {
	if (!empty(head))
		return;

	head = new node;
	head->c_data = data;
	head->next = head;
}

void insert_first(node*& head, data data) {
	if (empty(head)) {
		return insert_at_empty(head, data);
	}

	node* tmp = head;
	while (tmp->next != head) {
		tmp = tmp->next;
	}

	node* new_node = create_node(head, data);
	head = new_node;
	tmp->next = new_node;
}

void insert_last(node*& head, data data) {
	if (empty(head)) {
		return insert_at_empty(head, data);
	}

	node* tmp = head;
	while (tmp->next != head) {
		tmp = tmp->next;
	}

	node* new_node = create_node(tmp->next, data);
	tmp->next = new_node;
}

void insert_at(node*& head, data data, int index) {
	if (empty(head) || index <= 0)
		return insert_first(head, data);

	node* tmp = head;
	while (index != 0) {
		tmp = tmp->next;
		index--;
	}

	tmp->next = create_node(tmp->next, data);
}

void insert_order(node*& head, data data) {
	if (empty(head) || compare_data(data, head->c_data) <= 0) {
		return insert_first(head, data);
	}

	node* curr = head;
	while (curr->next != head && compare_data(data, curr->next->c_data) > 0) {
		curr = curr->next;
	}

	curr->next = create_node(curr->next, data);
};

static void delete_single(node*& head) {
	delete head;
	head = nullptr;
}

void remove_first(node*& head) {
	if (empty(head))
		return;

	if (single(head))
		return delete_single(head);

	node* to_delete = head;
	head = head->next;

	node* curr = head;
	while (curr->next != to_delete)
		curr = curr->next;

	curr->next = head;
	delete to_delete;
}

void remove_last(node*& head) {
	if (empty(head))
		return;

	if (single(head))
		return delete_single(head);

	node* curr = head;
	while (curr->next->next != head)
		curr = curr->next;

	node* to_delete = curr->next;
	curr->next = head;
	delete to_delete;
}

void remove_at(node*& head, int index) {
	if (empty(head))
		return;

	if (single(head))
		return delete_single(head);

	index = index < 0 ? -index : index;

	node* prev = head;
	node* curr = head->next;

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

void remove_element(node*& head, data data) {
	if (empty(head))
		return;

	if (single(head) && compare_data(head->c_data, data) == 0) {
		return delete_single(head);
	}

	if (compare_data(head->c_data, data) == 0)
		return remove_first(head);

	node* prev = head;
	node* curr = head->next;

	while (curr != head && compare_data(curr->c_data, data) != 0) {
		prev = curr;
		curr = curr->next;
	}

	if (curr == head)
		return;

	prev->next = curr->next;
	delete curr;
}

node* reverse(node* head) {
	if (empty(head) || single(head))
		return head;

	node* prev = nullptr;
	node* curr = head;
	node* next = nullptr;

	do {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	} while (curr != head);

	head->next = prev;
	return prev;
}

node* reverse_copy(node* head) {
	if (empty(head))
		return head;

	node* list = nullptr;
	node* curr = head;

	do {
		list = create_node(list, curr->c_data);
		curr = curr->next;
	} while (curr != head);

	node* list_tail = list;
	while (list_tail->next != nullptr)
		list_tail = list_tail->next;

	list_tail->next = list;

	return list;
}

node* find_node(node* head, int index) {
	if (empty(head))
		return nullptr;

	index = index > 0 ? index : -index;

	node* curr = head;
	while (index != 0) {
		index--;
		curr = curr->next;
	}

	return curr;
}

node* prev_node(node* head, node* x) {
	if (empty(head) || single(x))
		return head;

	node* curr = head;
	while (curr->next != head && curr->next != x)
		curr = curr->next;

	return curr;
}

node* copy(node* head) {
	if (empty(head))
		return nullptr;

	node* copied = nullptr;
	insert_at_empty(copied, head->c_data);

	node* new_head = copied;
	node* curr = head->next;

	while (curr != head) {
		copied->next = create_node(new_head, curr->c_data);
		copied = copied->next;
		curr = curr->next;
	}

	return new_head;
}

node* concat(node* head1, node* head2) {
	if (empty(head1))
		return head2;

	if (empty(head2))
		return head1;

	node* curr = head1;
	while (curr->next != head1)
		curr = curr->next;
	curr->next = head2;

	curr = head2;
	while (curr->next != head2)
		curr = curr->next;
	curr->next = head1;

	return head1;
}

node* concat_copy(node* head1, node* head2) {
	if (empty(head1))
		return copy(head2);

	if (empty(head2))
		return copy(head1);

	node* copied1 = copy(head1);
	node* curr = copied1;

	while (curr->next != copied1)
		curr = curr->next;

	node* copied2 = copy(head2);
	curr->next = copied2;
	curr = copied2;

	while (curr->next != copied2)
		curr = curr->next;
	curr->next = copied1;

	return copied1;
}

} // namespace list
