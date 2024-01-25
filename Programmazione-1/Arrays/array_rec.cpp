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

void merge_helper(const array arr1, int size1, const array arr2, int size2, array arr, int index) {
	if (index == size1 + size2)
		return;

	if (index < size1) {
		arr[index] = arr1[index];
		index++;
		merge_helper(arr1, size1, arr2, size2, arr, index);
		return;
	}

	arr[index] = arr2[index - size1];
	index++;
	merge_helper(arr1, size1, arr2, size2, arr, index);
}

void merge(const array arr1, int size1, const array arr2, int size2, array arr) {
	if (size1 + size2 > MAX_SIZE)
		return;

	merge_helper(arr1, size1, arr2, size2, arr, 0);
}

void merge_order_helper(const array arr1, int size1, const array arr2, int size2, array arr, int index) {
	if (index == size1 + size2)
		return;

	if (index < size1) {
		insert_order(arr, index, arr1[index]);
		merge_order_helper(arr1, size1, arr2, size2, arr, index);
		return;
	}

	insert_order(arr, index, arr2[index - size1]);
	merge_order_helper(arr1, size1, arr2, size2, arr, index);
}

void merge_order(const array arr1, int size1, const array arr2, int size2, array arr) {
	if (size1 + size2 > MAX_SIZE)
		return;

	merge_order_helper(arr1, size1, arr2, size2, arr, 0);
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
	if (!size || !compare_data(arr[size], element))
		return size - 1;

	return linear_search(arr, size - 1, element);
}

int binary_search_helper(const array arr, int low, int high, data element) {
	if (low > high)
		return -1;

	int mid = (low + high) / 2;

	if (!compare_data(arr[mid], element))
		return mid;
	else if (compare_data(arr[mid], element) > 0)
		return binary_search_helper(arr, low, mid - 1, element);
	else
		return binary_search_helper(arr, mid + 1, high, element);
}

int binary_search(const array arr, int size, data element) { return binary_search_helper(arr, 0, size - 1, element); }

} // namespace arr
