#include <iostream>
using namespace std;

void InsertionSortUsingRecursion(int startIndex, int lastIndex);

int lengthOfArray;
int array[0];

int main()
{
	cout<<"Enter the length of the array: ";
	cin>>lengthOfArray;
	cout<<endl;
	
	array[lengthOfArray];
	
	for(int index = 0; index < lengthOfArray; index++)
	{
		cout<<"Enter a number: ";
		cin>>array[index];
	}
	cout<<endl;
	
	cout<<"Before sorting..."<<endl;
	cout<<"Unsorted Array: ";
	for(int index = 0; index < lengthOfArray; index++)
	{
		cout<<array[index]<<" ";
	}
	cout<<endl;
	
	//sorting in increasing order using insertion sort
	/*int swapper = 0;
	for(int index = 1; index < lengthOfArray; index++)
	{
		swapper = array[index];
		for(int count = 0; count <= (index - 1); )
		{
			if(array[index] < array[count])
			{
				for(int move = index; move > count; move--)
				{
					array[move] = array[move - 1];
					array[move - 1] = swapper;
				}
			}
			else
			{
				count++;
			}
		}
	}
	*/
	
	InsertionSortUsingRecursion(0, 1);
	
	cout<<"After sorting..."<<endl;
	cout<<"Sorted Array: ";
	for(int position = 0; position < lengthOfArray; position++)
	{
		cout<<array[position]<<" ";
	}
	cout<<endl;
}

void InsertionSortUsingRecursion(int startIndex, int lastIndex)
{	
	//sorting in ascending order
	if(lengthOfArray == 0 || lengthOfArray == 1 || lastIndex == lengthOfArray)
	{
		return;
	}
	else if(startIndex == -1)
	{
		InsertionSortUsingRecursion(startIndex + 1, lastIndex + 1);
	}
	else if(array[startIndex] <= array[lastIndex])
	{
		InsertionSortUsingRecursion(startIndex + 1, lastIndex + 1);
	}
	else
	{
		int swapper = array[lastIndex];
		array[lastIndex] = array[startIndex];
		array[startIndex] = swapper;
		InsertionSortUsingRecursion(startIndex - 1, lastIndex - 1);
	}

	//sorting in descending order
	/*
	if(lengthOfArray == 0 || lengthOfArray == 1 || lastIndex == lengthOfArray)
	{
		return;
	}
	else if(startIndex == -1)
	{
		InsertionSortUsingRecursion(startIndex + 1, lastIndex + 1);
	}
	else if(array[startIndex] >= array[lastIndex])
	{
		InsertionSortUsingRecursion(startIndex + 1, lastIndex + 1);
	}
	else
	{
		int swapper = array[lastIndex];
		array[lastIndex] = array[startIndex];
		array[startIndex] = swapper;
		InsertionSortUsingRecursion(startIndex - 1, lastIndex - 1);
	}
	*/	
}	
	
