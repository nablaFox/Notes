namespace list {

struct node {
	int data;
	node* next;
};

void init(node*&);
void deinit(node*&);
int length(node*);
void print(node*);
void insert_first(node*&, int);
void insert_last(node*&, int);
void insert_order(node*&, int);
void remove_first(node*&);
void remove_element(node*&, int);
node* reverse(node*);
node* reverse_copy(node*);
node* find_node(node*, int data);
node* prev_node(node*, node*);
node* copy(node*);
node* concat(node*, node*);
node* concat_copy(node*, node*);

} // namespace list
