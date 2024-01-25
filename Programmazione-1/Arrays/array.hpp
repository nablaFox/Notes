#pragma once

#include "demo_data.hpp"

namespace arr {

typedef data* const array;

void print_data(const data&);
int compare_data(const data&, const data&);
double sum_data(const data&, const data&);

void print(array, int);
void remove_element(array, const data&, int&);
void remove_at(array, int&, int);
void insert_order(array, int&, const data&);
void merge(const array, int, const array, int, array);
void merge_order(const array, int, const array, int, array);
void reverse(array, int);

int binary_search(const array, int, data);
int linear_search(const array, int, data);

} // namespace arr
