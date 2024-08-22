#include <iostream>
#define SIZE 6
using namespace std;

int linearSearchUsingRecursion(int index, int elementToBeSearched);
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
	
	int input;
	cout<<"Number to be searched: ";
	cin>>input;
	cout<<endl;
	
	int elementReturned = linearSearchUsingRecursion(0, input);
	
	if(elementReturned == -1)
	{
		cout<<"Given Number is not found"<<endl;
	}
	else
	{
		cout<<"Given number is present at index "<<elementReturned<<endl;
	}
}

int linearSearchUsingRecursion(int index, int elementToBeSearched)
{
	if(index == SIZE)
	{
		return -1;
	}
	else if(arrayList[index] == elementToBeSearched)
	{
		return index;
	}
	else
	{
		linearSearchUsingRecursion(index += 1, elementToBeSearched);
	}
}








