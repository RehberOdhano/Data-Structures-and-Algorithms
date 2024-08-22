#include <iostream>
#define SIZE 6
using namespace std;

int linearSearch(int arr[]);
int arrayList[SIZE];

int main()
{
	cout<<"Linear Search..."<<endl;
	cout<<"Lets store some data in the array first..."<<endl;
	
	for(int index = 0; index < SIZE; index++)
	{
		cout<<"Enter a number: ";
		cin>>arrayList[index];
		cout<<endl;
	}
	
	int elementReturned = linearSearch(arrayList);
	
	if(elementReturned == -1)
	{
		cout<<"Given Number is not found"<<endl;
	}
	else
	{
		cout<<"Given number is present at index "<<elementReturned<<endl;
	}
}

int linearSearch(int arr[])
{
	int input;
	cout<<"Number to be searched: ";
	cin>>input;
	cout<<endl;
	
	for(int index = 0; index <= SIZE; index++)
	{
		if(index == SIZE)
		{
			return -1;
		}
		else if(arr[index] == input)
		{
			return index;
		}
	}
}

