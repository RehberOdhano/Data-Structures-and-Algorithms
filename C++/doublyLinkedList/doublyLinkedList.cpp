#include <iostream>
using namespace std;

struct node{
	int data;
	node* previous = NULL;
	node* next = NULL;
};

node* head = NULL;
node* tail = NULL;

bool isEmpty();
void insertANodeAtStart();
void insertANodeAtEnd();
void insertANodeAtNthPosition();
void deleteFirstNode();
void deleteLastNode();
void deleteNodeAtNthPosition();
void swapNodes();
void printListInReverseOrder();
void arrangeListInReverseOrder();
void palindrome();
void display();

int main()
{
	int choices;
	do
	{
		cout<<"MENU"<<endl;
		cout<<"1. Check Whether the list is empty or not"<<endl;
		cout<<"2. Insert A Node At Start"<<endl;
		cout<<"3. Insert A Node At End"<<endl;
		cout<<"4. Insert A Node At Nth Position"<<endl;
		cout<<"5. Delete First Node"<<endl;
		cout<<"6. Delete Last Node"<<endl;
		cout<<"7. Delete Node At Nth Position"<<endl;
		cout<<"8. Swap Nodes"<<endl;
		cout<<"9. Print The Linked List In Reverse Order"<<endl;
		cout<<"10. Arrange The List In Reverse Order"<<endl;
		cout<<"11. Check Whether the list is palindrome or not"<<endl;
		cout<<"12. Display"<<endl;
		cout<<"0. Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>choices;
		cout<<endl;
		switch(choices)
		{
			case 1:
				isEmpty();
				break;
			case 2:
				insertANodeAtStart();
				break;
			case 3:
				insertANodeAtEnd();
				break;
			case 4:
				insertANodeAtNthPosition();
				break;
			case 5:
				deleteFirstNode();
				break;
			case 6:
				deleteLastNode();
				break;
			case 7:
				deleteNodeAtNthPosition();
				break;
			case 8:
				swapNodes();
				break;
			case 9:
				printListInReverseOrder();
				break;
			case 10:
				arrangeListInReverseOrder();
				break;
			case 11:
				palindrome();
				break;
			case 12:
				display();
				break;
			default:
				cout<<"Thank you"<<endl;
		}
	}
	while(choices != 0);
	
}

void display()
{
	cout<<"*****Display Method*****"<<endl;
	cout<<"LINKED LIST: ";
	if(head == NULL)
	{
		cout<<"EMPTY"<<endl;
	}
	else
	{
		node* temp = head; 
		while(temp != NULL)
		{
			cout<<temp -> data<<"->";
			temp = temp -> next;
		}
	}
	cout<<endl;
		
}

bool isEmpty()
{
	if(head == NULL)
	{
		cout<<"List is empty!"<<endl;
	}
	else
	{
		cout<<"Something is present in the list!"<<endl;
	}	
}

void insertANodeAtStart()
{
	node* nodeAtStart = new node();
	if(head == NULL)
	{
		cout<<"Initially, the last is empty!"<<endl;
		cout<<"Inserting a node..."<<endl;
		cout<<"Enter a number: ";
		cin>>nodeAtStart -> data;
		cout<<endl;
		nodeAtStart -> next = NULL;
		nodeAtStart -> previous = NULL;
		head = nodeAtStart;
		tail = nodeAtStart;
	}
	else
	{
		cout<<"Enter a number: ";
		cin>>nodeAtStart -> data;
		cout<<endl;
		nodeAtStart -> previous = NULL;
		nodeAtStart -> next = head;
		head -> previous = nodeAtStart;
		head = nodeAtStart;
		tail = nodeAtStart -> next;
	}
}

void insertANodeAtEnd()
{
	node* newNode = new node();
	if(head == NULL)
	{
		cout<<"Initially, the list is empty!"<<endl;
		cout<<"Inserting first node in the list..."<<endl;
		cout<<"Enter a number: ";
		cin>>newNode -> data;
		cout<<endl;
		newNode -> previous = NULL;
		newNode -> next = NULL;
		head = newNode;
		tail = newNode;
	}
	else
	{	
		cout<<"Enter a number: ";
		cin>>newNode -> data;
		cout<<endl;
		
		node* temp = head;
		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}
		
		temp -> next = newNode;
		newNode -> previous = temp;
		newNode -> next = NULL;
		tail = newNode;
	}	
}

