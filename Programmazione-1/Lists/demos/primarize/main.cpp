#include "../../list.hpp"
#include <cmath>
#include <cstdlib>
#include <iostream>

void list::print_data(const int& data) { std::cout << data << " "; }
int list::compare_data(const int& data1, const int& data2) { return data1 - data2; }

bool isPrime(int data) {
	if (data <= 2 || data % 2 == 0)
		return false;

	for (int i = 3; i < std::sqrt(data); i++) {
		if (data % i == 0)
			return false;
	}

	return true;
}

void primarize(list::List list) {
	if (list == nullptr || list->next == nullptr)
		return;

	list::List current = list->next;

	while (current != nullptr) {
		if (isPrime(current->c_data)) {
			list = current;
			current = current->next;
		} else {
			list::List toDelete = current;
			current = current->next;
			list->next = current;
			delete toDelete;
		}
	}
}

int main(int argc, char* argv[]) {
	srand(time(NULL));
	int size;

	std::cout << "Enter the size of the list: ";
	std::cin >> size;

	list::List list;
	list::init(list);

	list::insert_at(list, 1, 0);

	for (int i = 0; i < size; i++) {
		list::insert_order(list, rand() % 100);
	}

	list::print(list);

	primarize(list);

	std::cout << std::endl << "After primarization:" << std::endl;

	list::print(list);

	return 0;
}
