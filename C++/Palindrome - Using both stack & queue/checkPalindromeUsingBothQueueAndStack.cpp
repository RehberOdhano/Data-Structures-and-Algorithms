#include <iostream>
#define SIZE 5
using namespace std;

void push();
char pop();
void top();
bool isStackEmpty();
bool isStackFull();
void reverseAString();
bool isPalindrome();
bool isQueueEmpty();
bool isQueueFull();
char dequeue();
void enqueue();
void frontElement();
void displayStack();
void displayQueue();

char Stack[SIZE];
char queue[SIZE];
int topOfStack = -1; // used for empty stack
int frontIndex = -1;
int rearIndex = -1;

int main()
{
	int choices;
	do
	{
		cout<<"*****MENU*****"<<endl;
		cout<<"Stack Methods..."<<endl;
		cout<<"1. Push Method (Insert an element in the stack)"<<endl;
		cout<<"2. Pop Method (Delete an element from the stack)"<<endl;
		cout<<"3. Top Mehod (Returns the top element of the stack)"<<endl;
		cout<<"4. IsStackEmpty Method (Checks whether the stack is empty or not)"<<endl;
		cout<<"5. IsStackFull Method (Checks whether the stack is empty or not)"<<endl;
		cout<<"6. Reverse A String"<<endl;
		cout<<"7. IsPalindrome Method (checks whether a number or a string is palindrome or not)"<<endl;
		cout<<"8. DisplayStack Method"<<endl;
		cout<<"Queue Methods..."<<endl;
		cout<<"9. Dequeue Method (Delete an element from the front)"<<endl;
		cout<<"10. Enqueue Method (Insert an element at the rear)"<<endl;
		cout<<"11. IsQueueEmpty Method"<<endl;
		cout<<"12. IsQueueFull Method"<<endl;
		cout<<"13. FrontElement Method"<<endl;
		cout<<"14. DisplayQueue Method"<<endl;
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
					top();
					break;
				case 4:
					isStackEmpty();
					break;
				case 5:
					isStackFull();
					break;
				case 6:
					reverseAString();
					break;
				case 7:
					isPalindrome();
					break;
				case 8:
					displayStack();
					break;
				case 9:
					dequeue();
					break;
				case 10:
					enqueue();
					break;
				case 11:
					isQueueEmpty();
					break;
				case 12:
					isQueueFull();
					break;
				case 13:
					frontElement();
					break;
				case 14:
					displayQueue();
					break;
				default:
					cout<<"Thank You"<<endl;
			}
		}
	}
	while(choices != 0);	
}

void displayStack()
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

bool isStackEmpty()
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

bool isStackFull()
{
	if(topOfStack == (SIZE - 1))
	{
		cout<<"Stack Is Full!"<<endl;
	}	
	else
	{
		cout<<"There is some space available!"<<endl;
	}
}

void push()
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

char pop()
{
	int topElement = 0;
	if(topElement <= (SIZE - 1))
	{
		return (Stack[topElement]);
		topElement++;
	}
	else
	{
		cout<<"Stack is empty!"<<endl;
	}
}

void top()
{
	if(topOfStack == -1)
	{
		cout<<"Stack Is Empty!"<<endl;
	}
	else
	{
		cout<<Stack[topOfStack]<<endl;
	}
}

void reverseAString()
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

void displayQueue()
{
	cout<<"QUEUE"<<endl;
	if(isQueueEmpty())
	{
		cout<<"EMPTY!"<<endl;
	}
	else
	{
		for(int index = 0; index < SIZE; index++)
		{
			cout<<queue[index]<<endl;
		}
	}
}

bool isQueueFull()
{
	if(frontIndex == 0 && rearIndex == (SIZE - 1))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isQueueEmpty()
{
	if(frontIndex == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// insert at end method
void enqueue()
{
	if(isQueueEmpty())
	{
		frontIndex = rearIndex = 0;
		cout<<"Initially the queue is empty!"<<endl;
		cout<<"Inserting the first element..."<<endl;
		cout<<"Enter a number: ";
		cin>>queue[frontIndex];
		cout<<endl;
	}
	else if(isQueueFull())
	{
		cout<<"OOPS! No Space is Available!"<<endl;
	}
	else
	{
		if(frontIndex != 0 && rearIndex == (SIZE - 1))
		{
			rearIndex = 0;
			cout<<"Enter a number: ";
			cin>>queue[rearIndex];
			cout<<endl;
		}
		else
		{
			rearIndex++;
			if(rearIndex == frontIndex)
			{
				cout<<"OOPS! Queue is full!"<<endl;
			}
			else
			{
				cout<<"Enter a number: ";
				cin>>queue[rearIndex];
				cout<<endl;
			}
		}
	}
}

// delete from start
char dequeue()
{
	if(isQueueEmpty())
	{
		cout<<"Queue is empty!"<<endl;
	}
	
	else if(rearIndex == (SIZE - 1))
	{
		if(frontIndex == rearIndex)
		{
			return (queue[frontIndex]);
			frontIndex = rearIndex = -1;
		}
		else
		{
			return (queue[frontIndex]);
			frontIndex++;
		}
	}
	else if(rearIndex != (SIZE - 1))
	{
		if(frontIndex == (SIZE - 1))
		{
			return (queue[frontIndex]);
			frontIndex = 0;
		}
		else if(frontIndex == rearIndex)
		{
			return (queue[frontIndex]);
			frontIndex = rearIndex = -1;
		}
		else
		{
			return (queue[frontIndex]);
			frontIndex++;
		}
	}
}

void frontElement()
{
	if(isQueueEmpty())
	{
		cout<<"Queue is empty!"<<endl;
	}
	else
	{
		cout<<"Top/Front/Start element is: "<<queue[frontIndex]<<endl;
	}
}

bool isPalindrome()
{
	bool checkPalindrome = true;
	for(int index = 0; index < SIZE; index++)
	{
		if(dequeue() != pop())
		{
			checkPalindrome = false;
			break;
		}
		else
		{
			continue;
		}
	}
		
	if(checkPalindrome)
	{
		cout<<"It's a palindrome!"<<endl;
	}
	else
	{
		cout<<"Not a palindrome!"<<endl;
	}
}













