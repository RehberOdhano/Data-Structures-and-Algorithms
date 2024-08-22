#include <iostream>
using namespace std;

struct node{
	int data;
	node* next = NULL;
	node* previous = NULL;
};

void InsertionSortUsingLinkedList();
void InsertionSortUsingLinkedListAndRecursion();


node* head = NULL;
node* tail = NULL;
node* _min = NULL;
node* min_checker = NULL;

int numberOfNodes;
int swapper = 0;

int main()
{
	cout<<"Enter the length of the linked list: ";
	cin>>numberOfNodes;
	
	for(int count = 1; count <= numberOfNodes; count++)
	{
		if(head == NULL)
		{
			node* firstNode = new node();
			cout<<"Enter a number: ";
			cin>>firstNode -> data;
			firstNode -> next = NULL;
			firstNode -> previous = NULL;
			head = tail = firstNode;
		}
		else
		{
			node* newNode = new node();
			cout<<"Enter a number: ";
			cin>>newNode -> data;
			tail -> next = newNode;
			newNode -> previous = tail;
			newNode -> next = NULL;
			tail = newNode;
		}
	}
	
	cout<<"Before Sorting..."<<endl;
	cout<<"Unsorted Linked List: ";
	node* temp = head;
	while(temp != NULL)
	{
		cout<<temp -> data<<"->";
		temp = temp -> next;
	}
	cout<<endl;
	
	//InsertionSortUsingLinkedList();
	_min = head;
	min_checker = _min -> next;
	InsertionSortUsingLinkedListAndRecursion();
	
	temp = head;
	cout<<"After Sorting..."<<endl;
	cout<<"Sorted Linked List: ";
	while(temp != NULL)
	{
		cout<<temp -> data<<"->";
		temp = temp -> next;
	}
	cout<<endl;
}

void InsertionSortUsingLinkedList()
{
	node* min = head;
	node* move = min -> next;
	node* previousToMove = head;
	node* helper = head;
	
	while(move != NULL)
	{
		if(numberOfNodes == 1)
		{
			break;
		}
		else if(move -> data < min -> data)
		{
			while(previousToMove -> next != move)
			{
				previousToMove = previousToMove -> next;
			}
			
			if(move -> next == NULL)
			{
				previousToMove -> next = NULL;
				move -> next = min;
				min -> previous = move;
				move -> previous = NULL;
				head = min = previousToMove = move;
			}
			else
			{
				previousToMove -> next = move -> next;
				move -> next -> previous = previousToMove;
				move -> next = min;
				min -> previous = move;
				move -> previous = NULL;
				head = min = move; 
				move = previousToMove -> next;
				previousToMove = head;
			}
		}
		else
		{
			helper = move;
			
			while(helper -> previous != NULL)
			{
				if(helper -> data > helper -> previous -> data)
				{
					move = move -> next;
					helper = move;
					break;
				}
				else
				{
					int swap = helper -> data;
					helper -> data = helper -> previous -> data;
					helper -> previous -> data = swap;
					helper = helper -> previous; 	
				}
			}
		}
	}
}

void InsertionSortUsingLinkedListAndRecursion()
{
	if(numberOfNodes == 1 || min_checker == NULL)
	{
		return;
	}
	else if(min_checker -> previous == NULL)
	{
		min_checker = min_checker -> next;
		InsertionSortUsingLinkedListAndRecursion();
	}	
	else if(min_checker -> data >= _min -> data)
	{
		if(min_checker -> data >= min_checker -> previous -> data)
		{
			min_checker = min_checker -> next;
		}
		else
		{
			swapper = min_checker -> data;
			min_checker -> data = min_checker -> previous -> data;
			min_checker -> previous -> data = swapper;
			min_checker = min_checker -> previous;
		}
		InsertionSortUsingLinkedListAndRecursion();
	}
	else
	{
		swapper = min_checker -> data;
		min_checker -> data = min_checker -> previous -> data;
		min_checker -> previous -> data = swapper;
		min_checker = min_checker -> previous;
		InsertionSortUsingLinkedListAndRecursion();
	}
}

