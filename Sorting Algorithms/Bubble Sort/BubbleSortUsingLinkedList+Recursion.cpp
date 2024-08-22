#include <iostream>
using namespace std;

struct node{
	int data;
	node* next = NULL;
};

node* head = NULL;
node* tail = NULL;
node* move = NULL;

int BubbleSortUsingRecursion(int count);

int numberOfNodes;

int main()
{
	cout<<"No. of Nodes: ";
	cin>>numberOfNodes;
	cout<<endl;
	
	for(int nodes = 1; nodes <= numberOfNodes; nodes++)
	{
		if(head == NULL)
		{
			node* firstNode = new node();
			cout<<"Enter a number: ";
			cin>>firstNode -> data;
			firstNode -> next = NULL;
			head = firstNode;
			tail = firstNode;
		}
		else
		{
			node* newNode = new node();
			cout<<"Enter a number: ";
			cin>>newNode -> data;
			tail -> next = newNode;
			newNode -> next = NULL;
			tail = newNode;
		}
	}
	
	cout<<endl;
	node* temp = head;
	cout<<"Before Sorting..."<<endl;
	cout<<"Linked List: ";
	while(temp != NULL)
	{
		cout<<temp -> data<<"->";
		temp = temp -> next;
	}
	cout<<endl;
	temp = head;
	
	//Selection Sort using linked list + recursion
	move = head;
	int result = BubbleSortUsingRecursion(1);
	if(result == -1)
	{
		cout<<"Only one element is present..."<<endl;
	}
	else
	{
		cout<<"After Sorting..."<<endl;
		cout<<"Linked List: ";
		for(int counter = 1; counter <= numberOfNodes; counter++)
		{
			cout<<temp -> data<<"->";
			temp = temp -> next;
		}
		cout<<endl;
	}
}

int BubbleSortUsingRecursion(int count)
{
	int swapper = 0;
	if(numberOfNodes == 1 || count == numberOfNodes)
	{
		return 1;
	}
	else if(move -> next == NULL)
	{
		move = head;
		BubbleSortUsingRecursion(count + 1);
	}
	else if((move -> data) > (move -> next -> data))
	{
		swapper = move -> next -> data;
		move -> next -> data = move -> data;
		move -> data = swapper;
		move = move -> next;
		BubbleSortUsingRecursion(count);
	}
	else
	{
		move = move -> next;
		BubbleSortUsingRecursion(count);
	}	
}
