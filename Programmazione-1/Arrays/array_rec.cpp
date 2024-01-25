#include <iostream>
#include "array.hpp"

namespace arr {

void print(array arr, int size) {
	if (!size)
		return;

	size--;
	print(arr, size);
	print_data(arr[size]);
}

static int remove_element_helper(array arr, const data& data, int size, int index, int new_size) {
	if (index == size)
		return new_size;

	if (compare_data(arr[index], data)) {
		arr[new_size] = arr[index];
		new_size++;
	}

	return remove_element_helper(arr, data, size, index + 1, new_size);
}

void remove_element(array arr, const data& data, int& size) { size = remove_element_helper(arr, data, size, 0, 0); }

static void insert_order_helper(array arr, int& size, const data& data, int index) {
	if (!index || data > arr[index - 1]) {
		arr[index] = data;
		return;
	}

	arr[index] = arr[index - 1];

	insert_order_helper(arr, size, data, index - 1);
}

void insert_order(array arr, int& size, const data& data) {
	if (size == MAX_SIZE)
		return;

	insert_order_helper(arr, size, data, size);
	size++;
}

void remove_at(array arr, int& size, int index) {
	if (index >= size || index < 0)
		return;

	if (index == size - 1) {
		size--;
		return;
	}

	arr[index] = arr[index + 1];
	remove_at(arr, size, index + 1);
}

void merge(const array arr1, int size1, const array arr2, int size2, array arr, int& size) {
	if (size1 + size2 > MAX_SIZE)
		return;

	if (size == size1 + size2)
		return;

	if (size < size1) {
		arr[size] = arr1[size];
		size++;
		merge(arr1, size1, arr2, size2, arr, size);
		return;
	}

	arr[size] = arr2[size - size1];
	size++;
	merge(arr1, size1, arr2, size2, arr, size);
}

void merge_order(const array arr1, int size1, const array arr2, int size2, array arr, int& size) {
	if (size1 + size2 > MAX_SIZE)
		return;

	if (size == size1 + size2)
		return;

	if (size < size1) {
		insert_order(arr, size, arr1[size]);
		merge_order(arr1, size1, arr2, size2, arr, size);
		return;
	}

	insert_order(arr, size, arr2[size - size1]);
	merge_order(arr1, size1, arr2, size2, arr, size);
}

void reverse_helper(array arr, int high, int low) {
	if (low > high)
		return;

	data tmp = arr[high];
	arr[high] = arr[low];
	arr[low] = tmp;

	reverse_helper(arr, high - 1, low + 1);
}

void reverse(array arr, int size) { reverse_helper(arr, size - 1, 0); }

int linear_search(const array arr, int size, data element) {
	if (!size || arr[size - 1] == element)
		return size - 1;

	return linear_search(arr, size - 1, element);
}

int binary_search_helper(const array arr, int low, int high, data element) {
	if (low > high)
		return -1;

	int mid = (low + high) / 2;

	if (element == arr[mid])
		return mid;
	else if (element < arr[mid])
		return binary_search_helper(arr, low, mid - 1, element);
	else
		return binary_search_helper(arr, mid + 1, high, element);
}

int binary_search(const array arr, int size, data element) { return binary_search_helper(arr, 0, size - 1, element); }

} // namespace arr
