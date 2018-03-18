#include <iostream>
#include <string>
#include <stdlib.h>

struct node {
	int data;
	node *next;
};
#include "single.hpp"
using namespace std;


int main() {
 	// EX 13
	cout <<endl << "EX -- 13"<<endl;
	int size = 20;
	list football_names; // defining list of football players
	for(int i = 1; i <= size; i++) { // initializing list with some values
		football_names.createnode(i);
	}
	football_names.display(); // displaying the results
	list team1 = football_names.copy(); //making copy of the first list
	list team2 = football_names.copy(); // making copy of the second list
  
	team1.delete_every_second(); // from list 1 deleting every second - team 1 is ready
	team2.insert_start(0); // inserting 1 element at start 
	team2.delete_every_second(); // from list 2 delete every second
	team2.delete_first(); // deleting the element 0 from list 2 - team 2 is ready
	
	// results :
	cout <<endl << "EX -- 13 results:"<<endl;
	cout << "Team 1:" << endl;
	team1.display();
	cout << endl <<"Team 2:" << endl;
	team2.display();
	cout<<endl; 
    	return 0;
}
