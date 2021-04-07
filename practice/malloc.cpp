#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	int *list = (int*)malloc(3*sizeof(int));
	if(list == NULL)
		return 1;
	
	list[0] = 1;
	list[1] = 2;
	list[2] = 3;
	
	int* temp = (int*)malloc(4*sizeof(int));
	if(temp == NULL)
		return 1;
		
	for(int i = 0; i < 3; i++)
	{
		temp[i] = list[i];
	}
	
	temp[3] = 4;
	free(list);
	
	list = temp;
	
	for(int i = 0; i < 4; i++)
	{
		cout<<temp[i]<<"\n";
	}
	return 0;
	
	
	/*
	int *list = (int*)(3*sizeof(int));
	if(list == NULL)
		return 1;
	
	list[0] = 1;
	list[1] = 2;
	list[2] = 3;
	
	int* temp = (int*)realloc(list, 4*sizeof(int));
	if(temp == NULL)
		return 1;
	
	list = temp;
	temp[3] = 4;
	
	for(int i = 0; i < 4; i++)
	{
		cout<<list[i]<<"\n";
	}
	return 0;
	*/
}
