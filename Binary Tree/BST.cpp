#include <iostream>
using namespace std;

// BST -> binary search tree
struct BST_node{
	int data;
	BST_node* left = NULL; //points to left child 
	BST_node* right = NULL; //points to right child
};

//to store the address of root node
BST_node* rootNode = NULL;

void Insert();
void preOrderTraversal(BST_node* root);
void postOrderTraversal(BST_node* root);
void InOrderTraversal(BST_node* root);
void Search(); 
void averageOfAllNodes(BST_node* s);
void deleteNode();
void minValue(BST_node* m);
void maxValue(BST_node* m);
int minValueUsingRecursion(BST_node* m);
int maxValueUsingRecursion(BST_node* m);
BST_node* SearchForDeletion(BST_node* ptr, int num);

int main()
{
	
	int choices;
	do
	{
		cout<<"MENU"<<endl;
		cout<<"1. Insert Nodes"<<endl;
		cout<<"2. PreOder Traversal"<<endl;
		cout<<"3. PostOder Traversal"<<endl;
		cout<<"4. InOder Traversal"<<endl;
		cout<<"5. Search an element"<<endl;
		cout<<"6. Find the average of nodes in BST"<<endl;
		cout<<"7. Find minimum"<<endl;
		cout<<"8. Find maximum"<<endl;
		cout<<"9. Delete a node"<<endl;
		cout<<"0. Exit"<<endl;
		
		cout<<"Enter your choice: ";
		cin>>choices;
		cout<<endl;
		switch(choices)
		{
			case 1:
				Insert();
				break;
			case 2:
				preOrderTraversal(rootNode);
				break;
			case 3:
				postOrderTraversal(rootNode);
				break;
			case 4:
				InOrderTraversal(rootNode);
				break;
			case 5:
				Search();
				break;
			case 6:
				averageOfAllNodes(rootNode);
				break;
			case 7:
				minValue(rootNode);
				break;
			case 8:
				maxValue(rootNode);
				break;
			case 9:
				deleteNode();
				break;
			default:
				cout<<"Thank You"<<endl;
				break;
		}
	} while(choices != 0);
	
	/*
	cout<<"No. of Nodes: ";
	cin>>numberOfNodes;
	cout<<endl;
	
	for(int i = 1; i <= numberOfNodes; i++)
	{
		Insert();
	}
	cout<<endl;
	
	preOrderTraversal(rootNode);
	cout<<endl;
	
	Search();
	
	cout<<"Average: "<<averageOfAllNodes(rootNode)<<endl;
	
	cout<<"Minimum: "<<minValue(rootNode)<<endl;
	cout<<"Maximum: "<<maxValue(rootNode)<<endl;
	cout<<"Minimum: "<<minValueUsingRecursion(rootNode)<<endl;
	cout<<"Maximum: "<<maxValueUsingRecursion(rootNode)<<endl;
	
	cout<<"PostOrder Traversal: ";
	postOrderTraversal(rootNode);
	cout<<endl;
	
	cout<<"InOrder Traversal: ";
	InOrderTraversal(rootNode);
	cout<<endl;
	*/
}

void preOrderTraversal(BST_node* root)
{	
	if(root == NULL)
	{
		return;
	}
	
	cout<<root -> data<<" ";
	preOrderTraversal(root -> left);
	preOrderTraversal(root -> right);
}

void postOrderTraversal(BST_node* root)
{
	if(root == NULL)
	{
		return;
	}
	
	postOrderTraversal(root -> left);
	postOrderTraversal(root -> right);
	cout<<root -> data<<" ";
}

void InOrderTraversal(BST_node* root)
{
	if(root == NULL)
	{
		return;
	}
	
	InOrderTraversal(root -> left);
	cout<<root -> data<<" ";
	InOrderTraversal(root -> right);	
}

void Insert()
{
	BST_node* newNode = new BST_node();
	cout<<"Enter a number: ";
	cin>>newNode -> data;
	newNode -> left = newNode -> right = NULL;
	
	if(rootNode == NULL)
	{
		rootNode = newNode;
	}
	else
	{
		BST_node* ptr = rootNode;
		BST_node* helper = rootNode;
		
		while(ptr != NULL)
		{
			helper = ptr;
			
			if(newNode -> data >= ptr -> data)
			{
				ptr = ptr -> right;
			}
			else
			{
				ptr = ptr -> left;
			}
		}
		
		if(newNode -> data >= helper -> data)
		{
			helper -> right = newNode;
		}
		else
		{
			helper -> left = newNode;
		}	 
	}
}

void Search()
{
	BST_node* ptr = rootNode;
	int num;
	cout<<"Enter a number you want to search: ";
	cin>>num;
	
	if(ptr == NULL)
	{
		cout<<"Tree is empty!"<<endl;
	}
	else
	{
		while(ptr != NULL)
		{
			if(num == ptr -> data)
			{
				break;
			}
			else
			{
				if(num > ptr -> data)
				{
					ptr = ptr -> right;
				}
				else
				{
					ptr = ptr -> left;
				}
			}
		}
		
		if(ptr == NULL)
		{
			cout<<"Number Not Found!"<<endl;
		}
		else
		{
			cout<<"Number Found!"<<endl;
		}
	}
}

void averageOfAllNodes(BST_node* s)
{	
	int numberOfNodes = 0;
	double sum = 0.0;
	
	if(numberOfNodes == 0)
	{
		cout<<sum<<endl;
	}
	else if(numberOfNodes == 1)
	{
		cout<<s -> data<<endl;
	}
	else
	{
		if(s != NULL)
		{
			sum += s -> data;
			numberOfNodes += 1;
			averageOfAllNodes(s -> left);
			averageOfAllNodes(s -> right);
		}
		cout<<"Average: "<<(sum / numberOfNodes)<<endl;
	}
}

void minValue(BST_node* m)
{
	if(m == NULL)
	{
		cout<<"Tree is empty!"<<endl;
	}
	else
	{
		while(m -> left != NULL)
		{
			m = m -> left;
		}
		cout<<"Minimum: "<<m -> data<<endl;
	}
}

void maxValue(BST_node* m)
{
	if(m == NULL)
	{
		cout<<"Tree is empty!"<<endl;
	}
	else
	{
		while(m -> right != NULL)
		{
			m = m -> right;
		}
		cout<<"Maximum: "<<m -> data<<endl;
	}	
}

int minValueUsingRecursion(BST_node* m)
{
	if(m == NULL)
	{
		cout<<"Tree is empty!"<<endl;
		return -1;
	}
	else if(m -> left == NULL)
	{
		return m -> data;
	}
	else
	{
		minValueUsingRecursion(m -> left);
	}
}

int maxValueUsingRecursion(BST_node* m)
{
	if(m == NULL)
	{
		cout<<"Tree is empty!"<<endl;
		return -1;
	}
	else if(m -> right == NULL)
	{
		return m -> data;
	}
	else
	{
		maxValueUsingRecursion(m -> right);
	}
}



