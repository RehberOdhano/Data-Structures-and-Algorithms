#include <iostream>
using namespace std;

void SelectionSortUsingRecursion(int startIndex, int lastIndex);
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
	
	cout<<"Before sorting..."<<endl;
	cout<<"Unsorted Array: ";
	for(int index = 0; index < lengthOfArray; index++)
	{
		cout<<array[index]<<" ";
	}
	cout<<endl;
	
	//sorting in decreasing order using selection sort
	/*for(int count = 0; count < lengthOfArray; count++)
	{
		int max = array[count];
		for(int index = count; index < lengthOfArray;)
		{
			if(max >= array[index])
			{
				index++;
			}
			else
			{
				max = array[index];
				array[index] = array[count];
				array[count] = max;
				index++;
			}
		}
	}
	*/
	
	//selection sort in decreasing order using recursion
	SelectionSortUsingRecursion(0, 1);
	
	cout<<"After sorting..."<<endl;
	cout<<"Sorted Array: ";
	for(int position = 0; position < lengthOfArray; position++)
	{
		cout<<array[position]<<" ";
	}
	cout<<endl;
}

void SelectionSortUsingRecursion(int startIndex, int lastIndex)
{
	if(lengthOfArray == 1 || startIndex == lengthOfArray)
	{
		return;
	}
	else
	{
		if(lastIndex == lengthOfArray)
		{
			SelectionSortUsingRecursion(startIndex += 1, startIndex + 1);
		}
		else
		{
			if(array[startIndex] > array[lastIndex])
			{
				SelectionSortUsingRecursion(startIndex, lastIndex += 1);
			}
			else
			{
				int swap = array[lastIndex];
				array[lastIndex] = array[startIndex];
				array[startIndex] = swap;
				SelectionSortUsingRecursion(startIndex, lastIndex += 1);
			}
		}
	}
}
