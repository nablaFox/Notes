#include "../lists.hpp"
#include <iostream>
#include <time.h>

using namespace std;
using namespace list;

int main(int argc, char* argv[]) {
	srand(time(NULL));

	int size;

	cout << "Size: ";
	cin >> size;

	node* list;
	init(list);

	for (int i = 0; i < size; i++) {
		insert_last(list, rand() % 10 + 1);
	}

	print(list);
	deinit(list);

	return 0;
}
