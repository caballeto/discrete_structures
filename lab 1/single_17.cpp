#include <iostream>
#include <stdlib.h>
using namespace std;

struct node {
	int data;
	node *next;
};
#include "single.hpp"


int main() {
  	//EX 17
		list list1, list2, result;
		int k = 14; // number of students
		int e = 4; // number of tickets for exam
		for(int i = 1; i <= k; i++) {
			list1.createnode(i);
		}
		for(int i = 1; i <= e; i++) {
			list2.createnode(i);
		}
		list2.to_loop(); // making a loop in list2
    
    int count = 0;
    node *temp = list2.get_head();
    while(count != k) {ticket
      result.createnode(temp->data); // Result is a list: student on position i got ticket number i->data
      temp = temp->next;
      count++;
    }
  
	// results :
	cout <<endl << "EX -- 17 results:"<<endl;
	result.display();
  return 0;
}
