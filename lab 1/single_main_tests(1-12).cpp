#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

struct node {
	int data;
	node *next;
};
#include "single.hpp"

int main() {
 	  // initializing list
		list some_list;
		cout<< "Start list\n";
    // adding elements to list
		some_list.createnode(25);
		some_list.createnode(50);
		some_list.createnode(75);
		some_list.createnode(100);
		some_list.createnode(125);
		some_list.display();
		cout << "\n";
  
    // EX 1
		some_list.move_element(0,4); // move element 0 4 positions right
		// moving element for 4 positions
		cout<< "Moving from pos 0 to pos 4\n";
		some_list.display();
		cout << "\n";
  
		// EX 2 copying the list
		cout << "Original\n";
		some_list.display();
		list copy_of_first = some_list.copy(); // making copied list
		cout << "\n";
		cout<<"Display copied \n";
		copy_of_first.display();
  
		// EX 3 adding to the start of list
		cout <<"\nInserting to the start\n";
		some_list.insert_start(1000);
		some_list.display();
		cout << "\n";
  
		// EX 4 concat lists
		some_list.concat_list(some_list.get_head(),copy_of_first.get_head());// concatenating 2 lists
		cout<<"Display concatenated" << endl;
		some_list.display();
    
    // EX 5 deleting element n
		cout<<"deleting element n"<< endl;
		some_list.delete_position(2);
		some_list.display();
  
    // EX 6 insert element after element n
		cout<<endl <<"Inserting after element pos"<< endl;
		some_list.insert_position_after(3,10);
		some_list.display();
    
		// EX 7 intersection of lists
		list lst1, lst2; // defining two lists
		lst1.createnode(1); // initializing list 1
		lst1.createnode(2);
		lst1.createnode(5);
		lst2.createnode(6); // intializing list 2
		lst2.createnode(1);
		lst2.createnode(5);
		lst2.createnode(100);
    // displaying list
		cout<<endl <<"New list 1"<< endl;
		lst1.display();
		cout<<endl <<"New list 2"<< endl;
		lst2.display();
		list intersection = lst1.intersection(lst1.get_head(), lst2.get_head()); // making intersection
		cout<<endl <<"Intersection"<< endl;
		intersection.display();
    
    // EX 8 sort in increasing order
		cout<<endl <<"Sort in increasing order"<< endl;
		lst2.sort_increasing(); // sorting in increasing order
		lst2.display();
    
    // EX 9 deleting every second element in the list
		cout<<endl <<"Delete every second"<< endl;
		lst2.createnode(150); // adding some elements to the list
		lst2.createnode(151);
		lst2.display();
		cout << endl;
		lst2.delete_every_second(); // deleting
		lst2.display();
    
    // EX 10 deleting every third element in the list
		cout<<endl <<"Delete every third"<< endl;
		lst1.createnode(110); // adding some elements to the list
		lst1.createnode(120);
		lst1.createnode(130);
		lst1.display();
		lst1.delete_every_third(); // deleting
		cout << endl;
		lst1.display();
  
    // EX 11 sort in decreasing order
		cout<<endl <<"Sort in decreasing order"<< endl;
		lst1.sort_decreasing(); // sorting
		lst1.display();
  
    // EX 12 erasing list
		cout<<endl <<"Erase list"<< endl;
		lst1.erase(); // erasing
		lst1.display(); // list erased so no info displayed
		cout << endl;
		lst1.createnode(10); // showing that list is still working
		lst1.display();
		cout << endl;
		return 0; 
}
