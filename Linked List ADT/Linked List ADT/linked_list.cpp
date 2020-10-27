/* Linked List ADT implementation in C++*/


#include <iostream>

using namespace std;

/* Defining the class for Linked List ADT*/

template <typename T>
class List {
  public:
	// This method is used to access the contents of the Linked List in a manner similar to arrays i.e like a[0] to acces the first element using concept of operator overloading.
    T & operator[](unsigned index){
		ListNode *thru = head_;

		while (index > 0 && thru->next != nullptr) {
			thru = thru->next;
		    index--;
		}  

	  	return thru->data;
	}
 
	// This method is used to append data to the Linked List
	void append(T data){
		ListNode *node = new ListNode(data);
		node->next =  nullptr;
		ListNode * curr = head_;
		if(head_ == nullptr){
			head_ = node;
		}
		else{
			while(curr->next != nullptr){
				curr = curr->next;
			}
			curr->next = node;
		}

	}
	// This method is used to insert data into the front of the Linked List.
	void insertAtFront(T  data)  {
  		ListNode *node = new ListNode(data);
		node->next =  head_;
		head_ = node;
	}
	
	// This method will sort the Linked List
	
	void sort_list() {
		ListNode* curr = head_;
		ListNode* node2 = head_->next;
		while(curr != nullptr){
			node2 = curr->next;
			while(node2 != nullptr){
				if(curr->data > node2->data){
					T tmp;
					tmp = curr->data;
					curr->data = node2->data;
					node2->data = tmp;
				}
				node2 = node2->next;
			}
			curr = curr->next;
		}
		
	}


	// This method will check if the list is empty or not
	bool Empty_List(){
		if(head_ != nullptr)
			return true;
		else
			return false;
	}

	// This method will display the whole Linked LIst
	void display() {
		ListNode *thru = head_;

		while (thru != nullptr) {
			cout<<thru->data<<" ";
			thru = thru->next;
		}  
		cout<<"\n";	
	}


	//**** This method will merge two linked Lists
	List<T> *merge(List &L1) {
		int Lsize = this->len();
		int L1size = L1.len();
		int i = 0;
		while(i<L1size) {
			this->append(L1[i++]);
		}
		this->sort_list();

		return this;
	}

	// This method will retrun the length of the Linked List
	int len(){
		ListNode* curr = head_;
		int size = 0;
		while(curr != nullptr){
			size++;
			curr = curr->next;
		}
		return size;
	}

	// This method is used to insert a data value at any position of the linked list.
	void insert(const T & data, int pos) {
		ListNode *curr = head_;
		int size = 1;
		while(curr->next != nullptr){
			size++;
			curr= curr->next;
		}
		int i = 0;
		if(pos < 1 || pos > size + 1){
			cout<<"Invalid Position"<<endl;
		}
		else{	
			if(pos == 1){
				ListNode* newnode = new ListNode(data);
				newnode->next = head_;
				head_ = newnode;
			}
			else{
				pos = pos - 2;
				curr = head_;
				while(curr->next != nullptr){
					if(pos == 0){
						break;
					}
					curr = curr->next;
					pos --;
				}
				ListNode* newnode = new ListNode(data);
				newnode->next = curr->next;
				curr->next = newnode;
			}
		}
	}

	// This method is used to delete an element given the position.
	void delete_pos(int pos){
		ListNode* curr = head_;
		int i = 0;
		if(pos == 0){
			head_ = curr->next;
			free(curr);
			return;
		}
		pos--;

		for(i=0; curr!=NULL && i<pos-1; i++){
			curr = curr->next;
		}

		if(curr == NULL || curr->next == NULL)
			return;
		
		ListNode *next = curr->next->next;
		free(curr->next);
		curr->next = next;

	}

