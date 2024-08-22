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
		void front();
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
		cout<<"6. Display Method (Prints all the elements of the queue)"<<endl;
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
					queue.front();
				case 6:
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
	while(frontIndex < SIZE)
	{
		cout<<queue[frontIndex]<<endl;
		frontIndex++;
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

bool Que :: isFull()
{
	if(rearIndex == (SIZE - 1))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Que :: dequeue()
{
	if(isEmpty())
	{
		cout<<"Queue is empty!"<<endl;
	}
	else
	{
		if(frontIndex == rearIndex)
		{
			cout<<"Dequeued/Deleted element is: "<<queue[frontIndex]<<endl;
			frontIndex = rearIndex = -1;
		}
		else
		{
			cout<<"Dequeued/Deleted element is: "<<queue[frontIndex]<<endl;
			frontIndex = (frontIndex + 1) % SIZE;
		}
	}
} 

void Que :: enqueue()
{
	if(isEmpty())
	{
		cout<<"Initially, queue is empty!"<<endl;
		frontIndex = rearIndex = 0;
		cout<<"Insert first element: ";
	}
	else
	{
		if((rearIndex + 1) % SIZE == frontIndex) // check whether the queue is full or not
		{
			cout<<"OOPS! No Space Available"<<endl;
		}
		else
		{
			rearIndex = (rearIndex + 1) % SIZE;
			cout<<"Enter an integer: ";
		}
	}
	cin>>queue[rearIndex];
	cout<<endl;
}

void Que :: front()
{
	cout<<"Element at front/start of the queue is: "<<queue[frontIndex];
}



















