class list // single list
{
	private:
		node *tail, *head;
	public:
	  list()
	  {
		  head=NULL;
		  tail=NULL;
	  }
	  node* get_head(); // returns the head of the list
	  node* get_tail(); // return the tail of the list
	  void createnode(int value);// add an element to the end of the list
	  void display(); // display the elements of the list
	  void insert_start(int value);// insert element at start
	  void insert_position_before(int pos, int value);//insert element before position pos with value
	  void insert_position_after(int pos, int value);
	  void delete_first();// delete the first element of list;
	  void delete_last();// delete last element of the list
	  void delete_position(int pos);// delete element on position pos
	  // the position of the first element is 1
	  void move_element(int pos, int n);//moves element from pos to pos + n
	  list copy(); // return the copy of the list
	  void concat_list(node *a, node *b); // add list with head node b to the end of list a
	  list intersection(node *a, node *b);// return the list - intersection of two lists
	  void sort_increasing();// sort in increasing order
	  void sort_decreasing();// sort in decreasing order
	  void delete_every_second(); // delete every second
	  void delete_every_third(); // delete every third
	  void delete_every_k(int); // delete every k-th element of the list
	  void erase();// delete all the elements of list
	  void to_loop();// make a list looped
	  int length();// return the length of the list
};