void insertANodeAtNthPosition()
{
	node* temp = head;
	node* secondNode = head;
	node* thirdNode = head;
	int position;
	cout<<"Enter the position where you want to enter a node: ";
	cin>>position;
	cout<<endl;
	
	int nodeCounter = 1;
	if(head == NULL)
	{
		cout<<"OOPS1! List is empty!"<<endl;
		nodeCounter = 0;
	}
	else
	{
		while(temp -> next != NULL)
		{
			temp = temp -> next;
			nodeCounter++;
		}
	}
	
	if(position == 1)
	{
		insertANodeAtStart();
	}
	else if(position == (nodeCounter + 1))
	{
		insertANodeAtEnd();
	}
	else if(position <= 0 || position > (nodeCounter + 1))
	{
		cout<<"Invalid Input!"<<endl;
	}
	else
	{
		node* mover = head;
		for(int count = 1; count <= (position - 2); count++)
		{
			mover = mover -> next;
		}
		
		if(mover == head && (nodeCounter % 2 == 0 || nodeCounter % 2 == 1))
		{
			secondNode = mover -> next;
			node* nodeAtNthPosition = new node();
			cout<<"Enter a number: ";
			cin>>nodeAtNthPosition -> data;
			cout<<endl;
			mover -> next = nodeAtNthPosition;
			nodeAtNthPosition -> previous = mover;
			nodeAtNthPosition -> next = secondNode;
			secondNode -> previous = nodeAtNthPosition;
		}
		else
		{
			thirdNode = mover -> next;
			node* nodeAtNthPosition = new node();
			cout<<"Enter a number: ";
			cin>>nodeAtNthPosition -> data;
			cout<<endl;
			mover -> next = nodeAtNthPosition;
			nodeAtNthPosition -> previous = mover;
			nodeAtNthPosition -> next = thirdNode;
			thirdNode -> previous = nodeAtNthPosition;
		}
	}
}

void deleteFirstNode()
{
	node* firstNode = head;
	node* afterFirstNode = firstNode -> next;
	int counter = 0;
	if(head == NULL)
	{
		cout<<"OOPS! List is empty!"<<endl;
	}
	else 
	{
		node* temp = head;
		while(temp != NULL)
		{
			temp = temp -> next;
			counter++; 
		}
	}
	
	if(counter == 1)
	{
		head = NULL;
		delete firstNode;
	}
	else
	{
		afterFirstNode -> previous = NULL;
		firstNode -> next = NULL;
		head = afterFirstNode;
		delete firstNode;
	}
}

void deleteLastNode()
{
	node* temp = head;
	node* lastNode = head;
	node* previousOfLastNode = head;
	int counter = 0;
	if(head == NULL)
	{
		cout<<"OOPS! List is empty!"<<endl;
	}
	else 
	{
		while(temp != NULL)
		{
			temp = temp -> next;
			counter++; 
		}
	}
	
	if(counter == 1)
	{
		deleteFirstNode();
	}
	else
	{
		while(lastNode -> next != NULL)
		{
			lastNode = lastNode -> next;
		}
		
		for(int count = 1; count <= (counter - 2); count++)
		{
			previousOfLastNode = previousOfLastNode -> next;
		}
		
		previousOfLastNode -> next = NULL;
		lastNode -> previous = NULL;
		delete lastNode;
	}
}

