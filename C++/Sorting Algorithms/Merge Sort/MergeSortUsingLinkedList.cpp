#include <iostream>
using namespace std;

struct node{
	int data;
	node* next = NULL;
};

node* head = NULL;
node* tail = NULL;

void MergeSort();
void Merge();
int numberOfNodes;

int main()
{
	cout<<"Enter the length of linked list: ";
	cin>>numberOfNodes;
	cout<<endl;
	
	cout<<"Let's store some values in the linked list..."<<endl;
	for(int count = 1; count <= numberOfNodes; count++)
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
		cout<<endl;
	}
	
	cout<<"Before Sorting..."<<endl;
	cout<<"Linked List: ";
	node* temp = head;
	for(int count = 1; count <= numberOfNodes; count++)
	{
		cout<<temp -> data<<"->";
		temp = temp -> next;
	}
	cout<<endl;
	
	MergeSort(head, tail);
	
	cout<<"After Sorting..."<<endl;
	cout<<"Linked List: ";	
}

void MergeSort()
{

}

void Merge()
{
	
}
















