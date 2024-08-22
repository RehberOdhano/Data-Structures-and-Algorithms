#include <iostream>
using namespace std;

struct node{
	int data;
	node* next = NULL;
};

node* head = NULL;
node* tail = NULL;
node* mid = NULL;
int numberOfNodes;
int startingIndex = 0;
int midValue;
int lastIndex;

int BinarySearchUsingRecursion(int lastValue, int elementToBeSearched);

int main()
{
	cout<<"Binary Search Using Recursion..."<<endl;
	cout<<"Lets first store some data in our linked list..."<<endl;
	
	while(true)
	{
		cout<<"No. of nodes: ";
		cin>>numberOfNodes;
		cout<<endl;
		
		if(numberOfNodes <= 0)
		{
			cout<<"Enter a positive number: "<<endl;
		}
		else
		{
			break;
		}
	}
	
	for(int index = 0; index < numberOfNodes; index++)
	{
		if(head == NULL)
		{
			node* firstNode = new node();
			cout<<"Initially list is empty!"<<endl;
			cout<<"Storing first value..."<<endl;
			cout<<"Enter a number: "<<endl;
			cin>>firstNode -> data;
			firstNode -> next = NULL;
			head = firstNode;
			tail = firstNode;
			cout<<endl;
		}
		else
		{
			node* newNode = new node();
			cout<<"Enter a number: ";
			cin>>newNode -> data;
			tail -> next = newNode;
			newNode -> next = NULL;
			tail = newNode;
			cout<<endl;
		}
	}
	
	//sorting the linked list
	int swap = 0;
	node* helper = head;
	for(int count = 1; count <= (numberOfNodes / 2); count++)
	{
		while(helper -> next != NULL)
		{
			swap = helper -> data;
			if(swap > helper -> next -> data)
			{
				helper -> data = helper -> next -> data;
				helper -> next -> data = swap;
				helper = helper -> next;
			}
			else
			{
				helper = helper -> next;
			}
		}
		helper = head;
	}
	
	cout<<"Sorted Linked List: ";
	while(helper != NULL)
	{
		cout<<helper -> data<<"->";
		helper = helper -> next;
	}
	cout<<endl;
	
	lastIndex = (numberOfNodes - 1);
	
	int input;
	cout<<"Number to be searched: ";
	cin>>input;
	cout<<endl;
	
	int elementReturned = BinarySearchUsingRecursion(lastIndex, input);
	
	if(elementReturned == -1)
	{
		cout<<"Given Number is not found"<<endl;
	}
	else
	{
		cout<<"Given number is present at index "<<elementReturned<<endl;
	}
}

int BinarySearchUsingRecursion(int lastValue, int elementToBeSearched)
{
	mid = head;
	midValue = ((startingIndex + lastValue) / 2);
	
	for(int count = 1; count <= midValue; count++)
	{
		mid = mid -> next;
	}
	if(startingIndex == numberOfNodes || lastValue == -1)
	{
		return -1;
	}	
	else if(elementToBeSearched == mid -> data)
	{
		return midValue;
	}
	else if(elementToBeSearched > mid -> data)
	{
		startingIndex = midValue + 1;
		BinarySearchUsingRecursion(lastValue, elementToBeSearched);
	}
	else if(elementToBeSearched < mid -> data)
	{
		lastValue = midValue - 1;
		BinarySearchUsingRecursion(lastValue, elementToBeSearched);
	}
}
