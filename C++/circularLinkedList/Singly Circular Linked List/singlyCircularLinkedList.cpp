#include <iostream>
using namespace std;

struct node{
	int data;
	node* next = NULL;
};

node* head = NULL;
node* tail = NULL;

void insertAtStart();
void insertAtEnd();
void insertAtNthPosition();
bool isEmpty();
void display();

int main()
{
	int choices;
	do
	{
		cout<<"MENU"<<endl;
		cout<<"1. InsertAtStart Method"<<endl;
		cout<<"2. InsertAtEnd Method"<<endl;
		cout<<"3. InsetAtNthPosition Method"<<endl;
		cout<<"4. IsEmpty Method"<<endl;
		cout<<"5. Display Method"<<endl;
		cout<<"0. Exit"<<endl;
		
		cout<<"Enter your choice: ";
		cin>>choices;
		cout<<endl;
		switch(choices)
		{
			case 1:
				insertAtStart();
				break;
			case 2:
				insertAtEnd();
				break;
			case 3:
				insertAtNthPosition();
				break;
			case 4:
				isEmpty();
				break;
			case 5:
				display();
				break;
			default:
				cout<<"Thank You"<<endl;
				break;
		}
	}
	while(choices != 0);
}

void display()
{
	cout<<"*****Display Method*****"<<endl;
	cout<<"Circular Linked List: ";
	if(head == NULL)
	{
		cout<<"EMPTY"<<endl;
	}
	else
	{
		node* move = head;
		int headData = head -> data;
		while(move -> next -> data != headData)
		{
			cout<<move -> data<<"->";
			move = move -> next;
		}
		cout<<move -> data<<"->"<<endl;
	}
}

bool isEmpty()
{
	if(head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void insertAtStart()
{
	if(head == NULL)
	{
		cout<<"Intially, the circular list is empty!"<<endl;
		cout<<"Inserting first node in the list..."<<endl;
		node* firstNode = new node();
		cout<<"Enter a number: ";
		cin>>firstNode -> data;
		cout<<endl;
		head = firstNode;
		tail = firstNode;
		firstNode -> next = tail;
	}
	else
	{
		node* nodeAtStart = new node();
		cout<<"Enter a number: ";
		cin>>nodeAtStart -> data;
		cout<<endl;
		nodeAtStart -> next = head;
		head = nodeAtStart;
		tail -> next = nodeAtStart;
	}
}

void insertAtEnd()
{
	node* newNode = new node();
	if(head == NULL)
	{
		cout<<"Intially, the list is empty!"<<endl;
		cout<<"Inserting a node in the list..."<<endl;
		cout<<"Enter a number: ";
		cin>>newNode -> data;
		cout<<endl;
		head = newNode;
		tail = newNode;
		newNode -> next = tail;
	}
	else
	{
		cout<<"Enter a number: ";
		cin>>newNode -> data;
		cout<<endl;
		tail -> next = newNode;
		newNode -> next = head;
		tail = newNode;
	}
}

void insertAtNthPosition()
{
	int position;
	int numberOfNodes = 0;
	cout<<"Enter a position where you want to enter a node: ";
	cin>>position;
	cout<<endl;
	
	node* mover = head;
	int number = mover -> data;
	while(mover -> next -> data != number)
	{
		mover = mover -> next;
		numberOfNodes++;
	}
	
	if(head == NULL)
	{
		cout<<"List is empty!"<<endl;
	}
	else if(position == 1)
	{
		insertAtStart();
	}
	else if(position == (numberOfNodes + 1))
	{
		insertAtEnd();
	}
	else if(position <= 0 || position > numberOfNodes + 2)
	{
		cout<<"Invalid position!"<<endl;
	}
	else
	{
		node* move = head;
		node* nodeAtNthPosition = new node();
		cout<<"Enter a number: ";
		cin>>nodeAtNthPosition -> data;
		cout<<endl;
	
		for(int count = 1; count <= (position - 2); count++)
		{
			move = move -> next;
		}
		nodeAtNthPosition -> next = move -> next;
		move -> next = nodeAtNthPosition;
	}
}

