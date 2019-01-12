//Program of inserting, deleting and knowing in general about linked lists

#include<iostream>       //library header

using namespace std;     //namespace



class Node{
	public:
	// Data
	int data;
	// Ptr to the next Node
	Node *next;
	//Constructor that makes the ptr to NULL
	Node()
	{
		next = NULL;
		
	}	
};

class LinkedList{
	//Head + circles inside linked with each other
	public:
		
	//Head -> Node type ptr
	Node *head;
	Node *tail;   //not necessary but eases the process of insertion  
	
	//Constructor to make head to NULL
	LinkedList()
	{
		head = NULL;
		tail = NULL;
	}
	//Circles inside linked with each other
	//Rules how circles will be linked
	
	//Insert
	void insert(int value)        //user defined function that inserts node at the last 
	{
		//If 1st node is added
		Node *temp = new Node;  //Node object created in heap whose address is stored in temp pointer (temp is present in stack and the node is in the heap)
		                        //Basically creates a circle of linked list
		                        //temp stores memory address of new node inserted
		                        
		temp->data = value;     //inserts value to the created circle
		
		//Now this has to be included into the linked list (hence the head has to be made as first element of linked list)
		//1st node only;
		if(head == NULL)          //shows that 1st node is being inserted
		{
			head = temp;
		}
		
		/*
		//2nd node only    (address of new node stored in temp)
		else{
			head->next = temp;
		}
		*/
		
		//Any other node only
		else
		{
			tail->next = temp;                 //links last node to the new node being inserted
		}
		
		tail = temp;                       //points tail pointer to the new node(since it is now the last node of the LL)
		cout<<endl;
		
	}
	
	//Deletion
	void deletion()       //deletes the last element
	{
		//store the tail in temp
		Node *temp = tail;
		//node before tail has to point to NULL    
		//tail cannot move back so only way is to use head 
		Node *current = head;
		while(current->next != tail)    //objective is to stop current upto node just before tail
		{
			current = current->next;
		}
		
		current->next = NULL;   //this will be the last node now so that the next node can be deleted
		
		//update tail
		tail = current;         //tail now points to the last node and the next node is inaccessible
		
		//delete temp
		delete temp;            //the next node gets deleted from the heap
		cout<<endl;
	}
	
	//inserts node at a specific place and not in the last necessarily (this function works for all positions except head but we have to make required modifications which is present in the IF statement btw)
	void insertAt(int pos,int value)
	{
		//To add node at the position of the header
		if(pos == 1)
		{
			//create a new node
			Node *temp = new Node;
			//assign the entered value as data to the new node
			temp->data = value;
			//link the new node to head
			temp->next = head;
			//update head 
			head = temp;
		}
		
		else
		{
			//Reach the place before the position
			Node *current = head;
			int i = 1;
			while(i<pos-1)
			{
				i++;
				current = current->next;
			}                                            //now current points to the node just before the position
			
			//counter variable to count no. of entries
			int count = 0;
			//declare present pointer to initially point to head
			Node *present = head;
			//increment count upto last element and simultaneously increment present pointer
			while(present!=NULL)
			{
				count++;
				present = present->next;
			}
			
			if(pos>count)
			{
				cout<<"The linked list doesn't have that many elements\n";
			}
			
			
			else
			{
					
				//Create the node
				Node *temp = new Node;
			    temp->data = value;                //value inserted as data to the new node
				
				//Moving pointers like magic
				temp->next = current->next;     //link established between new node and the next node
				current->next = temp;           //current should be linked to the new node (since current points to the node just before the position)
			}
		}
		cout<<endl;
	}
	
	//Deletes element of linked list from a specific position
	void deletionAt(int pos)
	{
		if(pos == 1)
		{
			//set node to be deleted as temp
			Node *temp = new Node;
			temp = head;
			head = head->next;
			//delete temp
			delete temp;
		}
		
		else
		{
			//reach the position just before the node to be deleted
			Node *current = head;
			int i = 1;
			while(i<pos-1)
			{
				i++;
				current = current->next;
			}
			//Create the node temp and set it as the node to be deleted
			Node *temp = new Node;
			temp = current->next;
			//link previous node to the next node
			current->next = temp->next;
			//delete temp
			delete temp;
	    }
		cout<<endl;
	}

	//Display
	void display()
	{
		Node *current = head;
		while(current != NULL)    //prints till current reaches last node i.e., till current becomes NULL
		{
			cout<<current->data<<"->";
			current = current->next;
		}
		cout<<"NULL";
	}
	
	//Counts number of items in the linked list
	int countItems()
	{
		//set a counter variable
		int count = 0;
		//move pointer from 1st element till the last and increment it everytime it moves
		Node *current = head;
		while(current !=NULL)
		{
			count++;
			current = current->next;
		}
		
		//return the counter
		return count;
	}
};

int main()
{
	LinkedList l1;
	l1.insert(1);
	l1.insert(2);
	l1.insert(3);
	l1.insert(4);
	l1.insert(5);
	l1.insert(6);
	l1.insert(7);
	l1.display();
	l1.deletion();
	l1.display();
	l1.insertAt(1,15);
	l1.display();
	l1.insertAt(4,19);
	l1.display();
	l1.deletionAt(1);
	l1.display();
	l1.deletionAt(3);
	l1.display();
	cout<<endl;
	l1.insertAt(8,11);
	l1.display();
	cout<<endl;
	cout<<"The number of elements is "<<l1.countItems()<<endl;	
	return 0;
}