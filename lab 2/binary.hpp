struct node {
	int value;
	char b;
	node *left;
	node *right;
};

class btree {
	public:
		node *root;
		btree();
		node* insert(int, node*);
		void inorder(node*);
		void make_attributes(node*, int);
};
