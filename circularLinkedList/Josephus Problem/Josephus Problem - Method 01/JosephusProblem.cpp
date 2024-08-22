#include <iostream>
using namespace std;

struct node{
	int data;
	node* next = NULL;
};

node* first = NULL;
node* last = NULL;
int lengthOfCircle;


int JosephusProblem(int length);

int main()
{
	while(true)
	{
		cout<<"Enter the length of circle(no. of nodes): ";
		cin>>lengthOfCircle;
		cout<<endl;
		if(lengthOfCircle <= 0)
		{
			cout<<"Enter a positive number: "<<endl;
		}
		else
		{
			break;
		}
	}
		
	for(int count = 1; count <= lengthOfCircle; count++)
	{
		if(first == NULL)
		{
			node* firstNode = new node();
			cout<<"Enter a number: ";
			cin>>firstNode -> data;
			cout<<endl;
			first = firstNode;
			last = firstNode;
			firstNode -> next = first;
		}
		else
		{
			node* newNode = new node();
			cout<<"Enter a number: ";
			cin>>newNode -> data;
			cout<<endl;
			last -> next = newNode;
			newNode -> next = first;
			last = newNode;
		}
	}
	
	int onlyLeft = JosephusProblem(lengthOfCircle);
	cout<<"Soldier "<<onlyLeft<<" survives"<<endl;
	
}

int JosephusProblem(int length)
{
	node* helper = first;
	
	for(int counter = 1; counter <= (length - 1); counter++)
	{
		node* deleter = helper;
		deleter = helper -> next;
		helper -> next = deleter -> next;
		deleter -> next = NULL;
		delete deleter;
		helper = helper -> next;
	}
	
	return (helper -> data);	
}


