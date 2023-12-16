#pragma once

namespace list {

struct node {
	data c_data;
	node* next;
};

void init(node*&);
void deinit(node*&);
int length(node*);
void print_node(const data& data);
int compare(const data& data1, const data& data2);
void print(node*);
void insert_first(node*&, data);
void insert_last(node*&, data);
void insert_at(node*&, data, int index);
void insert_order(node*&, data);
void remove_first(node*&);
void remove_last(node*&);
void remove_at(node*&, int index);
void remove_element(node*&, data);
node* reverse(node*);
node* reverse_copy(node*);
node* find_node(node*, int);
node* prev_node(node*, node*);
node* copy(node*);
node* concat(node*, node*);
node* concat_copy(node*, node*);

} // namespace list
