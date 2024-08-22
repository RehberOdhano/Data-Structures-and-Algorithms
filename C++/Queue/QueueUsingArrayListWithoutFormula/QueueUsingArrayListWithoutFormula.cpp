#include <iostream>
# define SIZE 5
using namespace std;

class Que
{
	public:
		int queue[SIZE];
		int frontIndex;
		int rearIndex;
	public:
		Que();
		bool isFull();
		bool isEmpty();
		int dequeue();
		void enqueue();
		void frontElement();
		bool isPalindrome();
		void display();
};

int main()
{
	Que queue;
	int choices;
	do
	{
		cout<<"*****MENU*****"<<endl;
		cout<<"1. Enqueue Method (Insert an element at rear/end)"<<endl;
		cout<<"2. Dequeue Method (Delete an element from front/start)"<<endl;
		cout<<"3. IsEmpty Method (Checks whether the stack is empty or not)"<<endl;
		cout<<"4. IsFull Method (Checks whether the stack is full or not)"<<endl;
		cout<<"5. Front Method (Returns the front value of the queue)"<<endl;
		cout<<"6. IsPalindrome Method (checks whether a number or string is palindrome or not)"<<endl;
		cout<<"7. Display Method (Prints all the elements of the queue)"<<endl;
		cout<<"0. Exit"<<endl;
		
		cout<<"Enter your choice from 0 to 6: ";
		cin>>choices;
		cout<<endl;
		
		if(choices < 0 || choices > 7)
		{
			cout<<"Invalid Input! Try Again"<<endl;
		}
		else
		{
			switch(choices)
			{	
				case 1:
					queue.enqueue();
					break;
				case 2:
					queue.dequeue();
					break;
				case 3:
					queue.isEmpty();
					break;
				case 4:
					queue.isFull();
					break;
				case 5:
					queue.frontElement();
					break;
				case 6:
					queue.isPalindrome();
				case 7:
					queue.display();
					break;
				default:
					cout<<"Thank You"<<endl;
			}
		}
	}
	while(choices != 0);	
}

Que :: Que()
{
	frontIndex = rearIndex = -1;
}

void Que :: display()
{
	cout<<"QUEUE"<<endl;
	if(isEmpty())
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

bool Que :: isFull()
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

bool Que :: isEmpty()
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
void Que :: enqueue()
{
	if(isEmpty())
	{
		frontIndex = rearIndex = 0;
		cout<<"Initially the queue is empty!"<<endl;
		cout<<"Inserting the first element..."<<endl;
		cout<<"Enter a number: ";
		cin>>queue[frontIndex];
		cout<<endl;
	}
	else if(isFull())
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
int Que :: dequeue()
{
	if(isEmpty())
	{
		cout<<"Queue is empty!"<<endl;
	}
	
	else if(rearIndex == (SIZE - 1))
	{
		if(frontIndex == rearIndex)
		{
			cout<<"Dequeued/deleted element is: "<<queue[frontIndex]<<endl;
			cout<<"Queue is empty!"<<endl;
			frontIndex = rearIndex = -1;
		}
		else
		{
			cout<<"Dequeued/deleted element is: "<<queue[frontIndex]<<endl;
			frontIndex++;
		}
	}
	else if(rearIndex != (SIZE - 1))
	{
		if(frontIndex == (SIZE - 1))
		{
			cout<<"Dequeued/deleted element is: "<<queue[frontIndex]<<endl;
			frontIndex = 0;
		}
		else if(frontIndex == rearIndex)
		{
			cout<<"Dequeued/deleted element is: "<<queue[frontIndex]<<endl;
			cout<<"Queue is empty!"<<endl;
			frontIndex = rearIndex = -1;
		}
		else
		{
			cout<<"Dequeued/deleted element is: "<<queue[frontIndex]<<endl;
			frontIndex++;
		}
	}
}

void Que :: frontElement()
{
	if(isEmpty())
	{
		cout<<"Queue is empty!"<<endl;
	}
	else
	{
		cout<<"Top/Front/Start element is: "<<queue[frontIndex]<<endl;
	}
}

bool Que :: isPalindrome()
{
	bool checkPalindrome = true;
	int lastIndex = (SIZE - 1);
	if(SIZE % 2 == 0)
	{
		for(int index = 0; index <= ((SIZE / 2) - 1); index++)
		{
			if(queue[index] != queue[lastIndex])
			{
				checkPalindrome = false;
				break;
			}
			else
			{
				lastIndex--;
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
			if(queue[index] != queue[lastIndex])
			{
				checkPalindrome = false;
				break;
			}
			else
			{
				lastIndex--;
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
















