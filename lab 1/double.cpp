double_list double_list::intersection(node *current1, node *current2) {
	double_list intersected;
	node *temp = new node;
	temp = current2;
	while (current1 != NULL)
	{
		while (current2 != NULL)
		{
			if(current1->data == current2->data)
			{
				intersected.createnode(current1->data);
			}
			current2 = current2->next;
		}
		current2 = temp;
		current1 = current1->next;
	}
	return intersected;
}
void double_list::to_loop() {
	node *temp = head;
	node *join = temp;
	while(temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = join;
	join->prev = temp;
}
double_list double_list::copy() {
	double_list copied;
	node *temp=new node;
	temp=head;
	while(temp!=NULL)
	{
	  copied.createnode(temp->data);
	  temp=temp->next;
	}
	return copied;
}

void double_list::erase() {
	node *current = head;
	node *next;
	while (current != NULL) {
	   next = current->next;
	   free(current);
	   current = next;
	}
	head = NULL;
	cout << endl << "List erased." << endl;
}

void double_list::delete_every_third() {
	if(head == NULL)
		cout << "list is empty" << endl;
	node *current = head;
	node *prev = NULL;
	int count = 0;
	while(current != NULL)
	{
		count++;
		if(count == 3){
			prev->next = current->next;
			if(current->next != NULL) {
				current->next->prev = prev;
			}
			count = 0;
		}
		if(count != 0)
			prev = current;
		current = prev->next;
	}
}

void double_list::delete_every_second() {
	if(head == NULL)
		cout << "list is empty" << endl;
	node *current = head;
	node *prev = NULL;
	int count = 0;
	while(current != NULL)
	{
		count++;
		if(count == 2){
			prev->next = current->next;
			if(current->next != NULL) {
				current->next->prev = prev;
			}
			count = 0;
		}
		if(count != 0)
			prev = current;
		current = prev->next;
	}
}
void double_list::delete_every_k(int k) {
	if(k == 1) {
		(*this).erase();
		return;
	}
	if(head == NULL)
		cout << "list is empty" << endl;
	node *current = head;
	node *prev = NULL;
	int count = 0;
	while(current != NULL)
	{
		count++;
		if(count == k){
			prev->next = current->next;
			if(current->next != NULL) {
				current->next->prev = prev;
			}
			count = 0;
		}
		if(count != 0)
			prev = current;
		current = prev->next;
	}
}

void double_list::delete_position(int pos) { // pos starts from 1
	if(pos == 1) {
		(*this).delete_first();
		return;
	}
	node *current=new node;
	node *previous=new node;
	current=head;
	for(int i=1;i<pos;i++) {
	  previous=current;
	  current=current->next;
	  if(current->next == NULL && i < pos-1) {
		  cout << "Wrong pos" << endl;
		  return;
	  }
	}
	if(current == tail) {
		(*this).delete_last();
		return;
	}
	current->next->prev = previous;
	previous->next=current->next;
	current->next = NULL;
	current->prev = NULL;
	delete current;
}
void double_list::delete_last() {
	node *current=new node;
	node *previous=new node;
	current=head;
	while(current->next!=NULL) {
	  previous=current;
	  current=current->next;
	}
	tail=previous;
	previous->next=NULL;
	current->prev=NULL;
	delete current;
}
void double_list::delete_first() {
	node *temp = head;
	temp->next->prev = NULL;
	head = head->next;
	temp->next = NULL;
	delete temp;
}

void double_list::insert_start(int value) {
	node* temp = new node;
	temp->data = value;
	temp->next = head;
	temp->prev = NULL;
	head->prev = temp;
	head = temp;
}

void double_list::insert_position_after(int pos, int value) {
    node *temp, *cur;
    cur = head;
    for (int i = 0;i <pos-1;i++) {
        cur=cur->next;
        if (cur == NULL) {
            cout << endl << "Invalid pos" << endl;
            return;
        }
    }
    temp = new node;
    temp->data = value;
    if(cur->next == NULL) {
    	cur->next = temp;
    	temp->next = NULL;
    	temp->prev = cur;
    	tail = temp;
    } else {
    	temp->next =  cur->next;
    	cur->next->prev = temp;
    	cur->next = temp;
    	temp->prev = cur;
    }
}

int double_list::length() {
	node *current = head;
	int len = 0;
	while(current != NULL) {
		current = current->next;
		len++;
	}
	return len;
}
node* double_list::get_head() {
	return head;
}

node* double_list::get_tail() {
	return head;
}

void double_list::createnode(int value)
{
  node *temp=new node;
  temp->data=value;
  temp->next=NULL;
  if(head==NULL) {
	temp->prev=NULL;
    head=temp;
    tail=temp;
    temp=NULL;
  }
  else {
	node *temp1 = new node;
	temp1 = head;
	while(temp1->next != NULL) {
		temp1 = temp1->next;
	}
    temp1->next=temp;
    temp->prev=temp1;
    tail=temp;
  }
}

void double_list::display() {
	  node *temp=new node;
	  temp=head;
	  while(temp!=NULL)
	  {
	    cout<<temp->data<<"\t";
	    temp=temp->next;
	  }
}

void double_list::concat_list(node* current, node *b) {
	if(current != NULL && b != NULL) {
		if(current->next == NULL){
			current->next = b;
			b->prev = current;
		} else {
			concat_list(current->next,b);
		}
	}
}

