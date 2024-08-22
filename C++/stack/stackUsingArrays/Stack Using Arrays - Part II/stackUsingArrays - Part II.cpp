#include <iostream>
#define SIZE 5
using namespace std;

class STACK
{
    private:
        char Stack[SIZE];
        int topOfStack;
    public:
        STACK();    //defualt constructor
        void push();
        bool isEmpty();
        bool isFull();
        void display();
        void pop();
        void top();
        void reverseAString();
};

int main()
{
	STACK stack;
	int choices;
	do
	{
		cout<<"*****MENU*****"<<endl;
		cout<<"1. Push Method (Insert an element in the stack)"<<endl;
		cout<<"2. Pop Method (Delete an element from the stack)"<<endl;
		cout<<"3. Top Mehod (Returns the top element of the stack)"<<endl;
		cout<<"4. IsEmpty Method (Checks whether the stack is empty or not)"<<endl;
		cout<<"5. IsFull Method (Checks whether the stack is full or not)"<<endl;
		cout<<"6. Reverse A String"<<endl;
		cout<<"7. Display Method"<<endl;
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
					stack.push();
					break;
				case 2:
					stack.pop();
					break;
				case 3:
					stack.top();
					break;
				case 4:
					stack.isEmpty();
					break;
				case 5:
					stack.isFull();
					break;
				case 6:
					stack.reverseAString();
					break;
				case 7:
					stack.display();
					break;
				default:
					cout<<"Thank You"<<endl;
			}
		}
	}
	while(choices != 0);	
}

STACK :: STACK()
{
    topOfStack = -1;
}

void STACK :: display()
{
	if(topOfStack == -1)
	{
		cout<<"Stack Is Empty!"<<endl;
	}
	else
	{
		cout<<"STACK"<<endl;
		int index = topOfStack;
		while(index != -1)
		{
			cout<<Stack[index]<<endl;
			index--;
		}
	}
}

bool STACK :: isEmpty()
{
	if(topOfStack == -1)
	{
		cout<<"Stack Is Empty!"<<endl;
	}
	else
	{
		cout<<"Something Is Present In The Stack!"<<endl;
	}
}

bool STACK :: isFull()
{
	if(topOfStack == (SIZE - 1))
	{
		cout<<"Stack Is Full!"<<endl;
	}	
	else
	{
		cout<<"There is some space available"<<endl;
	}
}

void STACK :: push()
{
	char characters;
	if(topOfStack == -1)
	{
		topOfStack += 1; 
		cout<<"Initially, the stack is empty!"<<endl;
		cout<<"Inserting an element in the stack..."<<endl;
		cout<<"Enter a number: ";
		cin>>characters;
		cout<<endl;
		Stack[topOfStack] = characters;
	}
	else
	{
		if(topOfStack >= (SIZE - 1))
		{
			cout<<"Overflow!"<<endl;
		}
		else
		{
			topOfStack += 1;
			cout<<"Enter a number: ";
			cin>>characters;
			cout<<endl;
			Stack[topOfStack] = characters;
		}
	}
}

void STACK :: pop()
{
	if(topOfStack == -1)
	{
		cout<<"Stack Is Empty!"<<endl;
	}
	else
	{
		cout<<"Poped/Deleted element is: "<<Stack[topOfStack]<<endl;
		topOfStack -= 1;
	}
}

void STACK :: top()
{
	if(topOfStack == -1)
	{
		cout<<"Stack Is Empty!"<<endl;
	}
	else
	{
		cout<<"TOPMOST ELEMENT OF STACK: "<<Stack[topOfStack]<<endl;
	}
}

void STACK :: reverseAString()
{
	int index;
	int mover = topOfStack;
	if(topOfStack == -1)
	{
		cout<<"Stack Is Empty!"<<endl;
	}	
	else
	{
		char secondStack[SIZE];	
		for(index = 0; index < SIZE; index++)
		{
			secondStack[index] = Stack[mover];
			mover--;
		}
		
		for(index = 0; index < SIZE; index++)
		{
			mover += 1;
			Stack[mover] = secondStack[index];
		}
		topOfStack = mover;
	}
}

