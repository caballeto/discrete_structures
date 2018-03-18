#include "single.hpp"

// EX 1 move element from pos to pos + n
void list::move_element(int pos, int n) {
	node *prev = new node;
	node *current = new node;
	current = head;
	if(pos == 0) {
		head = current->next;
		(*this).insert_position_before(n+1, current->data);
	} else {
		for(int i = 0; i < pos; i++) {
			prev = current;
			current = current->next;
		}
		prev->next = current->next;
		(*this).insert_position_before(pos + n + 1, current->data);
	}
}

// EX 2 returns a copy of the lists
list list::copy() {
	list copied;
	node *temp=new node;
	temp=head;
	while(temp!=NULL) {
	  copied.createnode(temp->data);
	  temp=temp->next;
	}
	return copied;
}

// EX 3 insert an element at the start of the list
void list::insert_start(int value) {
  node *temp=new node;
  temp->data=value;
  temp->next=head;
  head=temp;
}

// EX 4 concat two lists
void list::concat_list(node *current, node *b) {
	if(current != NULL && b != NULL) {
		if(current->next == NULL)
			current->next = b;
		else
			concat_list(current->next,b);
	}
}

// EX 5 delete element at position pos
void list::delete_position(int pos) {
  node *current=new node;
  node *previous=new node;
  current=head;
  for(int i=1;i<pos;i++)
  {
    previous=current;
    current=current->next;
  }
  previous->next=current->next;
}

// EX 6 insert element after position pos
void list::insert_position_after(int pos, int value) {
  node *pre=new node;
  node *cur=new node;
  node *temp=new node;
  cur=head;
  for(int i=1;i<pos;i++) {
    pre=cur;
    cur=cur->next;
  }
  pre = pre->next;
  cur = cur->next;
  temp->data=value;
  pre->next=temp;
  temp->next=cur;
}

// EX 7 makes an intersection of two given lists 
list list::intersection(node *current1, node *current2) {
	list intersected;
	node *temp = new node;
	temp = current2;
	while (current1 != NULL) {
		while (current2 != NULL) {
			if(current1->data == current2->data) {
				intersected.createnode(current1->data);
			}
			current2 = current2->next;
		}
		current2 = temp;
		current1 = current1->next;
	}
	return intersected;
}

// EX 8 sort elements of ist in increasing order
void list::sort_increasing() {
	node * current = head;
	int temp_data;
	int counter = 0;
	while (current) {  // getting length of the list 
		current = current->next;
		counter++;
	}
	current = head;

	for (int j=0; j<counter; j++) { // buuble sorting the list  O(n^2)
		while (current->next != NULL) {
			if (current->data > current->next->data) {
				temp_data = current->data;
				current->data = current->next->data;
				current->next->data = temp_data;
				current = current->next;
			}
			else
				current = current->next;
		}
		current = head;
	}
}

// EX 9 delete every second element in list
void list::delete_every_second() {
	if(head == NULL)
		cout << "list is empty" << endl;
	node *current = head;
	node *prev = NULL;
	int count = 0;
	while(current != NULL) {
	 	count++;
		if(count == 2){
			prev->next = current->next;
			count = 0;
		}
		if(count != 0)
			prev = current;
		current = prev->next;
	}
}

// EX 10 
void list::delete_every_third() { // deleting every third element
	if(head == NULL)
		cout << "list is empty" << endl;
	node *current = head;
	node *prev = NULL;
	int count = 0;
	while(current != NULL) {
		count++;
		if(count == 3){
			prev->next = current->next;
			count = 0;
		}
		if(count != 0)
			prev = current;
		current = prev->next;
	}
}

// EX 11 sort in decreasing order
void list::sort_decreasing() {
	node * current = head;
		int temp_data;
		int counter = 0;
		while (current) { // getting length of the list
			current = current->next;
			counter++;
		}
		current = head;

		for (int j=0; j<counter; j++) {  // buuble sorting the list  O(n^2)
			while (current->next != NULL) {
				if (current->data < current->next->data) {
					temp_data = current->data;
					current->data = current->next->data;
					current->next->data = temp_data;
					current = current->next;
				}
				else
					current = current->next;
			}
			current = head;
		}
}

// EX 12 erase list
void list::erase() {
	node *current = head;
	node *next;
	while (current != NULL) {
	   next = current->next;
	   free(current);
	   current = next;
	}
	head = NULL;
}

// get the number of elements in list
int list::length() {
	node * current = head;
	int count = 0;
	while (current) { // getting length of the list
		current = current->next;
		count++;
	}
	return count;
}

// making the list of the loop
void list::to_loop() {
	node *temp = head;
	node *join = temp;
	while(temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = join;
}

void list::delete_every_k(int k) {
	if(head == NULL)
		cout << "list is empty" << endl;
	node *current = head;
	node *prev = NULL;
	int count = 0;
	while(current != NULL) {
		count++;
		if(count == k){
			prev->next = current->next;
			count = 0;
		}
		if(count != 0)
			prev = current;
		current = prev->next;
	}
}

// return the head node of the list
node* list::get_head() {
	return head;
}

// return the tail node of the list
node* list::get_tail() {
	return tail;
}

// add element to the end of the list
void list::createnode(int value) {
  node *temp=new node;
  temp->data=value;
  temp->next=NULL;
  if(head==NULL) {
    head=temp;
    tail=temp;
    temp=NULL;
  }
  else {
    tail->next=temp;
    tail=temp;
  }
}

// display the elements of the list
void list::display() {
  node *temp=new node;
  temp=head;
  while(temp!=NULL) {
    cout<<temp->data<<"\t";
    temp=temp->next;
  }
}

// insert element before position pos
void list::insert_position_before(int pos, int value) {
  node *pre=new node;
  node *cur=new node;
  node *temp=new node;
  cur=head;
  for(int i=1;i<pos;i++) {
    pre=cur;
    cur=cur->next;
  }
  temp->data=value;
  pre->next=temp;
  temp->next=cur;
}

void list::delete_first() {
  node *temp=new node;
  temp=head;
  head=head->next;
  delete temp;
}

void list::delete_last() {
  node *current=new node;
  node *previous=new node;
  current=head;
  while(current->next!=NULL) {
    previous=current;
    current=current->next;
  }
  tail=previous;
  previous->next=NULL;
  delete current;	
}
