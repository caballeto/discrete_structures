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
    // EX 15
 		cout <<endl << "EX -- 15";
		list _list; // defining the list
		int war_num =10; // number of warriors
		int every_m = 3; // they kill every m
		for(int i = 1; i <= war_num; i++) { // initialize list with some values
			_list.createnode(i);
		}
		_list.to_loop();// make list looped
	
		node *temp1 = _list.get_head();
		node *temp2 = _list.get_head();
		while(temp1->next != temp1)
		{
			int count = 1;
			while(count != every_m)
			{
				temp2 = temp1;
				temp1 = temp1->next;
				count++;
			}
		  temp2->next = temp1->next; // deleting every m
			temp1 = temp2->next; // going further
		}
		cout << endl << temp1->data << endl;  // the last warrior
    return 0;
}
