#include <iostream>
using namespace std;

void MergeSort(int arr[], int startIndex, int lastIndex);
void MergeSubArrays(int* arrPointer, int initialIndex, int endIndex);
int size;

int main()
{
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
	
	MergeSort(originalArr, 0, (size - 1));
	
	//after sorting
	cout<<"Sorted Array: ";
	for(int index = 0; index < size; index++)
	{
		cout<<originalArr[index]<<" ";
	}
	cout<<endl;

}

void MergeSort(int arr[], int startIndex, int lastIndex)
{
	if(startIndex == lastIndex)
	{
		return;
	}
	else
	{
		int midPoint = (startIndex + lastIndex) / 2;
		cout<<startIndex<<" "<<midPoint<<" "<<lastIndex<<endl;
		MergeSort(arr, startIndex, midPoint);
		MergeSort(arr, (midPoint + 1), lastIndex);
		MergeSubArrays(arr, startIndex, lastIndex);
	}
}

void MergeSubArrays(int* arrPointer, int initialIndex, int endIndex)
{
	int midPoint = (initialIndex + endIndex) / 2;
	int leftIndex = initialIndex;
	int rightIndex = (midPoint + 1);
	int startIndex = initialIndex;
	
	int newArr[size];
	
	while(leftIndex <= midPoint && rightIndex <= endIndex)
	{
		if(arrPointer[leftIndex] < arrPointer[rightIndex])
		{
			newArr[startIndex++] = arrPointer[leftIndex++];
		}
		else
		{
			newArr[startIndex++] = arrPointer[rightIndex++];
		}
	}
	
	while(leftIndex <= midPoint)
	{
		newArr[startIndex++] = arrPointer[leftIndex++];
	}
	
	while(rightIndex <= endIndex)
	{
		newArr[startIndex++] = arrPointer[rightIndex++];
	}
	
	for(int i = initialIndex; i <= endIndex; i++)
	{
		arrPointer[i] = newArr[i];
	}
}
