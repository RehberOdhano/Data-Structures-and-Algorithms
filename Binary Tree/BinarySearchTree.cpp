#include <iostream>
#include <bits/stdc++.h>
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
void Search(BST_node* ptr, int num); 
double averageOfAllNodes(BST_node* s);
BST_node* deleteNode(BST_node* ptr, int num);
BST_node* minValue(BST_node* m);
int maxValue(BST_node* m);
int FindHeightOfBST(BST_node* root);

int numberOfNodes;
double sum;

int main()
{
	cout<<"No. of Nodes: ";
	cin>>numberOfNodes;
	cout<<endl;	
	
	//inserting nodes in BST
	for(int i = 1; i <= numberOfNodes; i++)
	{
		Insert();
	}
	cout<<endl;
	
	//display the elements of the BST in pre-order
	preOrderTraversal(rootNode);
	cout<<endl;
	
	//search user-defined value
	int num;
	cout<<"Number to be searched: ";
	cin>>num;
	Search(rootNode, num);	
	
	//find the average of all the nodes
	cout<<"Average: "<<averageOfAllNodes(rootNode)<<endl;
	
	//find the min and max in the BST
	cout<<"Minimum: "<<(minValue(rootNode)) -> data<<endl;
	cout<<"Maximum: "<<maxValue(rootNode)<<endl;
	
	//delete a user-defined node
	/*
	int n;
	cout<<"Enter a number you want to delete: ";
	cin>>n;
	cout<<endl;
	deleteNode(rootNode, n);
	
	//display the elements of the BST in pre-oder after deletion
	preOrderTraversal(rootNode);
	cout<<endl;
	*/
	
	
	//display the elements of the BST in post-order
	postOrderTraversal(rootNode);
	cout<<endl;
	
	//display the elements of the BST in in-order
	InOrderTraversal(rootNode);
	cout<<endl;
	
	//Height of BST
	/*
	int result = FindHeightOfBST(rootNode);
	if(result == -1)
	{
		cout<<"Tree is empty!"<<endl;
	}
	else
	{
		cout<<"Height: "<<result<<endl;
	}
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

double averageOfAllNodes(BST_node* s)
{
	if(numberOfNodes == 0)
	{
		return sum;
	}
	else if(numberOfNodes == 1)
	{
		return s -> data;
	}
	else
	{
		if(s != NULL)
		{
			sum += s -> data;
			averageOfAllNodes(s -> left);
			averageOfAllNodes(s -> right);
		}
		return (sum / numberOfNodes);
	}
}

BST_node* deleteNode(BST_node* ptr, int num)
{
	if(ptr == NULL)
	{
		return ptr;
	}
	else if(num < ptr -> data)
	{
		ptr -> left = deleteNode(ptr -> left, num);
	}
	else if(num > ptr -> data)
	{
		ptr -> right = deleteNode(ptr -> right, num);
	}
	
	else 
	{
		//leaf Node - No child
		if(ptr -> left == NULL && ptr -> right == NULL)
		{ 
			delete ptr;
			ptr = NULL;
		}
		
		//One child 
		else if(ptr -> left == NULL)
		{
			BST_node* temp = ptr;
			ptr = ptr -> right;
			delete temp;
		}
		else if(ptr -> right == NULL)
		{
			BST_node* temp = ptr;
			ptr = ptr -> left;
			delete temp;
		}
		//2 children
		else
		{ 
			BST_node* temp = minValue(ptr -> right);
			ptr -> data = temp -> data;
			ptr -> right = deleteNode(ptr -> right, temp -> data);
		}
	}
	return ptr;	
}

BST_node* minValue(BST_node* m)
{
	if(m == NULL)
	{
		cout<<"Tree is empty!"<<endl;
		return NULL;
	}
	else
	{
		while(m -> left != NULL)
		{
			m = m -> left;
		}
		return m;
	}
}

int maxValue(BST_node* m)
{
	if(m == NULL)
	{
		cout<<"Tree is empty!"<<endl;
		return -1;
	}
	else
	{
		while(m -> right != NULL)
		{
			m = m -> right;
		}
		return m -> data;
	}	
}

void Search(BST_node* ptr, int num)
{
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

/*
int FindHeightOfBST(BST_node* root)
{
	
}
*/
