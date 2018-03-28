/*
 * exercise_9.cpp
 *
 *  Created on: Mar 20, 2018
 *      Author: napoleon
 *  Exercise №9 from lab 2.
 */

#include <iostream>
#include <stdlib.h>
#include "binary.hpp"
using namespace std;

int main() {
	btree tree; // defining tree
  int N = 100; // number of nodes
	tree.root = tree.insert(rand()%N, tree.root); // defining root
	node *root = tree.root;

	// initializing tree nodes with some values
  for(int i = 0; i < N; i++) {
  	tree.insert(rand()%N, root);
  }

	// assigning the attributes
	tree.make_attributes(root, 0);

	// results
	tree.inorder(root);

	return 0;
}
