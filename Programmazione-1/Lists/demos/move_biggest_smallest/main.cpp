#include <cstdlib>
#include <iostream>
#include "../../list.hpp"

void list::print_data(const int& data) { std::cout << data << " "; }
int list::compare_data(const int& data1, const int& data2) { return data1 - data2; }

void moveBiggestAtEnd(list::List& list) {
	if (!list || !list->next) {
		return;
	}

	list::List curr = list;
	list::List prev = nullptr;
	int biggest = list->c_data;

	while (curr->next != nullptr) {
		if (list::compare_data(biggest, curr->next->c_data) < 0) {
			biggest = curr->next->c_data;
			prev = curr;
		}

		curr = curr->next;
	}

	if (!prev)
		return;

	list::Node* biggest_node = prev->next;
	prev->next = biggest_node->next;
	biggest_node->next = nullptr;
	curr->next = biggest_node;
}

void moveSmallestAtBeginning(list::List& list) {
	if (!list || !list->next) {
		return;
	}

	list::List curr = list;
	list::List prev = nullptr;
	int smallest = list->c_data;

	while (curr->next != nullptr) {
		if (list::compare_data(smallest, curr->next->c_data) > 0) {
			smallest = curr->next->c_data;
			prev = curr;
		}

		curr = curr->next;
	}

	if (!prev)
		return;

	list::Node* smallest_node = prev->next;
	prev->next = smallest_node->next;
	smallest_node->next = list->next;
	list = smallest_node;
}

int main() {
	srand(time(NULL));
	int size;

	std::cout << "Size: ";
	std::cin >> size;

	list::List list;

	list::init(list);

	for (int i = 0; i < size; i++) {
		list::insert_last(list, rand() % 100);
	}

	list::print(list);

	moveSmallestAtBeginning(list);
	moveBiggestAtEnd(list);

	std::cout << "\nAfter:\n";
	list::print(list);

	list::deinit(list);

	return 0;
}
