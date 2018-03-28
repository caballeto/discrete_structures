#include <vector>

struct node {
	int value;
	node *left;
	node *right;
};

// condition functions
bool condition_1(int);
bool condition_2(int);
bool condition_3(int);
bool condition_4(int);
bool condition_5(int); // EDIT!
bool condition_6(int);
bool condition_7(int);
bool condition_8(int);
bool condition_9(int);
bool condition_10(int);
bool condition_11(int);
bool condition_12(double);

// binary tree realization
class btree {
	public:
	    node *root;
		btree();
		void randomize(); // creates 15 random elements from -99 to 99
		node* insert(int, node*); // inserting element with value
		void inorder(node*); // prints the tree
		node* most_left(node*);
		node* search(node*, int); // returning the found node with value
		node* delete_node(node*, int);// deletes node from tree
		std::vector<node*> search_nodes(node*, bool (*condition)(int));// search all elements which pass the condition
		void delete_nodes(node*, bool (*condition)(int));
		std::vector<node*> to_vector(node*);
};

