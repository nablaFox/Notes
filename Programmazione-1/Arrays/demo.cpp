#include <iostream>
#include "array.hpp"
#include "sort.hpp"

using namespace std;
using namespace arr;

void arr::print_data(const int& data) { cout << data << " "; }
int arr::compare_data(const int& data1, const int& data2) { return data1 - data2; }

void populate_rand(int* arr, int& size, int num) {
	for (int i = 0; i < num; i++) {
		insert_order(arr, size, rand() % 10 + 1);
	}
}

int main(int argc, char* argv[]) {
	srand(time(NULL));
	// int arr[MAX_SIZE];
	// int size = 0;

	// populate_rand(arr, size, 7);

	// print(arr, size);

	// int input;
	// cin >> input;

	// remove_element(arr, input, size);
	// remove_at(arr, size, input);

	// create two arrays, and test the merge function

	int arr1[MAX_SIZE];
	int size1 = 0;
	int arr2[MAX_SIZE];
	int size2 = 0;
	int arr3[MAX_SIZE];
	int size3 = 0;

	populate_rand(arr1, size1, 3);
	populate_rand(arr2, size2, 4);

	print(arr1, size1);
	std::cout << std::endl;

	print(arr2, size2);
	std::cout << std::endl;

	merge_order(arr1, size1, arr2, size2, arr3, size3);

	print(arr3, size3);
	std::cout << std::endl;

	int input;
	cin >> input;

	int index = binary_search(arr3, size3, input);
	std::cout << index << std::endl;
	// std::cout << arr3[index] << std::endl;

	return 0;
}
