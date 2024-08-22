#include <iostream>
using namespace std;

struct node{
	int data;
	node* prev = NULL;
	node* next = NULL;
};

node* head = NULL;
node* tail = NULL;

void insertANodeAtStart();
void insertANodeAtEnd();
void deleteNodeFromStart();
void deleteNodeFromEnd();
void display();
void sizeOfDeque();

int main()
{
	int choices;
	do
	{
		cout<<"Menu"<<endl;
		cout<<"1. Insert Node At Start"<<endl;
		cout<<"2. Insert Node At End"<<endl;
		cout<<"3. Delete Node From Start"<<endl;
		cout<<"4. Delete Node From End"<<endl;
		cout<<"5. Size of queue"<<endl;
		cout<<"6. Display"<<endl;
		cout<<"0. Exit"<<endl;
		cin>>choices;
		switch(choices)
		{
			case 1:
				insertANodeAtStart();
				break;
			case 2:
				insertANodeAtEnd();
				break;
			case 3:
				deleteNodeFromStart();
				break;
			case 4:
				deleteNodeFromEnd();
				break;
			case 5:
				sizeOfDeque();
				break;
			case 6:
				display();
				break;
			default:
				cout<<"Good Bye"<<endl;
				break;
		}
	}
	while(choices != 0);
}

void display()
{
	cout<<"Double Ended Queue: ";
	if(head == NULL)
	{
		cout<<"Empty!"<<endl;
	}
	else
	{
		node* move = head;
		while(move != NULL)
		{
			cout<<move -> data<<"->";
			move = move -> next;
		}
		cout<<endl;
	}
}

void insertANodeAtStart()
{
	if(head == NULL)
	{
		cout<<"Initially queue is empty!"<<endl;
		cout<<"Inserting first element..."<<endl;
		node* firstNode = new node();
		cout<<"Enter a number: ";
		cin>>firstNode -> data;
		firstNode -> next = firstNode -> prev = NULL;
		head = tail = firstNode;
	}
	else
	{
		node* nodeAtStart = new node();
		cout<<"Enter a number: ";
		cin>>nodeAtStart -> data;
		nodeAtStart -> next = head;
		head -> prev = nodeAtStart;
		nodeAtStart -> prev = NULL; 
		head = nodeAtStart;
	}
	cout<<"Node is inserted at start"<<endl;
}

void insertANodeAtEnd()
{
	if(head == NULL)
	{
		cout<<"Initially queue is empty!"<<endl;
		cout<<"Inserting first element..."<<endl;
		node* firstNode = new node();
		cout<<"Enter a number: ";
		cin>>firstNode -> data;
		firstNode -> next = firstNode -> prev = NULL;
		head = tail = firstNode;
	}
	else
	{
		node* nodeAtEnd = new node();
		cout<<"Enter a number: ";
		cin>>nodeAtEnd -> data;
		tail -> next = nodeAtEnd;
		nodeAtEnd -> prev = tail;
		nodeAtEnd -> next = NULL;
		tail = nodeAtEnd;
	}
	cout<<"Node is inserted at end"<<endl;
}

void deleteNodeFromStart()
{
	if(head == NULL)
	{
		cout<<"Queue is empty!"<<endl;
	}
	else
	{
		node* temp = head;
		if(temp -> prev == NULL && temp -> next == NULL)
		{
			head = tail = NULL;
		}
		else
		{
			head = head -> next;
			temp -> next = NULL;
			head -> prev = NULL;
		}
		delete temp;
		cout<<"Node is delete from start"<<endl;
	}
}

void deleteNodeFromEnd()
{
	if(head == NULL)
	{
		cout<<"Queue is empty!"<<endl;
	}
	else
	{
		node* temp = tail;
		
		if(temp -> prev == NULL && temp -> next == NULL)
		{
			head = tail = NULL;
		}
		else
		{
			tail = tail -> prev;
			tail -> next = NULL;
			temp -> prev = NULL;
		}
		delete temp;
		cout<<"Node is delete from end"<<endl;
	}
}

void sizeOfDeque()
{
	if(head == NULL)
	{
		cout<<"Queue is empty!"<<endl;
	}
	else
	{
		int count = 0;
		node* temp = head;
		while(temp != NULL)
		{
			count++;
			temp = temp -> next;
		}
		delete temp;
		cout<<"Size of Queue: "<<count<<" element(s)"<<endl;
	}
}
