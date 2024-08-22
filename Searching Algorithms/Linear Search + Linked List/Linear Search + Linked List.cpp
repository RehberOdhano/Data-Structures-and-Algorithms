#include <iostream>
using namespace std;

struct node{
	int data;
	node* next = NULL;
};

node* head = NULL;
node* tail = NULL;
int numberOfNodes;

int LinearSearch();

int main()
{
	cout<<"Linear Search Using Linked List"<<endl;
	cout<<"Lets first store some data in our linked list..."<<endl;
	
	cout<<"No. of nodes: ";
	cin>>numberOfNodes;
	cout<<endl;
	
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
	
	int elementReturned = LinearSearch();
	
	if(elementReturned == -1)
	{
		cout<<"Given Number is not found"<<endl;
	}
	else
	{
		cout<<"Given number is present at index "<<elementReturned<<endl;
	}
}

int LinearSearch()
{
	int input;
	cout<<"Number to be searched: ";
	cin>>input;
	cout<<endl;
	
	for(int count = 0; count < numberOfNodes; count++)
	{
		if(head -> data == input)
		{
			return count;
		}
		else
		{
			head = head -> next;
		}
	}
	return -1;
}
