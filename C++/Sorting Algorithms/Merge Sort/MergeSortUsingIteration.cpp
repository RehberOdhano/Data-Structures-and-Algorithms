#include <iostream>
using namespace std;

int main()
{
	int size;
	cout<<"Enter the length of the array: ";
	cin>>size;
	cout<<endl;
	
	int originalArr[size];
	for(int index = 0; index < size; index++)
	{
		cout<<"Enter a number: ";
		cin>>originalArr[index];
		cout<<endl;
	}
	
	//Before Sorting
	cout<<"Unsorted Array: ";
	for(int index = 0; index < size; index++)
	{
		cout<<originalArr[index]<<" ";
	}
	cout<<endl;
	
	//merge sort using iteration
	int newArr[size];
	
	for(int count = 1; count <= ((size / 2) - 2); count++)
	{
		int i = 0;
		int j = 2 * count;
		while(i < (size - 1) && j <= (size - 1))
		{
			if(originalArr[i] > originalArr[j])
			{
				newArr[i] = originalArr[j];
				newArr[j] = originalArr[i];
				i++;
				j++;
			}
			else
			{
				newArr[i] = originalArr[i];
				newArr[j] = originalArr[j];
				i++;
				j++;
			}
		}
		
		for(int index = 0; index < size; index++)
		{
			originalArr[index] = newArr[index];
		}
	}
	
	cout<<"After Sorting: ";
	for(int index = 0; index < size; index++)
	{
		cout<<originalArr[index]<<" ";
	}
	cout<<endl;	
}