	// This method is used to delete an element given the data value.
	void delete_element(const T & data){
		ListNode* curr = head_;
		ListNode* prev = head_;
		if(curr->data == data){
			head_ = curr->next;
			free(curr);
			return;
		}
		curr = head_;
		while(curr != nullptr && curr->data != data){
			prev = curr;
			curr = curr->next;
		}
		if(curr != nullptr){
			prev->next = curr->next;
			free(curr);
		}
		else{
			cout<<"Data not fiund in Linked List"<<endl;
		}
	}
	
    // We define this constructor to make sure that head is null-initialized.
    List() : head_(nullptr) { }

    // We define a destructor to delete the memory allocated for the ListNode objects when the List is destroyed.
    ~List() {
      ListNode *thru = head_;
      while (thru != nullptr) {
        ListNode* toDelete = thru;
        thru = thru->next;
        delete toDelete;
		toDelete = nullptr;
      }
    }

  private:
	// Creating a Linked List Node as a Private Member of the class
    class ListNode {
      public:
        T  data; // Stores the data Value
        ListNode *next;	// Stores the next pointer.

		// Default parameterised Constructor of the node which accepts a data and stores it in the node and makes the next pointer point to nullptr.
        ListNode(const T & data) : data(data), next(nullptr) { }
    };

    ListNode *head_;   // Head pointer for our List 
    
 
};



int main() {
  	List<int> list1, list2;

  	cout<<"Checking if list1 is empty..."<<endl;
  	cout<<list1.Empty_List()<<endl;
	cout<<"Checking if List 2 is empty..."<<endl;
	cout<<list2.Empty_List()<<endl;

	cout<<"\nInserting elements into List 1..."<<endl;
	cout<<"Inserting the first 3 elements at the front of the list..."<<endl;
  	list1.insertAtFront(3);
  	list1.insertAtFront(23);
  	list1.insertAtFront(15);
	list1.display();
	cout<<"Appending the next 2 elements..."<<endl;
  	list1.append(87);
  	list1.append(34);
	list1.display();

	cout<<"\nInserting Elements into List 2..."<<endl;
	cout<<"Appending the first 3 elements into the list..."<<endl;
  	list2.append(75);
  	list2.append(9);
  	list2.append(28);
	list2.display();
	cout<<"Inserting the next 2 elements at the front of the list..."<<endl;
  	list2.insertAtFront(56);
  	list2.insertAtFront(34);
	list2.display();

	cout<<"\nInserting an Element 12 at position 2 in List1..."<<endl;
	list1.insert(12,2);
  	list1.display();

	cout<<"Inserting an Element 98 at position 4 in List2..."<<endl;
	list2.insert(98,4);
	list2.display();

	cout<<"\nDeleting element at position 4 List1..."<<endl;
	list1.delete_pos(4);
  	list1.display();

	cout<<"Deleting element at position 2 List2..."<<endl;
	list2.delete_pos(2);
	list2.display();

	cout<<"Deleting element 23 in List1..."<<endl;
	list1.delete_element(23);
	list1.display();
	cout<<"Deleting element 28 in List1..."<<endl;//For Data not found
	list1.delete_element(28);
	list1.display();
	cout<<"Deleting element 98 in List2..."<<endl;
	list2.delete_element(98);
	list1.display();

	cout<<"\nSorting the List1....."<<endl;
	list1.sort_list();
  	list1.display();
	cout<<"\nSorting the List2....."<<endl;
	list2.sort_list();
	list2.display();

	cout<<"\nMerging Linked List 1 and Linked List 2 into Linked List 1..."<<endl;
	list1.merge(list2);
	cout<<"\nDisplaying the Lists 1 and 2 after merging..."<<endl;
	cout<<"Linked List1..."<<endl;
	list1.display();
	cout<<"Linked List2..."<<endl;
	list2.display();

//    cout<<"\nSize of Linked List1..."<<endl<<list1.len()<<endl;
	cout<<"\nChecking if list is empty..."<<endl;
  	cout<<list1.Empty_List()<<endl;
  	return 0;
}
