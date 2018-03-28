#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <vector>
#include "tree.hpp"
using namespace std;

btree::btree() {
	root = NULL;
}

node* btree::insert(int value, node *leaf) {
	if(leaf == NULL) {
		node *temp = new node;
		temp->value = value;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}

	if(value < leaf->value) {
		leaf->left = insert(value, leaf->left);
	} else if (value > leaf->value) {
		leaf->right = insert(value,leaf->right);
	}
	return leaf;
}

void btree::inorder(node *root) {
	if(root != NULL) {
		inorder(root->left);
		cout << root->value <<endl;
		inorder(root->right);
	}
}

vector<node*> btree::to_vector(node *root) {
	vector<node*> res,res1,res2;
	if(root != NULL) {
		res.push_back(root);
		res1 = to_vector(root->left);
		res2 = to_vector(root->right);
		res.insert(res.end(),res1.begin(),res1.end());
		res.insert(res.end(),res2.begin(),res2.end());
	}
	return res;
}

void btree::randomize() {
	//srand(time(NULL));
	root = new node;
	root->value = rand()%198-99;
	int k = 14;
	for(int i = 0; i < k; i++) {
		insert(rand()%198-99,root);
	}
	cout << "Tree created :" << endl;
	inorder(root);
}

node* btree::search(node* root, int value) {
	if(root == NULL || root->value == value) {
		return root;
	}
	if(value > root->value) {
		return search(root->right, value);
	}
	return search(root->left,value);
}

node* btree::most_left(node *root) {
	if(root == NULL)
		return NULL;

	while(root->right != NULL) {
		root = root->right;
	}
	return root;
}

node* btree::delete_node(node *root, int value) {// rewrite!
	if(root==NULL) return root;
	else if(value<root->value)
		root->left = delete_node(root->left, value);
	else if (value> root->value)
		root->right = delete_node(root->right, value);
	else { //No child
		if(root->right == NULL && root->left == NULL) {
			delete root;
	        root = NULL;
	    } //One child
	    else if(root->right == NULL) {
	    	node* temp = root;
	        root= root->left;
	        delete temp;
	    }
	    else if(root->left == NULL) {
	    	node* temp = root;
	        root= root->right;
	        delete temp;
	    } //two child
	    else {
	    	node* temp = most_left(root->left);
	        root->value = temp->value;
	        root->left = delete_node(root->left, temp->value);
	    }
	}
	return root;
}

vector<node*> btree::search_nodes(node* root, bool (*condition)(int)) {
	vector<node*> found,vector_first,vector_second;
	if(root != NULL) {
		if((*condition)(root->value)){
			found.push_back(root);
			cout << found[found.size()-1]->value << "-VALUE-";
		}
		if(root->left != NULL) {
			vector_first = search_nodes(root->left, condition);
			found.insert(found.end(),vector_first.begin(),vector_first.end());
		}
		if(root->right != NULL) {
			vector_second = search_nodes(root->right, condition);
			found.insert(found.end(),vector_second.begin(),vector_second.end());
		}
	}
	return found;
}

void btree::delete_nodes(node *root, bool (*condition)(int)) {
	vector<node*> all_nodes; // all nodes
	vector<int> found_numbers; // values that fit to condition
	all_nodes = to_vector(root);
	for(unsigned int i = 0; i < all_nodes.size(); i++) {
		if((*condition)(all_nodes[i]->value)) {
			found_numbers.push_back(all_nodes[i]->value);
		}
	}
	for(unsigned int i = 0; i < found_numbers.size(); i++) {
		delete_node(root,found_numbers[i]); // deleting nodes
	}
}
