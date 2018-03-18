#include <iostream>
#include <stdlib.h>
using namespace std;

struct node {
	int data;
	node *next;
};
#include "single.hpp"


int main() {
    	// EX 20
	cout <<endl << "EX -- 20"<<endl;
	list list1, list2;
	int total = 20;//  total number of products
	for(int i = 1; i <= total; i++) { // initializing two lists with some values
		list1.createnode(i+2);
		list2.createnode(i);
	}
	list made_both; // result list
	made_both = list1.intersection(list1.get_head(), list2.get_head()); // finding the intersection of 2 lists
  
    	// results
	cout << endl <<"EX 20 result: " << endl;
	list1.display();
	cout << endl;
	list2.display();
	cout << endl;
	made_both.display(); // made by both
    	return 0;
}
