#include <iostream>
#include <stdlib.h>
using namespace std;

struct node {
  int data;
  node *next;
};
#include "single.hpp"


int main() {
	//EX 19
	cout <<endl << "EX -- 19"<<endl;
	list list1, list2;
	int L = 3;// number move from list 2 to list 1
	int k = 6;// number of elements in lists
	for(int i = 1; i <= k; i++) {
		list1.createnode(i);
		list2.createnode(i);
	}
	
	//main
	for(int i = 1; i <= L;i++) {
		list1.createnode(list2.get_head()->data); // add first element of list 2 to the end to of list 1
		list2.delete_first();// delete first element of list 2
	}
  
	//results
	cout << endl <<"EX 19 result: list - 2" << endl;
	list2.display();
	cout << endl<< "list - 1" << endl;
	list1.display();
  	return 0;
}
