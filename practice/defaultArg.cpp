#include <iostream>
using namespace std;

//global variable name localX
int localX = 30;

//function with default arguments/parameters and we only have to put the default
//values in the function prototype...
int volumeOfBox(int length = 1, int width = 1, int height = 1);

int main()
{
	//length = 1, width = 1, and height = 1
	cout<<"Volumne of the box: "<<volumeOfBox()<<" cubic meter(s)"<<endl;
	
	//length = 5, width = 1, and height = 1
	cout<<"Volumne of the box: "<<volumeOfBox(5)<<" cubic meter(s)"<<endl;
	
	//length = 5, width = 5, and height = 1
	cout<<"Volumne of the box: "<<volumeOfBox(5,5)<<" cubic meter(s)"<<endl;
	
	//length = 4, width = 4, and height = 4
	cout<<"Volumne of the box: "<<volumeOfBox(4,4,4)<<" cubic meter(s)"<<endl;
	
	//local variable named localX
	int localX = 25;
	
	//prints the value store in the local variable loacalX
	cout<<localX<<endl;
	
	//in order to print the value stored in the global variable localX,
	//we use unary scope resolution operator 
	cout<<::localX<<endl;
}

int volumeOfBox(int length, int width, int height)
{
	return(length*width*height);
}

