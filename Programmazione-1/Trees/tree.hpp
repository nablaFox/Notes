#pragma once

namespace tree {

enum result { OK, FAIL };

struct Node {
	data c_data;
	Node* left;
	Node* right;
};

typedef Node* Tree;

void init(Tree&);
void deinit(Tree&);
void print(const Tree&);
void print_data(const data&);
int compare_data(const data&, const data&);
void print_vertical(const Tree&);
result insert(Tree&, data);
Tree find_node(const Tree&, const data&);

} // namespace tree
