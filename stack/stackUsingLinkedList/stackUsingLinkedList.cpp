#include <iostream>
using namespace std;

struct node{
	int data;
	node* next = NULL;
};

node* head = NULL;
node* top = NULL;
node* mover = NULL;

void push();
void pop();
void Top();
bool isEmpty();
void reverseAString();
void display();

int main()
{
	int choices;
	do
	{
		cout<<"*****MENU*****"<<endl;
		cout<<"1. Push Method (Insert an element in the stack)"<<endl;
		cout<<"2. Pop Method (Delete an element from the stack)"<<endl;
		cout<<"3. Top Mehod (Returns the top element of the stack)"<<endl;
		cout<<"4. IsEmpty Method (Checks whether the stack is empty or not)"<<endl;
		cout<<"5. Reverse a string"<<endl;
		cout<<"6. Display Method"<<endl;
		cout<<"0. Exit"<<endl;
		
		cout<<"Enter your choice: ";
		cin>>choices;
		cout<<endl;
		
		if(choices < 0)
		{
			cout<<"Invalid Input! Try Again"<<endl;
		}
		else
		{
			switch(choices)
			{	
				case 1:
					push();
					break;
				case 2:
					pop();
					break;
				case 3:
					Top();
					break;
				case 4:
					isEmpty();
					break;
				case 5:
					reverseAString();
					break;
				case 6:
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
	mover = top;
	if(top == NULL)
	{
		cout<<"Stack Is Empty!"<<endl;
	}
	else
	{
		while(mover != NULL)
		{
			cout<<mover -> data<<"->";
			mover = mover -> next;
		}
	}
	cout<<endl;
}

bool isEmpty()
{
	if(top == NULL)
	{
		cout<<"Stack Is Empty!"<<endl;
	}	
	else
	{
		cout<<"Something is present in the stack!"<<endl;
	}
}

void push()
{
	if(top == NULL)
	{
		cout<<"Initially, the stack is empty!"<<endl;
		cout<<"Inserting first element in the stack..."<<endl;
		node* firstNode = new node();
		head = firstNode;
		top = firstNode;
		cout<<"Enter a number: ";
		cin>>firstNode -> data;
		cout<<endl;
		firstNode -> next = NULL;
	}
	else
	{
		node* newNode = new node();
		cout<<"Enter a number: ";
		cin>>newNode -> data;
		cout<<endl;
		newNode -> next = top;
		top = newNode;
	}	
}

void pop()
{
	if(top == NULL)
	{
		cout<<"Stack Is Empty!"<<endl;
	}	
	else
	{
		mover = top;
		if(mover -> next == NULL)
		{
			top = NULL;
			delete mover;
		}
		else
		{
			top = mover -> next;
			delete mover;
		}
	}
}

void Top()
{
	if(top == NULL)
	{
		cout<<"Stack Is Empty!"<<endl;
	}	
	else
	{
		cout<<"TOPMOST ELEMENT: "<<top -> data<<endl;
	}
}

void reverseAString()
{
	int nodeCounter = 0;
	int exchange = 0;
	node* moverOne = head;
	node* moverTwo = head;
	node* traverser = head;
	
	while(traverser != NULL)
	{
		traverser = traverser -> next;
		nodeCounter++;
	}
	
	if(head == NULL)
	{
		cout<<"Stack Is Empty!"<<endl;
	}
	else if(traverser -> next == NULL)
	{
		cout<<"Only one element is present in the stack. Can't be reversed"<<endl;
	}
	else if(nodeCounter % 2 == 0)
	{
				
	}
}





















