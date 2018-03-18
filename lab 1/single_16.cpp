#include <iostream>
#include <stdlib.h>
using namespace std;

struct node {
	int data;
	node *next;
};
#include "single.hpp"

int main() {
  	//EX 16
		cout <<endl << "EX -- 16"<<endl;
		list list1, list2; //defining lists
		int total = 20; // total lottery participants
		int total_winners = 7;// total prizez == total winners
		int k = 3;// every k-th wins the prize
		for(int i = 1; i <= total; i++) { // initializing the list with some values
			list1.createnode(i);
			list2.createnode(i);
		}
		list1.to_loop(); // making list1 looped
		list2.to_loop(); // making list2 looped
		list winners; // making list of winners
		node *temp = list1.get_head();
		for(int i = 0; i < total_winners; i++) {
			int count = 0;
			while(count != k) { // looping through participants and find every k-th
				temp = temp->next;
				count++;
			}
			winners.createnode(temp->data); // adding a winner
		}
		cout << endl <<"Displaying winners " << endl;
		winners.display();
    return 0;
}
