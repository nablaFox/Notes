#include <cstdlib>
#include <iostream>
#include <cstring>
#include "../../list.hpp"

int list::compare_data(const Person& data1, const Person& data2) { return strcmp(data1.name, data2.name); }

void list::print_data(const Person& data) {
	std::cout << "\nName: " << data.name << "\n";
	std::cout << "Age: " << data.age << "\n";
}

void populate(list::List& people, int size) {
	for (int i = 0; i < size; i++) {
		Person new_person;
		new_person.age = rand() % 100 + 1;

		char name[20];
		sprintf(name, "Person %d", i);
		strcpy(new_person.name, name);

		list::insert_last(people, new_person);
	}
}

void get_leader(list::List& people, int size, char**& order, const int M = 3) {
	order = new char*[size - 1];
	list::Node* current = people;

	for (int i = 0; i < size - 1; i++) {
		int steps = M;

		while (steps--) {
			current = current->next;
		}

		order[i] = new char[20];
		strcpy(order[i], current->c_data.name);

		list::remove_element(people, current->c_data);
	}
}

int main() {
	srand(time(NULL));
	int size;

	std::cout << "Size: ";
	std::cin >> size;

	list::List people;
	list::init(people);

	char** order = nullptr;

	populate(people, size);
	list::print(people);

	get_leader(people, size, order);

	std::cout << "The leader is " << people->c_data.name;

	std::cout << "\nThe order of elimination is: ";

	for (int i = 0; i < size - 1; i++) {
		std::cout << "\n" << order[i];
	}

	for (int i = 0; i < size - 1; i++) {
		delete[] order[i];
	}

	delete order;

	list::deinit(people);

	return 0;
}
