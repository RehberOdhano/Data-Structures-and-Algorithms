#include <iostream>
using namespace std;

struct node{
	int data;
	node* next = NULL;
};

node* head = NULL;
node* tail = NULL;

node* _max = NULL;
node* max_finder = NULL;

void SelectionSortUsingLinkedListAndRecursion();
int numberOfNodes;
int swapper = 0;

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
	
	
	_max = head;
	max_finder = _max -> next;
	//Sorting elements using selection sort + recursion
	SelectionSortUsingLinkedListAndRecursion();
	
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

void SelectionSortUsingLinkedListAndRecursion()
{
	
	if(numberOfNodes == 1 || _max -> next == NULL)
	{
		return;
	}
	else
	{
		if(max_finder -> data > _max -> data)
		{
			swapper = max_finder -> data;
			max_finder -> data = _max -> data;
			_max -> data = swapper;	
		}
		else
		{
			if(max_finder -> next == NULL)
			{
				_max = _max -> next;
				max_finder = _max -> next;
			}
			else
			{
				max_finder = max_finder -> next;
			}
		}
		SelectionSortUsingLinkedListAndRecursion();
	}	
}
