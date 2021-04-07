#include <iostream>
using namespace std;

int main()
{
	int vertices;
	cout<<"Enter number of vertices: ";
	cin>>vertices;
	cout<<endl;
	
	int matrix[vertices][vertices];
	
	
	//adjacency matrix
	for(int row = 0; row < vertices; row++)
	{
		for(int column = 0; column < vertices; column++)
		{
			cout<<"Enter the weight of the edge: ";
			cin>>matrix[row][column];
		}
		cout<<endl;
	}
	
	//print the matrix
	for(int row = 0; row < vertices; row++)
	{
		for(int column = 0; column < vertices; column++)
		{
			cout<<matrix[row][column]<<" ";
		}
		cout<<endl;
	}
	
	//print the edges
	for(int i = 0; i < vertices; i++)
	{
		for(int j = 0; j < vertices; j++)
		{
			if(matrix[i][j] == 0)
			{
				cout<<"There is no edge between "<<i<<" and "<<j<<endl;
			}
			else
			{
				if(i == j && matrix[i][j] > 0)
				{
					cout<<"There is an edge between "<<i<<" and "<<j<<" and it's a self-loop!"<<endl;
				}
				else
				{
					cout<<"There is an edge between "<<i<<" and "<<j<<endl;
				}
			}
		}
	}
	
	//finding adjacent nodes and self loops
	int input;
	cout<<"Enter a node number you want to find the adjacent nodes of: ";
	cin>>input;
	cout<<endl;
	
	if(input < 0 || input >= vertices)
	{
		cout<<"Enter a valid value (Range: 0 <= input < "<<vertices<<")"<<endl;
	}
	else
	{
		for(int i = 0; i < vertices; i++)
		{
			if(matrix[input][i] == 0)
			{
				continue;
			}
			else
			{
				if(i == input && matrix[i][input] > 0)
				{
					cout<<i<<"th node is adjacent to "<<input<<"th node and the edge is a self loop!"<<endl;
				}
				else
				{
					cout<<i<<"th node is adjacent to "<<input<<"th node"<<endl;
				}
			}
		}
	}	
}
