#include <iostream>
using namespace std;

struct node{
	int data;
	node* next = NULL;
};

node* head = NULL;
node* tail = NULL;

void SelectionSortUsingLinkedList();

int numberOfNodes;

int main()
{
	cout<<"No. of Nodes: ";
	cin>>numberOfNodes;
	cout<<endl;
	
	for(int count = 1; count <= numberOfNodes; count++)
	{
		if(head == NULL)
		{
			node* firstNode = new node();
			cout<<"Enter a number: ";
			cin>>firstNode -> data;
			firstNode -> next = NULL;
			head = tail = firstNode;
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
	
	//Display elements before sorting
	cout<<"Before Sorting..."<<endl;
	cout<<"Unsorted Linked List: ";
	node* temp = head;
	while(temp != NULL)
	{
		cout<<temp -> data<<"->";
		temp = temp -> next;
	}
	cout<<endl;
	
	//selection sort using linked list
	SelectionSortUsingLinkedList();
	
	//Display elements after sorting
	cout<<"After Sorting..."<<endl;
	cout<<"Sorted Linked List: ";
	temp = head;
	while(temp != NULL)
	{
		cout<<temp -> data<<"->";
		temp = temp -> next;
	}
	cout<<endl;	
	
}

void SelectionSortUsingLinkedList()
{
	int swap = 0;	
	if(numberOfNodes == 1)
	{
		return;
	}
	else
	{
		node* max = head;
		node* maxFinder = max -> next;
	
		while(max -> next != NULL)
		{
			if(maxFinder -> data > max -> data)
			{
				swap = maxFinder -> data;
				maxFinder -> data = max -> data;
				max -> data = swap;	
			}
			else if(maxFinder -> next == NULL)
			{
				max = max -> next;
				maxFinder = max -> next;
			}
			else
			{
				maxFinder = maxFinder -> next;
			}
		}
	}	
}

