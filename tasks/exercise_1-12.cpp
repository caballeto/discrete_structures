#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "tree.hpp"
using namespace std;

btree starter();

int main() {
  	// initializing tree with random elementsfrom -99 to 99
	btree tree = starter();
  
  	cout << "SEARCHING NODEs" << endl;
	vector<node*> found = tree.search_nodes(tree.root,condition_1);
 	cout << "Next nodes were found: " << endl;
	for(int i = 0; i < found.size(); i++) {
   	cout << found[i] << " "; 
  	}
  
  	cout << "DELETING NODEs" << endl;
	tree.delete_nodes(tree.root,condition_1);
	tree.inorder(tree.root);
}

btree starter() {
	btree tree;
	int element;
	string choice;
	cout << "Do you want to enter the tree elements?[Y/n] :";
	cin >> choice;
	while(choice != "Y") {
		if(choice == "n") break;
		cout << "Invalid input. Please try again." << endl;
		cin >> choice;
	}
	if(choice == "Y") {
		int i = 1;
		cout << "Element 1" << endl;
		while(cin >> element && i != 15) {
			cout << "Element " << i+1 << endl;
			tree.insert(element,tree.root);
			i += 1;
		}
		cout << "List created." << endl;
	} else if(choice == "n") {
		tree.randomize();// randomizing
	}
	return tree;
}
