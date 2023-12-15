#include "../../lists.hpp"
#include <iostream>

namespace list {

void print_node(const data& data) { std::cout << "a: " << data.a << ", b: " << data.b; }
int compare(const data& data1, const data& data2) { return data1.a - data2.a; }

} // namespace list
