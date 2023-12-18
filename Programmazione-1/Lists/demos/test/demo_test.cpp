#include <iostream>
#include <fstream>
#include <cstring>
#include "demo_test.hpp"
#include "demo_cli.hpp"

using namespace std;

// demo list implementation
void list::print_data(const custom& data) { cout << "a: " << data.a << ", b: " << data.b; }
int list::compare_data(const custom& data1, const custom& data2) { return data1.a - data2.a; }

// demo app
void init_list(list::Node*& list, int size) {
	init(list);

	for (int i = 0; i < size; i++) {
		custom data = get_random_data();
		insert_order(list, data);
	}
}

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

int get_size(const int base) {
	cout << "Enter the list size (default: " << base << "): ";

	char* buffer = new char[100];
	cin.getline(buffer, 100, '\n');

	if (strlen(buffer) == 0)
		return base;

	int size = atoi(buffer);

	if (size <= 0) {
		cout << "Invalid size, using default" << std::endl;
		return base;
	}

	return size;
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
	int j = 0;
	while (file.getline(buffer, 100, '\n')) {
		char line[sizeof(buffer) + 4];
		if (i < 9) {
			strcat((char*)menu, buffer);
			strcat((char*)menu, "\n");
		} else {
			snprintf(line, sizeof(line), "%c. %s\n", letters[j], buffer);
			strcat((char*)menu, line);
			j++;
		}
		i++;
	}

	const char* exit = "\nPress z to exit\n";
	strcat((char*)menu, exit);

	file.close();
	return menu;
}

void init_app(list::Node*& list, int argc, char** argv, const int default_size = 10) {
	CliOpts opts = parse_opts(argc, argv);

	if (opts.help) {
		cout << get_usage(argv[0]) << endl;
		exit(0);
	}

	if (opts.version) {
		cout << "Version: 1.0.0" << endl;
		exit(0);
	}

	if (opts.author) {
		cout << "Author: "
			 << "icecube" << endl;
		exit(0);
	}

	int size = opts.ask_size ? get_size(default_size) : default_size;

	init_list(list, size);
}

void run(list::Node*& list, const char* menu) {
	const char exit = 'z';
	char option;
	int index;

	cout << menu << endl << "Initial list:" << endl;
	print(list);
	cout << endl;

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
			list::Node* found = find_node(list, index);
			if (found == nullptr) {
				cout << "No node found" << endl;
				break;
			}
			list::print_data(found->c_data);
			cout << endl;
		} break;
		case 'n': {
			cout << "Index: ";
			cin >> index;
			list::Node* prev = prev_node(list, find_node(list, index));
			if (prev == nullptr) {
				cout << "No previous node" << endl;
				break;
			}
			list::print_data(prev->c_data);
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

		if (option != exit && option != 'b' && option != 'a') {
			cout << endl;
			print(list);
		}

		cout << endl;
	} while (option != exit);
}

void app(list::Node*& list, int argc, char** argv) {
	init_app(list, argc, argv);

	const char* menu = get_menu("demos/test/menu.txt");

	if (menu == nullptr) {
		cerr << "Error opening menu file" << endl;
		deinit(list);
		exit(1);
	}

	run(list, menu);

	cout << "Bye!" << endl;
	delete[] menu;
}
