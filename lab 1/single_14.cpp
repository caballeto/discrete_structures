#include <iostream>
#include <string>
#include <stdlib.h>
#include "single.hpp"
using namespace std;
list lot(list, int);

struct node {
	int data;
	node *next;
};

int main() {
   	 // EX
	cout <<endl << "EX -- 14"<<endl;
	list team1, team2, new_team1, new_team2; // creating lists
	int size = 10; // size of the lists
	for(int i = 1; i <= size; i++) { // initializing the lists with some values
		team1.createnode(i);
		team2.createnode(i);
	}
	ex14_ = team1.copy();
  
	int n = 4;// assign n
	int m = 5;// assign m
	new_team1 = lot(team1,n);
    	new_team2 = lot(team2,m);
    
    	// results
   	cout << "Team 1:" << endl;
	new_team1.display();
	cout << endl <<"Team 2:" << endl;
	new_team2.display();
	return 0;
}

list lot(list x,int n) {
  list new_l;
  node *current = x.get_head();
	int count = 0;
	while(current != NULL)
	{
		count++;
		if(count == n){
			new_l.createnode(current->data);
			count = 0;
		}
		current = current->next;
	}
  return new_l;
}
