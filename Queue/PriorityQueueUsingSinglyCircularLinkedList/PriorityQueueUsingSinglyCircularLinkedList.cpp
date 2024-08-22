#include <iostream>
using namespace std;

struct node{
	int number;
	node* next = NULL;
};

node* front = NULL;
node* rear = NULL;

bool isEmpty();
int dequeue();
void enqueue();
void frontElement();
void display();

int main()
{
	int choices;
	do
	{
		cout<<"*****MENU*****"<<endl;
		cout<<"1. Enqueue Method (Insert an element at rear/end)"<<endl;
		cout<<"2. Dequeue Method (Delete an element from front/start)"<<endl;
		cout<<"3. IsEmpty Method (Checks whether the stack is empty or not)"<<endl;
		cout<<"4. FrontElement Method (Returns the front value of the queue)"<<endl;
		cout<<"5. Display Method (Prints all the elements of the queue)"<<endl;
		cout<<"0. Exit"<<endl;
		
		cout<<"Enter your choice from 0 to 6: ";
		cin>>choices;
		cout<<endl;
		
		if(choices < 0 || choices > 6)
		{
			cout<<"Invalid Input! Try Again"<<endl;
		}
		else
		{
			switch(choices)
			{	
				case 1:
					enqueue();
					break;
				case 2:
					dequeue();
					break;
				case 3:
					isEmpty();
					break;
				case 4:
					frontElement();
				case 5:
					display();
					break;
				default:
					cout<<"Thank You"<<endl;
			}
		}
	}
	while(choices != 0);	
}

void display()
{
	cout<<"QUEUE"<<endl;
	node* mover = front;
	while(mover != rear)
	{
		cout<<mover -> number<<"->";
		mover = mover -> next;
	}
	cout<<rear -> number<<"->"<<endl;
}

bool isEmpty()
{
	if(front == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isFull()
{
	
}

void enqueue()
{
	if(isEmpty())
	{
		node* firstNode = new node();
		cout<<"Initially the queue is empty..."<<endl;
		cout<<"Inserting the first element..."<<endl;
		cout<<"Enter a number: ";
		cin>>firstNode -> number;
		front = firstNode;
		rear = firstNode;
		firstNode -> next = front;
		cout<<endl;
	}
	else
	{
		node* newNode = new node();
		cout<<"Enter a number: ";
		cin>>newNode -> number;
		cout<<endl;
		
		node* move = front;
		node* helper = front;
		
		if(newNode -> number > rear -> number)
		{
			rear -> next = newNode;
			newNode -> next = front;
			rear = newNode;
		}
		else if(newNode -> number <= front -> number)
		{
			newNode -> next = front;
			front = newNode;
			rear -> next = front;
		}
		else
		{
			while(newNode -> number > move -> number)
			{
				move = move -> next;
			}
			while(helper -> next != move)
			{
				helper = helper -> next;
			}
			helper -> next = newNode;
			newNode -> next = move; 
		}
	}
}

int dequeue()
{
	node* deleter = front;
	if(isEmpty())
	{
		cout<<"OOPS! Queue is empty!"<<endl;
	}
	else
	{
		if(front == rear)
		{
			cout<<"Dequeued/deleted element is: "<<front -> number<<endl;
			front = NULL;
			rear = NULL;
			delete deleter;
		}
		else
		{
			cout<<"Dequeued/deleted element is: "<<front -> number<<endl;
			front = front -> next;
		}
	}
}

void frontElement()
{
	if(isEmpty())
	{
		cout<<"OOPS! Queue is empty!"<<endl;
	}
	else
	{
		cout<<"Element at top/front/start of the queue is: "<<front -> number<<endl;
	}
}


