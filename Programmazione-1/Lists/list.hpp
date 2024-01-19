#pragma once

namespace list {

struct Node {
	data c_data;
	Node* next;
};

typedef Node* List;

void init(List&);
void deinit(List&);
int length(List);
void print_data(const data& data);
int compare_data(const data& data1, const data& data2);
void print(List);
void insert_first(List&, data);
void insert_last(List&, data);
void insert_at(List&, data, int index);
void insert_order(List&, data);
void remove_first(List&);
void remove_last(List&);
void remove_at(List&, int index);
void remove_element(List&, data);
List reverse(List);
List reverse_copy(List);
List find_node(List, int);
List prev_node(List, List);
List copy(List);
List concat(List, List);
List concat_copy(List, List);

} // namespace list
