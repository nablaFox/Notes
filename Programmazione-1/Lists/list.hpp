#pragma once

namespace list {

struct Node {
	data c_data;
	Node* next;
};

void init(Node*&);
void deinit(Node*&);
int length(Node*);
void print_data(const data& data);
int compare_data(const data& data1, const data& data2);
void print(Node*);
void insert_first(Node*&, data);
void insert_last(Node*&, data);
void insert_at(Node*&, data, int index);
void insert_order(Node*&, data);
void remove_first(Node*&);
void remove_last(Node*&);
void remove_at(Node*&, int index);
void remove_element(Node*&, data);
Node* reverse(Node*);
Node* reverse_copy(Node*);
Node* find_node(Node*, int);
Node* prev_node(Node*, Node*);
Node* copy(Node*);
Node* concat(Node*, Node*);
Node* concat_copy(Node*, Node*);

} // namespace list
