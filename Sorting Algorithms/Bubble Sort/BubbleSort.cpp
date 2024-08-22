#include <iostream>
using namespace std;

int BubbleSortUsingRecursion(int index, int length);

int lengthOfArray;
int array[0];
int count = 1;

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
		cout<<endl;
	}
	
	cout<<"Unsorted Array: ";
	for(int index = 0; index < lengthOfArray; index++)
	{
		cout<<array[index]<<" ";
	}
	cout<<endl;
	
	
	BubbleSortUsingRecursion(0, lengthOfArray);
	
	//sorting using bubble sort
	/*int swapper = 0;
	for(int count = 0; count < lengthOfArray; count++)
	{
		for(int index = 0; index < lengthOfArray; )
		{
			if(index == (lengthOfArray - 1))
			{
				break;
			}
			else if(array[index] > array[index + 1])
			{
				swapper = array[index + 1];
				array[index + 1] = array[index];
				array[index] = swapper;
			}
			else
			{
				index++;
			}
		}
	}
	*/
	cout<<"Sorted Array: ";
	for(int position = 0; position < lengthOfArray; position++)
	{
		cout<<array[position]<<" ";
	}
	cout<<endl;

}

int BubbleSortUsingRecursion(int index, int length)
{
	int swapper = 0;
	if(count == length)
	{
		return 1;
	}
	else if(index == (length - 1))
	{
		count++;
		BubbleSortUsingRecursion(0, length);
	}
	else if(array[index] > array[index + 1])
	{
		swapper = array[index + 1];
		array[index + 1] = array[index];
		array[index] = swapper;
		BubbleSortUsingRecursion(index += 1, length);
	}
	else
	{
		BubbleSortUsingRecursion(index += 1, length);
	}
}
