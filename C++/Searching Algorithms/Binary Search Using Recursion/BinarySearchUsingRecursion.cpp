#include <iostream>
#define SIZE 6
using namespace std;

int BinarySearch(int middleValue, int numberToBeSearched);
int sortedArray[SIZE];
int arrayList[SIZE];
int firstIndex = 0;
int lastIndex = (SIZE - 1);

int main()
{
	cout<<"Binary Search..."<<endl;
	cout<<"Lets store some data in the array first..."<<endl;
	
	int input;
	
	for(int index = 0; index < SIZE; )
	{
		cout<<"Enter a number from 0 to 5: ";
		cin>>input;
		cout<<endl;
		if(input < 0 || input > 5)
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
	
	int userInput;
	cout<<"Number to be searched: ";
	cin>>userInput;
	cout<<endl;
	
	int mid = ((firstIndex + lastIndex) / 2);
	int elementReturned = BinarySearch(mid, userInput);
	
	if(elementReturned == -1)
	{
		cout<<"Given Number is not found"<<endl;
	}
	else
	{
		cout<<"Given number is present at index "<<elementReturned<<endl;
	}
}

int BinarySearch(int middleValue, int numberToBeSearched)
{	
	if(firstIndex == SIZE || lastIndex == -1)
	{
		return -1;
	}
	else if(numberToBeSearched == sortedArray[middleValue])
	{
		return middleValue;
	}
	else if(numberToBeSearched < sortedArray[middleValue])
	{
		lastIndex = middleValue - 1;
		BinarySearch(((firstIndex + lastIndex) / 2), numberToBeSearched);
	}
	else if(numberToBeSearched > sortedArray[middleValue])
	{
		firstIndex = middleValue + 1;
		BinarySearch(((firstIndex + lastIndex) / 2), numberToBeSearched);
	}
}

