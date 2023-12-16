#include <iostream>
#include "demo_test.hpp"

int main() {
	srand(time(NULL));

	list::node* list;
	init_list(list, 10);

	app(list);

	list::deinit(list);
	return 0;
}
