#include <iostream>
using namespace std;

struct node{
	int data;
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
void printListInReverseOrder();
void arrangeListInReverseOrder();
void palindrome();
void swapNodeLocation();
void swapNodes();
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
		cout<<"8. Print The Linked List In Reverse Order"<<endl;
		cout<<"9. Arrange The List In Reverse Order"<<endl;
		cout<<"10. Check Whether the list is palindrome or not"<<endl;
		cout<<"11. Swap Node's Location"<<endl;
		cout<<"12. Swap Nodes"<<endl;
		cout<<"13. Display"<<endl;
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
				printListInReverseOrder();
				break;
			case 9:
				arrangeListInReverseOrder();
				break;
			case 10:
				palindrome();
				break;
			case 11:
				swapNodeLocation();
				break;
			case 12:
				swapNodes();
				break;
			case 13:
				display();
				break;
			default:
				cout<<"Thank you"<<endl;
				break;
		}
	}
	while(choices != 0);
	
}

void display()
{	
	cout<<"*****Display Method*****"<<endl;
	cout<<"Linked List: ";
	if(head == NULL)
	{
		cout<<"EMPTY"<<endl;
	}
	else
	{
		node* move = head;
		while(move != NULL)
		{
			cout<<move -> data<<"->";
			move = move -> next;
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
	if(head == NULL)
	{
		cout<<"Intially, the list is empty!"<<endl;
		cout<<"Inserting first node in the list..."<<endl;
		node* firstNode = new node();
		cout<<"Enter a number: ";
		cin>>firstNode -> data;
		cout<<endl;
		head = firstNode;
		tail = firstNode;
		firstNode -> next = NULL;
	}
	else
	{
		node* nodeAtStart = new node();
		cout<<"Enter a number: ";
		cin>>nodeAtStart -> data;
		cout<<endl;
		nodeAtStart -> next = head;
		head = nodeAtStart;
	}
}

void insertANodeAtEnd()
{
	if(head == NULL)
	{
		cout<<"Intially, the list is empty!"<<endl;
		cout<<"Inserting a node in the list..."<<endl;
		node* newNode = new node();
		cout<<"Enter a number: ";
		cin>>newNode -> data;
		cout<<endl;
		head = newNode;
		tail = newNode;
		newNode -> next = NULL;
	}
	else
	{
		node* newNode = new node();
		cout<<"Enter a number: ";
		cin>>newNode -> data;
		cout<<endl;
		while(tail -> next != NULL)
		{
			tail = tail -> next;
		}
		tail -> next = newNode;
		newNode -> next = NULL;
	}
}

void insertANodeAtNthPosition()
{		
	int position;
	int numberOfNodes = 0;
	cout<<"Enter a position where you want to enter a node: ";
	cin>>position;
	cout<<endl;
	
	node* mover = head;
	while(mover != NULL)
	{
		mover = mover -> next;
		numberOfNodes++;
	}
	
	if(head == NULL)
	{
		cout<<"List is empty!"<<endl;
	}
	else if(position == 1)
	{
		insertANodeAtStart();
	}
	else if(position == (numberOfNodes + 1))
	{
		insertANodeAtEnd();
	}
	else if(position > (position + 1))
	{
		cout<<"Invalid position!"<<endl;
	}
	else
	{
		node* move = head;
		node* nodeAtNthPosition = new node();
		cout<<"Enter a number: ";
		cin>>nodeAtNthPosition -> data;
		cout<<endl;
	
		for(int count = 1; count <= (position - 2); count++)
		{
			move = move -> next;
		}
		nodeAtNthPosition -> next = move -> next;
		move -> next = nodeAtNthPosition;
	}
}

void deleteFirstNode()
{
	node* firstNodeDeleter = head;
	if(head == NULL)
	{
		cout<<"List is empty!"<<endl;
	}
	else
	{
		head = head -> next;
		delete firstNodeDeleter;
	}
}

void deleteLastNode()
{
	int numberOfNodes = 0;
	node* move = head;
	while(move != NULL)
	{
		move = move -> next;
		numberOfNodes++;
	}
	
	if(head == NULL)
	{
		cout<<"List is empty!"<<endl;
	}
	else
	{
		node* lastNodeDeleter = head;
		node* temp = head;
		
		for(int counter = 1; counter <= (numberOfNodes - 2); counter++)
		{
			temp = temp -> next;
		}
		
		while(lastNodeDeleter -> next != NULL)
		{
			lastNodeDeleter = lastNodeDeleter -> next;
		}
		delete lastNodeDeleter;
		temp -> next = NULL;
	}
}

void deleteNodeAtNthPosition()
{
	int position;
	cout<<"Enter a position of node you want to delete: ";
	cin>>position;
	cout<<endl;
	
	int numberOfNodes = 0;
	node* move = head;
	while(move != NULL)
	{
		move = move -> next;
		numberOfNodes++;
	}
	
	if(head == NULL)
	{
		cout<<"List is empty!"<<endl;
	}
	else if(position == 1)
	{
		deleteFirstNode();
	}
	else if(position == numberOfNodes)
	{
		deleteLastNode();
	}
	else if(position > (numberOfNodes))
	{
		cout<<"Invalid position!"<<endl;
	}
	else
	{
		node* temp = head;
		node* nthPositionNodeDeleter = head;
		for(int count = 1; count <= (position - 1); count++)
		{
			nthPositionNodeDeleter = nthPositionNodeDeleter -> next;
		}
		temp = nthPositionNodeDeleter -> next;
		delete nthPositionNodeDeleter;
		
		node* helper = head;
		for(int counter = 1; counter <= (position - 2); counter++)
		{
			helper = helper -> next;
		}
		helper -> next = temp;
	}
}

void swapNodeLocation()
{
	node* posOne = head;
	node* posTwo = head;
	int dataCarrier = 0;
	
	int positionOne;
	int positionTwo;
	cout<<"Enter the position: ";
	cin>>positionOne;
	cout<<"Enter the position: ";
	cin>>positionTwo;
	cout<<endl;	
	
	int totalNodes = 0;
	node* nodeCounter = head;
	while(nodeCounter != NULL)
	{
		nodeCounter = nodeCounter -> next;
		totalNodes++;
	}
	
	if(positionOne <= 0 || positionOne > totalNodes || positionTwo <= 0 || positionTwo > totalNodes)
	{
		cout<<"You've entered invalid positions!"<<endl;
	}
	
	else if(totalNodes == 0 || totalNodes == 1)
	{
		cout<<"Nodes can't be swaped!"<<endl;
		cout<<totalNodes<<" nodes are available!"<<endl;
	}
	
	else
	{
		for(int count = 1; count <= (positionOne - 1); count++)
		{
			posOne = posOne -> next;
		}
		
		for(int count = 1; count <= (positionTwo - 1); count++)
		{
			posTwo = posTwo -> next;
		}
		
		dataCarrier = posOne -> data;
		posOne -> data = posTwo -> data;
		posTwo -> data = dataCarrier;
	}
}

void printListInReverseOrder()
{	
	int nodesInTheList = 1;
	if(head == NULL)
	{
		nodesInTheList = 0;
	}
	else
	{
		node* traverseInTheList = head;
		while(traverseInTheList -> next != NULL)
		{
			traverseInTheList = traverseInTheList -> next;
			nodesInTheList++;
		}
	}
	
	node* headNode = head;
	node* lastNode = head;
	node* temp = head;
	node* mover = head;
	node* lastNodeKeep = head;
	
	if(nodesInTheList == 0 || nodesInTheList == 1)
	{
		cout<<"Linked List can't be reversed!"<<endl;
	}
	
	else
	{
		while(lastNode -> next != NULL)
		{	
			lastNode = lastNode -> next;
		}
			
		for(int count = 1; count <= (nodesInTheList - 2); count++)
		{
			temp = temp -> next; 
		}
			
		lastNodeKeep = temp -> next;
		lastNode -> next = headNode;
			
		for(int count = 1; count <= (nodesInTheList - 2); count++)
		{
			for(int counter = count; counter <= (nodesInTheList - 2); counter++)
			{
				mover = mover -> next;
			}
			mover -> next = lastNode -> next;
			lastNode -> next = mover;
			lastNode = mover; 
			mover = headNode;
		}
		headNode -> next = NULL;
		head = lastNodeKeep;
	}
}

void arrangeListInReverseOrder()
{
	int nodesInTheList = 1;
	if(head == NULL)
	{
		nodesInTheList = 0;
	}
	else
	{
		node* traverseInTheList = head;
		while(traverseInTheList -> next != NULL)
		{
			traverseInTheList = traverseInTheList -> next;
			nodesInTheList++;
		}
	}
	
	node* temp = head;
	node* mover = head;
	int dataCarrier = 0;
	
	if(nodesInTheList == 0 || nodesInTheList == 1)
	{
		cout<<"Linked List can't be arranged in reverse order!"<<endl;
	}
	
	else
	{
		for(int count = 1; count <= (nodesInTheList / 2); count++)
		{
			for(int counter = count; counter <= (nodesInTheList - 1); counter++)
			{
				temp = temp -> next;
			}
			dataCarrier = temp -> data;
			temp -> data = mover -> data;
			mover -> data = dataCarrier;
			mover = mover -> next;
			temp = head;
		}	
	}
}

void palindrome()
{
	int nodeCalculator = 1;
	
	node* leadNode = head;
	node* trailNode = head;
	node* temp = head;
	node* secondNode = leadNode -> next;
	node* thirdNode = secondNode -> next;
	
	
	while(trailNode -> next != NULL)
	{
		trailNode = trailNode -> next;
		nodeCalculator++;
	}
	
	if(nodeCalculator % 2 == 0)
	{
		if(nodeCalculator % 2 == 0 && nodeCalculator > 4)
		{
			for(int count = 1; count <= (nodeCalculator - 2); count++)
			{
				temp = temp -> next;
			}
			if(leadNode -> data == trailNode -> data)
			{
				if(secondNode -> data == temp -> data)
				{
					if(thirdNode -> data == thirdNode -> next -> data)
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
				cout<<"It's not a palindrome!"<<endl;
			}
		}
		else
		{
			for(int count = 1; count <= (nodeCalculator - 2); count++)
			{
				temp = temp -> next;
			}
		
			if(leadNode -> data == trailNode -> data)
			{
				if(secondNode -> data == temp -> data)
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
	
	else
	{
		if(nodeCalculator > 5)
		{
			node* middleNode = head;
			for(int count = 1; count <= 3; count++)
			{
				middleNode = middleNode -> next;
			}
			
			for(int count = 1; count <= (nodeCalculator - 2); count++)
			{
				temp = temp -> next;
			}
			
			if(leadNode -> data == trailNode -> data)
			{
				if(secondNode -> data == temp -> data)
				{
					if(thirdNode -> data == middleNode -> next -> data)
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
				cout<<"It's not a palindrome!"<<endl;
			}
		}
		else
		{
			for(int count = 1; count <= (nodeCalculator - 2); count++)
			{
				temp = temp -> next;
			}
		
			if(leadNode -> data == trailNode -> data)
			{
				if(leadNode -> next -> data == temp -> data)
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

void swapNodes()
{
	int positionOne;
	int positionTwo;
	cout<<"Enter the position: ";
	cin>>positionOne;
	cout<<"Enter the position: ";
	cin>>positionTwo;
	
	int totalNodes = 0;
	node* nodeCounter = head;
	while(nodeCounter != NULL)
	{
		nodeCounter = nodeCounter -> next;
		totalNodes++;
	}
	
	node* posOne = head;
	node* posTwo = head;
	node* previousOne = head;
	node* previousTwo = head;
	node* keepNode = NULL;
	
	if(head == NULL)
	{
		cout<<"Linked List is empty!"<<endl;
	}
	else if(positionOne <= 0 || positionOne > totalNodes || positionTwo <= 0 || positionTwo > totalNodes)
	{
		cout<<"You've entered invalid positions!"<<endl;
	}
	
	else if(positionOne == positionTwo)
	{
		cout<<"You've entered both positions same!"<<endl;
	}
	
	else if(totalNodes == 0 || totalNodes == 1)
	{
		cout<<"Nodes can't be swapped!"<<endl;
	}
	else
	{
		if(positionOne != 1 && (positionTwo > (positionOne + 1)))
		{
			if((positionTwo != totalNodes))
			{
				for(int count = 1; count <= (positionOne - 1); count++)
				{	
					posOne = posOne -> next;
				}
			
				for(int count = 1; count <= (positionTwo - 1); count++)
				{
					posTwo = posTwo -> next;
				}
			
				for(int count = 1; count <= (positionOne - 2); count++)
				{
					previousOne = previousOne -> next;
				}	
			
				for(int count = 1; count <= (positionTwo - 2); count++)
				{
					previousTwo = previousTwo -> next;
				}
				keepNode = posTwo -> next;
				previousOne -> next = posTwo;
				posTwo -> next = posOne -> next;
				previousTwo -> next = posOne;
				posOne -> next = keepNode;
			}
			else
			{
				for(int count = 1; count <= (positionOne - 1); count++)
				{	
					posOne = posOne -> next;
				}
			
				for(int count = 1; count <= (positionTwo - 1); count++)
				{
					posTwo = posTwo -> next;
				}
			
				for(int count = 1; count <= (positionOne - 2); count++)
				{
					previousOne = previousOne -> next;
				}	
			
				for(int count = 1; count <= (positionTwo - 2); count++)
				{
					previousTwo = previousTwo -> next;
				}
				
				previousOne -> next = posTwo;
				posTwo -> next = posOne -> next;
				previousTwo -> next = posOne;
				posOne -> next = NULL;
			}
		}
		else if(positionOne == 1 && positionTwo > 2)
		{
			if((positionTwo < totalNodes))
			{
				for(int count = 1; count <= (positionOne - 1); count++)
				{
					posOne = posOne -> next;
				}
			
				for(int count = 1; count <= (positionTwo - 1); count++)
				{
					posTwo = posTwo -> next;
				}
			
				for(int count = 1; count <= (positionOne - 2); count++)
				{
					previousOne = previousOne -> next;
				}
			
				for(int count = 1; count <= (positionTwo - 2); count++)
				{
					previousTwo = previousTwo -> next;
				}
				previousOne = posOne -> next;
				posOne -> next = posTwo -> next;
				posTwo -> next = previousOne;
				previousTwo -> next = posOne;
				head = posTwo;
			}
			else
			{
				for(int count = 1; count <= (positionOne - 1); count++)
				{
					posOne = posOne -> next;
				}
			
				for(int count = 1; count <= (positionTwo - 1); count++)
				{
					posTwo = posTwo -> next;
				}
			
				for(int count = 1; count <= (positionOne - 2); count++)
				{
					previousOne = previousOne -> next;
				}
			
				for(int count = 1; count <= (positionTwo - 2); count++)
				{
					previousTwo = previousTwo -> next;
				}
				previousOne = posOne -> next;
				posTwo -> next = previousOne;
				previousTwo -> next = posOne;
				posOne -> next = NULL;
				head = posTwo;	
			}
			
		}
		// if two nodes are adjacent
		else 
		{
			if(positionOne == 1)
			{	
				for(int count = 1; count <= (positionTwo - 1); count++)
				{
					posTwo = posTwo -> next;
				}
				
				posOne -> next = posTwo -> next;
				posTwo -> next = posOne;
				head = posTwo;
			}
			else if(positionTwo == totalNodes)
			{
				for(int count = 1; count <= (positionOne - 1); count++)
				{
					posOne = posOne -> next;
				}
			
				for(int count = 1; count <= (positionTwo - 1); count++)
				{
					posTwo = posTwo -> next;
				}
			
				for(int count = 1; count <= (positionOne - 2); count++)
				{
					previousOne = previousOne -> next;
				}
				
				previousOne -> next = posTwo;
				posTwo -> next = posOne;
				posOne -> next = NULL;
			}
			else
			{
				for(int count = 1; count <= (positionOne - 1); count++)
				{
					posOne = posOne -> next;
				}
			
				for(int count = 1; count <= (positionTwo - 1); count++)
				{
					posTwo = posTwo -> next;
				}
			
				for(int count = 1; count <= (positionOne - 2); count++)
				{
					previousOne = previousOne -> next;
				}
				
				previousOne -> next = posTwo;
				posOne -> next = posTwo -> next;
				posTwo -> next = posOne;
			}
		}		
	}
}


