#include <iostream>
#define SIZE 5
using namespace std;

void push();
void pop();
void top();
bool isEmpty();
bool isFull();
void reverseAString();
bool isPalindrome();
void sortStack();
void display();

char Stack[SIZE];
int topOfStack = -1; // used for empty stack

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
		cout<<"5. IsFull Method (Checks whether the stack is empty or not)"<<endl;
		cout<<"6. Reverse A String"<<endl;
		cout<<"7. IsPalindrome Method (checks whether a number or a string is palindrome or not)"<<endl;
		cout<<"8. Display Method"<<endl;
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
					isEmpty();
					break;
				case 5:
					isFull();
					break;
				case 6:
					reverseAString();
					break;
				case 7:
					isPalindrome();
					break;
				case 8:
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

bool isEmpty()
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

bool isFull()
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

void pop()
{
	if(topOfStack == -1)
	{
		cout<<"Stack Is Empty!"<<endl;
	}
	else
	{
		cout<<"Poped/Deleted Element is: "<<Stack[topOfStack]<<endl;
		topOfStack -= 1;
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

bool isPalindrome()
{
	bool checkPalindrome = true;
	int topElement = topOfStack;
	if(SIZE % 2 == 0)
	{
		for(int index = 0; index <= ((SIZE / 2) - 1); index++)
		{
			if(Stack[topElement] != Stack[index])
			{
				checkPalindrome = false;
				break;
			}
			else
			{
				topElement--;
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
	else
	{
		for(int index = 0; index <= ((SIZE / 2) - 1); index++)
		{
			if(Stack[topElement] != Stack[index])
			{
				checkPalindrome = false;
				break;
			}
			else
			{
				topElement--;
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
}

void sortStack()
{
	
}























