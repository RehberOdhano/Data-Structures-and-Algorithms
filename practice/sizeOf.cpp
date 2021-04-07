#include <iostream>
using namespace std;

int main()
{
	//usage of sizeof()
	int integers[10];
	cout<<sizeof(integers)<<endl; // displays 40 because each int equals 4 bytes
	
	//finding the size of the array using sizeof()
	cout<<sizeof(integers)/sizeof(integers[0])<<endl;
	
	//pointer's math
	int numbers[10];
	
	int* ptr0 = &numbers[0];
	int* ptr1 = &numbers[1];
	int* ptr2 = &numbers[2];
	
	cout<<"ptr0 is at: "<<ptr0<<endl;
	cout<<"ptr1 is at: "<<ptr1<<endl;
	cout<<"ptr2 is at: "<<ptr2<<endl;
	
	
	int* ptr3 = ptr0;
	cout<<"before incrementing, ptr3 = "<<ptr3<<endl;
	cout<<"after incrementing ptr3 = "<<++ptr3<<endl;
	
	ptr3 += 1;
	cout<<"after adding 2, ptr3 = "<<ptr3<<endl;
}
