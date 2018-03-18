#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

struct node {
	int data;
	node *next;
  string made_by;
};
#include "single.hpp"


int main() {
  	//EX 18
	list all; // list of all products
	
	//list determination
	all.createnode(5);
	all.createnode(5);
	all.createnode(9);
	all.createnode(4);
	all.createnode(3);
	all.createnode(7);
	node *current = new node;
	current = all.get_head();
	current->made_by = "SONY";
	current->next->made_by = "SONY";
	current->next->next->made_by = "MICROSOFT";
	current->next->next->next->made_by = "APPLE";
	current->next->next->next->next->made_by = "MICROSOFT";
	current->next->next->next->next->next->made_by = "SONY";
	
	//main
	list only_sony;
	for(int i = 0; i < all.length(); i++) {
		if(current->made_by == "SONY") {
			only_sony.createnode(current->data);
		}
		current = current->next;
	}
  
	//results
	cout << endl <<"EX 18 result: " << endl;
	all.display();
	cout << endl<< "ONLY SONY" << endl;
	only_sony.display();
	return 0;
}