void deleteNodeAtNthPosition()
{
	int nthPosition;
	node* helperOne = head;
	node* helperTwo = head;
	node* nodeCounter = head;
	node* deleterNode;
	cout<<"Enter a position of node you want to delete: ";
	cin>>nthPosition;
	cout<<endl;	
	
	int counter = 0;
	while(nodeCounter != NULL)
	{
		nodeCounter = nodeCounter -> next;
		counter++;
	}
	
	if(head == NULL)
	{
		cout<<"OOPS! List is empty"<<endl;
	}
	
	else if(nthPosition <= 0 || nthPosition > (counter + 1))
	{
		cout<<"Invalid Position Entered!"<<endl;
	}
	
	else if(nthPosition == 1)
	{
		deleteFirstNode();
	}
	else if(nthPosition == counter)
	{
		deleteLastNode();
	}
	else if(nthPosition > 1 && nthPosition < counter)
	{
		for(int count = 1; count <= (nthPosition - 2); count++)
		{
			helperOne = helperOne -> next;
		}
		
		for(int count = 1; count <= nthPosition; count++)
		{
			helperTwo = helperTwo -> next;
		}
		
		deleterNode = helperOne -> next;
		helperOne -> next = NULL;
		helperTwo -> previous = NULL;
		helperOne -> next = helperTwo;
		helperTwo -> previous = helperOne;
		deleterNode -> next = NULL;
		deleterNode -> previous = NULL;
		delete deleterNode; 
	}
}

void swapNodes()
{
	node* temp = head;
	node* lastNode = head;
	node* headNode = head;
	node* secondNode = head;
	int nodeCalculator = 0;
	int positionOne;
	int positionTwo;
	cout<<"Enter a position of node to swap with other: ";
	cin>>positionOne;
	cout<<endl;
	cout<<"Enter a position of node to swap with other: ";
	cin>>positionTwo;
	cout<<endl;
	
	if(head == NULL)
	{
		cout<<"List is empty!"<<endl;
	}
	else
	{
		while(lastNode -> next != NULL)
		{
			lastNode = lastNode -> next;
		}
			
		while(temp != NULL)
		{
			temp = temp -> next;
			nodeCalculator++;
		}
		
		if(nodeCalculator == 1)
		{
			cout<<"Swapping can't occur! Only one node is present in the list"<<endl;
		}
		else if((nodeCalculator == 2 & ( positionOne == 1 && positionTwo == 2)) || (nodeCalculator == 2 & ( positionOne == 2 && positionTwo == 1))) // maybe not needed)
		{
			lastNode -> next = headNode;
			headNode -> previous = lastNode;
			headNode -> next = NULL;
			lastNode -> previous = NULL;
			head = lastNode;
		}
		else if(positionOne == 1 && nodeCalculator > 2)
		{
			if(positionTwo == 2)
			{
				secondNode = headNode -> next;
				secondNode -> next = headNode;
				headNode -> previous = secondNode;
				headNode -> next = lastNode;
				lastNode -> previous = headNode;
				head = secondNode;
			}
			else if(positionTwo == 3) 
			{
				if(nodeCalculator == 3)
				{
					secondNode = headNode -> next;
					lastNode -> next = secondNode;
					secondNode -> next = headNode;
					headNode -> previous = secondNode;
					secondNode -> previous = lastNode;
					headNode -> next = NULL;
					lastNode -> previous = NULL;
					head = lastNode;
				}
				else
				{
					secondNode = head -> next;
					headNode -> next = lastNode;
					lastNode -> previous = headNode;
					lastNode -> next = NULL;
					secondNode -> next = headNode;
					headNode -> previous = secondNode;
					secondNode -> previous = secondNode -> next;
					secondNode -> next -> next = secondNode;
					secondNode -> next -> previous = NULL;
					head= secondNode -> next; 
				}
			}
			
		}
	}

}

