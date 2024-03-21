#include <iostream>
#include "custom_data.hpp"

int compare_data(const Custom& data1, const Custom& data2) { return data1.a - data2.a; }
void print_data(const Custom& data) { std::cout << data.a << " " << data.b; }

int list::compare_data(const list::data& a, const list::data& b) { return ::compare_data(a, b); }
void list::print_data(const list::data& a) { ::print_data(a); }

void stack::print_data(const stack::data& a) { ::print_data(a); }

void queue::print_data(const queue::data& a) { ::print_data(a); }
