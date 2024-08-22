#include <iostream>
#define SIZE 6
using namespace std;

int BinarySearch(int arr[]);
int sortedArray[SIZE];
int arrayList[SIZE];
int middleValue;
int firstIndex = 0;
int lastIndex = (SIZE - 1);

int main()
{
	cout<<"Binary Search..."<<endl;
	cout<<"Lets store some data in the array first..."<<endl;
	
	int input;
	
	for(int index = 0; index < SIZE; )
	{
		cout<<"Enter a number from 0 to 9: ";
		cin>>input;
		cout<<endl;
		if(input < 0 || input > 9)
		{
			cout<<"Enter a valid input"<<endl;	
		}
		else
		{
			if(arrayList[input] > 0)
			{
				arrayList[input] = arrayList[input] + 1;
			}
			else
			{
				arrayList[input] = 1;
			}
			index++;
		}
	}
	
	//sorting the array
	int position = 0;
	for(int count = 0; count < SIZE;)
	{
		if(arrayList[count] > 0)
		{
			for(int move = 1; move <= arrayList[count]; move++)
			{
				sortedArray[position] = count;
				position++;
			}
		}
		count++;
	}
	
	
	cout<<"Sorted Array: "<<endl;
	for(int mover = 0; mover < SIZE; mover++)
	{
		cout<<sortedArray[mover]<<" ";
	}
	cout<<endl;
	
	int elementReturned = BinarySearch(sortedArray);
	
	if(elementReturned == -1)
	{
		cout<<"Given Number is not found"<<endl;
	}
	else
	{
		cout<<"Given number is present at index "<<elementReturned<<endl;
	}
	
}

int BinarySearch(int arr[])
{
	int input;
	cout<<"Number to be searched: ";
	cin>>input;
	cout<<endl;
	
	for(int index = 0; index <= (SIZE / 2); index++)
	{
		middleValue = ((firstIndex + lastIndex) / 2);
		cout<<firstIndex<<" "<<middleValue<<" "<<lastIndex<<endl;
		if(firstIndex == SIZE || lastIndex == -1)
		{
			return -1;
		}
		else if(input == arr[middleValue])
		{
			return middleValue;
		}
		else if(input < arr[middleValue])
		{
			lastIndex = middleValue - 1;
		}
		else if(input > arr[middleValue])
		{
			firstIndex = middleValue + 1;
		}
	}
}

