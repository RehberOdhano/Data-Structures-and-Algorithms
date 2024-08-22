#include <iostream>
using namespace std;

struct node{
	int data;
	node* next = NULL;
};

node* head = NULL;
node* tail = NULL;
node* move = NULL;

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
	
	//Bubble sort using linked list
	int swapper = 0;
	for(int mover = 1; mover < numberOfNodes; mover++)
	{
		move = head;
		for(int count = 1; count < numberOfNodes; count++)
		{
			if((move -> data) > (move -> next -> data))
			{
				swapper = move -> next -> data;
				move -> next -> data = move -> data;
				move -> data = swapper;
				move = move -> next;
			}
			else
			{
				move = move -> next;
			}
		}
	}
	
	cout<<"After Sorting..."<<endl;
	cout<<"Linked List: ";
	for(int counter = 1; counter <= numberOfNodes; counter++)
	{
		cout<<temp -> data<<"->";
		temp = temp -> next;
	}
	cout<<endl;

}
