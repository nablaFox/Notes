#include <iostream>
#include <fstream>
#include <cstring>
#include "demo_test.hpp"

using namespace std;

// demo list implementation
void list::print_node(const custom& data) { std::cout << "a: " << data.a << ", b: " << data.b; }
int list::compare(const custom& data1, const custom& data2) { return data1.a - data2.a; }

// demo functions
custom get_user_data() {
	custom data;
	cout << "a: ";
	cin >> data.a;
	cout << "b: ";
	cin >> data.b;
	return data;
}

custom get_random_data() {
	custom data;
	data.a = rand() % 100;
	data.b = rand() % 100;
	return data;
}

const char* get_menu(const char* filename) {
	fstream file(filename, ios::in);

	if (!file.is_open()) {
		return nullptr;
	}

	const char* menu = new char[1000];

	const char* letters = "abcdefghijklmnopqrstuvwxyz";
	char buffer[100];

	int i = 0;
	while (file.getline(buffer, 100, '\n')) {
		char line[sizeof(buffer) + 4];
		snprintf(line, sizeof(line), "%c. %s\n", letters[i], buffer);
		strcat((char*)menu, line);
		i++;
	}

	const char* exit = "\nPress z to exit\n";
	strcat((char*)menu, exit);

	file.close();
	return menu;
}

void init_list(list::node*& list, int size) {
	init(list);

	for (int i = 0; i < size; i++) {
		custom data = get_random_data();
		insert_last(list, data);
	}
}

void app(list::node*& list) {
	const char* menu = get_menu("demos/test/menu.txt");

	if (menu == nullptr) {
		cerr << "Error opening menu file" << endl;
		deinit(list);
		exit(1);
	}

	const char exit = 'z';
	int index;
	char option;
	cout << menu << endl;

	do {
		cout << "Option: ";
		cin >> option;

		switch (option) {
		case 'a':
			cout << "Length: " << length(list) << endl;
			break;
		case 'b':
			cout << endl;
			print(list);
			break;
		case 'c':
			insert_first(list, get_user_data());
			break;
		case 'd':
			insert_last(list, get_user_data());
			break;
		case 'e':
			insert_order(list, get_user_data());
			break;
		case 'f':
			cout << "Index: ";
			cin >> index;
			insert_at(list, get_user_data(), index);
			break;
		case 'g':
			remove_first(list);
			break;
		case 'h':
			remove_last(list);
			break;
		case 'i':
			cout << "Index: ";
			cin >> index;
			remove_at(list, index);
			break;
		case 'j':
			remove_element(list, get_user_data());
			break;
		case 'k':
			list = reverse(list);
			break;
		case 'l':
			list = reverse_copy(list);
			break;
		case 'm': {
			cout << "Index: ";
			cin >> index;
			list::node* found = find_node(list, index);
			if (found == nullptr) {
				cout << "No node found" << endl;
				break;
			}
			list::print_node(found->c_data);
			cout << endl;
		} break;
		case 'n': {
			cout << "Index: ";
			cin >> index;
			list::node* prev = prev_node(list, find_node(list, index));
			if (prev == nullptr) {
				cout << "No previous node" << endl;
				break;
			}
			list::print_node(prev->c_data);
			cout << endl;
		} break;
		case 'o':
			list = copy(list);
			break;
		case 'p':
			list = concat(list, copy(list));
			break;
		case 'q':
			list = concat_copy(list, list);
			break;
		case 'r':
			cout << menu;
			break;
		case exit:
			break;
		default:
			cout << "Invalid option" << endl;
			break;
		}

		if (option != exit && option != 'b') {
			cout << endl;
			print(list);
		}

		cout << endl;
	} while (option != exit);

	cout << "Bye!" << endl;
	delete[] menu;
}
