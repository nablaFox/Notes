#include "tree.hpp"
#include <cmath>
#include <iostream>
#include <math.h>

using namespace std;

static bool empty(const tree::Tree& tree) { return tree == nullptr; }

static tree::Tree create_node(tree::data data, tree::Tree left, tree::Tree right) {
	tree::Tree new_node = new (std::nothrow) tree::Node;
	new_node->c_data = data;
	new_node->left = left;
	new_node->right = right;

	return new_node;
}

static tree::Tree create_node(tree::data data) { return create_node(data, nullptr, nullptr); }

namespace tree {

void init(Tree& tree) { tree = nullptr; }

void deinit(Tree& tree) {
	if (!empty(tree)) {
		deinit(tree->left);
		deinit(tree->right);
		delete tree;
	}
}

void print(const Tree& tree) {
	if (!empty(tree)) {
		print(tree->left);
		print_data(tree->c_data);
		print(tree->right);
	}
}

void print_vertical(const Tree& tree) { return; };

result insert(Tree& tree, data data) {
	if (empty(tree)) {
		Tree new_node = create_node(data);
		if (empty(new_node))
			return FAIL;
		tree = new_node;
		return OK;
	}

	if (compare_data(data, tree->c_data) > 0)
		return insert(tree->right, data);
	else
		return insert(tree->left, data);
}

Tree find_node(const Tree& tree, const data& data) {
	if (empty(tree) || compare_data(data, tree->c_data) == 0)
		return tree;

	if (compare_data(data, tree->c_data) > 0)
		return find_node(tree->right, data);
	else
		return find_node(tree->left, data);
}

} // namespace tree
