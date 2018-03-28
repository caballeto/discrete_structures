#include <iostream>
#include "binary.hpp"
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
		cout << root->value << "  " << root->b <<endl;
		inorder(root->right);
	}
}

void btree::make_attributes(node *root, int i) {
    if(root != NULL) {
        if(i == 0) {
            root->b = 'K';// корень
            i += 1;
            make_attributes(root->right, i);
            make_attributes(root->left, i);
        } else {
           if(root->left != NULL || root->right != NULL) {
                root->b = 'P'; // промежуточная
                make_attributes(root->right, i);
                make_attributes(root->left, i);
            } else {
                root->b = 'L'; // листок
                return;
            }
        }

    }
}

