#include <iostream>
using namespace std;

class Que
{
	public:
		int size;
		int *q; // array that holds queue elements and pointer is taken so that dynamically we can create
			   // array to store the elements
				// if we want user defined size
		int front;
		int rear;
	public:
		Que(); // default constructor
		Que(int x); // overloaded constructor... we are passing an argument for the size of the queue  
		bool isFull();
		bool isEmpty();
		int dequeue();
		void enqueue(int x); // element we want to enque		
};

int main()
{
	Que q1; //default constructor called
	Que q2(5);
	Que q3(15);
	q1.enqueue(5);
	q2.enqueue(7);
	q3.enqueue(6);
	int x = q2.dequeue();
	cout<<"Dequeued element from q3 is: "<<x<<endl; 
}

// default constructor
Que :: Que()
{
	size = 10; // default size
	q = new int[size]; // runtime size allocation and point to newly created array
	front = rear = -1;
}

// overloaded constructor
Que :: Que(int x)
{
	size = x; // user defined size
	q = new int[size]; // points to the starting location of array
	front = rear = -1;
}

Que :: bool isEmpty()
{
	if(rear == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Que :: bool isFull()
{
	if(rear == size - 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Que :: void enqueue(int x)
{
	if(isFull())
	{
		cout<<"Queue is full!"<<endl;
	}
	else
	{
		if(isEmpty())
		{
			front = rear = 0;
		}
		else
		{
			rear++;
		}
		q[rear] = x;
	}
}

Que :: int dequeue()
{
	if(isEmpty())
	{
		cout<<"Queue is empty!"<<endl;
		return -1;
	}
	else if(front == rear) // if only one element is present
	{
		front = rear = -1;
	}
	else
	{
		return q[front++];
	}
}





