void printListInReverseOrder()
{
	int nodeCounter = 0;
	node* headNode = head;
	node* temp = head;
	node* helper = head;
	node* lastNode = head;
	node* secondNode = head;
	node* mover = head;
	node* previousOfLastNode = head;
	node* thirdNode = head;
	
	if(head == NULL)
	{
		cout<<"List is empty!"<<endl;
	}
	else
	{
		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}
	
		while(mover != NULL)
		{
			mover = mover -> next;
			nodeCounter++;
		}
	
		if(nodeCounter == 1)
		{
			cout<<headNode -> data<<"->"<<endl;
		}
		else if(nodeCounter == 2)
		{
			lastNode = temp;
			lastNode -> next = headNode;
			headNode -> previous = lastNode;
			headNode -> next = NULL;
			lastNode -> previous = NULL;
			head = lastNode;
		}
		else if(nodeCounter == 3)
		{
			secondNode = headNode -> next;
			lastNode = temp;
			lastNode -> next = secondNode;
			secondNode -> previous = lastNode;
			secondNode -> next = headNode;
			headNode -> previous = secondNode;
			headNode -> next = NULL;
			lastNode -> previous = NULL;
			head = lastNode;
		}
		else if(nodeCounter % 2 == 0)
		{
			secondNode = headNode -> next;
			lastNode = temp;
			for(int count = 1; count <= (nodeCounter - 2); count++)
			{
				previousOfLastNode = previousOfLastNode -> next;
			}
		
			lastNode -> next = previousOfLastNode;
			previousOfLastNode -> next = secondNode;
			secondNode -> next = headNode;
			previousOfLastNode -> previous = lastNode;
			secondNode -> previous = previousOfLastNode;
			headNode -> previous = secondNode;
			headNode -> next = NULL; 
			lastNode -> previous = NULL;
			head = lastNode;
		}
		else
		{
			secondNode = headNode -> next;
			lastNode = temp;
			for(int count = 1; count <= (nodeCounter - 2); count++)
			{
				previousOfLastNode = previousOfLastNode -> next;
			}
			thirdNode = secondNode -> next;
			lastNode -> next = previousOfLastNode;
			previousOfLastNode -> previous = lastNode;
			previousOfLastNode -> next = thirdNode;
			thirdNode -> previous = previousOfLastNode;
			thirdNode -> next = secondNode;
			secondNode -> previous = thirdNode;
			secondNode -> next = headNode;
			headNode -> previous = secondNode;
			lastNode -> previous = NULL;
			headNode -> next = NULL;
			head = lastNode;
		}
	}
}

void arrangeListInReverseOrder()
{
	int nodeCount = 0;
	int carrierOne = 0;
	int carrierTwo = 0;
	node* nodeCounter = head;
	node* firstNode = head;
	node* lastNode = head;
	
	if(head == NULL)
	{
		cout<<"List is empty!"<<endl;
	}
	else
	{
		while(nodeCounter != NULL)
		{
			nodeCounter = nodeCounter -> next;
			nodeCount++;
		}
	
		while(lastNode -> next != NULL)
		{
			lastNode = lastNode -> next;
		}
		
		if(nodeCount == 1)
		{
			cout<<lastNode -> data<<"->"<<endl;
		}

		else if(nodeCount == 2)
		{
			carrierOne = firstNode -> data;
			firstNode -> data = lastNode -> data;
			lastNode -> data = carrierOne; 
		}
	
		else if (nodeCount == 3)
		{
			carrierOne = firstNode -> data;
			firstNode -> data = lastNode -> data;
			lastNode -> data = carrierOne;
		}
		else
		{
			carrierOne = firstNode -> data;
			carrierTwo = firstNode -> next -> data;
			firstNode -> data = lastNode -> data;
			lastNode -> data = carrierOne;
			firstNode -> next -> data = lastNode -> previous -> data;
			lastNode -> previous -> data = carrierTwo; 
		}
	}
	
	
}

void palindrome()
{
	int nodes = 0;
	node* first = head;
	node* last = head;
	node* noder = head;
	
	while(noder != NULL)
	{
		noder = noder -> next; 
		nodes++;
	}
	
	while(last -> next != NULL)
	{
		last = last -> next;
	}
	
	if(head == NULL)
	{
		cout<<"List is empty!"<<endl;
	}
	else
	{
		if(nodes % 2 == 0)
		{
			if(first -> data == last -> data)
			{
				if(first -> next -> data == last -> previous -> data)
				{
					cout<<"It's a palindrome!"<<endl;
				}
				else
				{
					cout<<"It's not a palindrome!"<<endl;
				}
			}
			else
			{
				cout<<"It's not a palindrome!"<<endl;
			}	
		}
		else
		{	
			if(first -> data == last -> data)
			{
				if(first -> next -> data == last -> previous -> data)
				{
					cout<<"It's a palindrome!"<<endl;
				}
				else
				{
					cout<<"It's not a palindrome!"<<endl;
				}
			}
			else
			{
				cout<<"It's not a palindrome!"<<endl;
			}				
		}
	}	
}










