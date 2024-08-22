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
		cout<<"4. Front Method (Returns the front value of the queue)"<<endl;
		cout<<"5. Display Method (Prints all the elements of the queue)"<<endl;
		cout<<"0. Exit"<<endl;
		
		cout<<"Enter your choice from 0 to 6: ";
		cin>>choices;
		cout<<endl;
		
		if(choices < 0 || choices > 5)
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
					break;
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
		cout<<mover -> number<<endl;
		mover = mover -> next;
	}
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

void enqueue()
{
	if(isEmpty())
	{
		cout<<"Initially the queue is empty..."<<endl;
		cout<<"Inserting the first element..."<<endl;
		node* firstNode = new node();
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
		rear -> next = newNode;
		newNode -> next = front;
		rear = newNode;
		cout<<endl;
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
		}
		else
		{
			cout<<"Dequeued/deleted element is: "<<front -> number<<endl;
			front = front -> next;
			rear -> next = front;
			delete deleter;
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


