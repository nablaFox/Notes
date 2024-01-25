#include <iostream>
#include "array.hpp"

static void swap(arr::data& a, arr::data& b) {
	arr::data tmp = a;
	a = b;
	b = tmp;
}

namespace arr {

void print(array arr, int size) {
	for (int i = 0; i < size; i++) {
		print_data(arr[i]);
	}
}

void remove_element(array arr, const data& data, int& size) {
	int new_size = 0;

	for (int i = 0; i < size; i++) {
		if (compare_data(arr[i], data)) {
			arr[new_size] = arr[i];
			new_size++;
		}
	}

	size = new_size;
};

void remove_at(array arr, int& size, int index) {
	if (index < 0 || index >= size)
		return;

	for (int i = index; i < size - 1; i++) {
		arr[i] = arr[i + 1];
	}

	size--;
}

void insert_order(array arr, int& size, const data& data) {
	if (size == MAX_SIZE)
		return;

	int index = 0;
	for (; index < size && data > arr[index]; index++)
		;

	for (int i = size; i > index; i--) {
		arr[i] = arr[i - 1];
	}

	arr[index] = data;
	size++;
}

void merge(const array arr1, int size1, const array arr2, int size2, array arr, int& size) {
	if (size1 + size2 > MAX_SIZE)
		return;

	for (int i = 0; i < size1; i++) {
		arr[i] = arr1[i];
	}

	for (int i = 0; i < size2; i++) {
		arr[size1 - 1 + i] = arr2[i];
	}

	size = size1 + size2;
}

void merge_order(const array arr1, int size1, const array arr2, int size2, array arr, int& size) {
	if (size1 + size2 > MAX_SIZE)
		return;

	for (int i = 0; i < size1; i++) {
		insert_order(arr, size, arr1[i]);
	}

	for (int i = 0; i < size2; i++) {
		insert_order(arr, size, arr2[i]);
	}
}

void reverse(array arr, int size) {
	int j = 0;

	for (int i = size - 1; i >= j; i--) {
		swap(arr[i], arr[j]);
		j++;
	}
}

int linear_search(const array arr, int size, data element) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == element)
			return i;
	}

	return -1;
}

int binary_search(const array arr, int size, data element) {
	int high = size - 1;
	int low = 0;

	while (low <= high) {
		int mid = (low + high) / 2;

		if (arr[mid] == element) {
			return mid;
		} else if (arr[mid] > element) {
			high = mid - 1;
		} else if (arr[mid] < element) {
			low = mid + 1;
		}
	}

	return -1;
}

} // namespace arr
