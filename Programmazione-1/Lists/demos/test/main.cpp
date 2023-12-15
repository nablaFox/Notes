#include "../../lists.hpp"
#include <iostream>
#include <fstream>
#include <cstring>
#include <time.h>

using namespace std;
using namespace list;

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

	file.close();
	return menu;
}

void init_list(node*& list, int size) {
	init(list);

	for (int i = 0; i < size; i++) {
		custom data = get_random_data();
		insert_last(list, data);
	}
}

void app(node*& list) {
	const char* menu = get_menu("demos/test/menu.txt");

	if (menu == nullptr) {
		cerr << "Error opening menu file" << endl;
		deinit(list);
		exit(1);
	}

	int index;
	const char exit = 'q';
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
			remove_first(list);
			break;
		case 'g':
			remove_last(list);
			break;
		case 'h':
			remove_element(list, get_user_data());
			break;
		case 'i':
			list = reverse(list);
			break;
		case 'j':
			list = reverse_copy(list);
			break;
		case 'k': {
			cout << "Index: ";
			cin >> index;
			node* found = find_node(list, index);
			if (found == nullptr) {
				cout << "No node found" << endl;
				break;
			}
			print_node(found->c_data);
			cout << endl;
		} break;
		case 'l': {
			cout << "Index: ";
			cin >> index;
			node* prev = prev_node(list, find_node(list, index));
			if (prev == nullptr) {
				cout << "No previous node" << endl;
				break;
			}
			print_node(prev->c_data);
			cout << endl;
		} break;
		case 'm':
			list = copy(list);
			break;
		case 'n':
			list = concat(list, copy(list));
			break;
		case 'o':
			list = concat_copy(list, list);
			break;
		case 'p':
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

int main() {
	srand(time(NULL));

	node* list;
	init_list(list, 10);

	app(list);

	deinit(list);
	return 0;
}
