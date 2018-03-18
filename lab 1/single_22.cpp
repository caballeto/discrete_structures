#include <iostream>
#include <stdlib.h>
using namespace std;

struct node {
	int data;
	node *next;
};
#include "single.hpp"

int main() {
 	// EX 22
	cout <<endl << "EX -- 22"<<endl;
	list list1, list2;
	int killed = 3; // number of killed
	int team_num = 8; // total number in team
	for(int i = 1; i <= team_num; i++) {
		list1.createnode(i*10);
		list2.createnode(i);
	}
  
	cout <<endl << "Start teams:"<<endl; // displaying start lists
	list1.display();
	cout << endl;
	list2.display();
  
	for(int i = 1; i <= killed; i++) { // killing from first team
		list1.delete_first();
	}
	for(int i = 1; i <= killed;i++) {// add members from second team
		list1.createnode(list2.get_head()->data);
		list2.delete_first();
	}
	//results
	cout <<endl << "EX -- 22 results:"<<endl;
	list1.display(); 
    	return 0;
}
