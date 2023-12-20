#include <iostream>

using namespace std;
using namespace stack;

int stack::compare_data(const int& data1, const int& data2) { return data1 - data2; };
void stack::print_data(const int& data) { cout << data; };

int main(int argc, char* argv[]) {
	stack::Stack stack;

	init(stack);

	for (int i = 1; i < 10; i++) {
		push(i, stack);
	}

	print(stack);

	pop(stack);

	cout << endl;
	print(stack);

	deinit(stack);
	return 0;
}
