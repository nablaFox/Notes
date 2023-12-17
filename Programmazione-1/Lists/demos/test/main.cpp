#include <cstdlib>
#include <iostream>
#include "demo_test.hpp"

int main(int argc, char** argv) {
	srand(time(NULL));

	list::node* list;

	app(list, argc, argv);

	deinit(list);
	return 0;
}
