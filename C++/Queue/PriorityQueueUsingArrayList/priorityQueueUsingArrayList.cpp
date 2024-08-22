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
	if(frontIndex == 0 && rearIndex == (SIZE - 1) || frontIndex > rearIndex)
	{
		return true;
	}
	else
	{
		return false;
	}
}

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
		int input;
		cout<<"Enter a number: ";
		cin>>input;
		cout<<endl;
		
		// check if there is some space at the start
		if(frontIndex != 0 && rearIndex == (SIZE - 1))
		{
			if(input > queue[rearIndex])
			{
				// shift to left
				int move = frontIndex;
				while(move <= (SIZE - 1))
				{
					queue[move - 1] = queue[move];
					move++;
				}
				queue[rearIndex] = input;
				frontIndex -= 1;
			}
			else
			{
				int mover = rearIndex;
				while(mover != (frontIndex - 1) && input <= queue[mover])
				{
					/*if(input <= queue[mover])
					{
						mover--;
					}
					else
					{
						int counter = frontIndex;
						while(counter <= mover)
						{
							queue[counter - 1] = queue[counter];
							counter++;
						}
						queue[mover] = input;
						break;
						
					}
					*/
					mover--;
				}
				if(input > queue[mover])
				{
					queue[frontIndex - 1] = queue[frontIndex];
				}
				/*else
				{
					queue[mover] = input;
					frontIndex -= 1;
					//rearIndex = mover;
				}
				*/
				frontIndex -= 1;
				queue[mover] = input;
			}
		}
		else
		{
			// check if there is some space in the end
			if(frontIndex == 0 && rearIndex != (SIZE - 1))
			{
				if(input > queue[rearIndex])
				{
					rearIndex++;
					queue[rearIndex] = input;
				}
				else
				{
					// shift to right
					int traverse = rearIndex;
					while(traverse != -1)
					{
						if(traverse == 0 && input < queue[traverse])
						{
							queue[traverse + 1] = queue[traverse];
							queue[traverse] = input;
							frontIndex = 0;
							break;
						}
						else if(input <= queue[traverse])
						{
							queue[traverse + 1] = queue[traverse];
							traverse--;
						}
						else
						{
							traverse++;
							queue[traverse] = input;
							break;
						}
					}
					rearIndex++;
				}
			}
		}
	}
}

int Que :: dequeue()
{
	if(isEmpty())
	{
		cout<<"OOPS! Queue is empty!"<<endl;
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

void Que :: front()
{
	if(isEmpty())
	{
		cout<<"OOPS! Queue is empty!"<<endl;
	}
	else
	{
		cout<<"Element at front/start of the queue is: "<<queue[frontIndex];
	}
}

