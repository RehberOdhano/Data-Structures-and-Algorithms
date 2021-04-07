#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	//generate random numbers using rand()
	//generates same random number each time we run the program
	cout<<"Random Number: "<<rand()<<endl;
	
	//generates 10 random numbers
	cout<<"Random Numbers\n";
	for(int i = 0; i < 10; i++)
	{
		cout<<rand()<<"\n";
	}
	
	//generates 10 random numbers from 0 to 5
	cout<<"Random Numbers\n";
	for(int i = 0; i < 10; i++)
	{
		//rand() returns a random number and then using modulo operator we get
		//the remainder of that number
		cout<<(rand()%6)<<"\n"; 
	}
	
	//generates 10 random numbers from 1 to 6
	cout<<"Random Numbers\n";
	for(int i = 0; i < 10; i++)
	{
		//rand() returns a random number and then using modulo operator we get
		//the remainder of that number
		cout<<(rand()%6)+1<<"\n"; 
	}
	
	//all the above rand() functions generate same random numbers each time
	//we run the code because no computer random number generator is truly random
	//in order to generate different random numbers each time we run the code we use
	//srand()
	
	srand(time(0));
	cout<<"Random Numbers\n";
	for(int i = 0; i < 10; i++)
	{
		//rand() returns a random number and then using modulo operator we get
		//the remainder of that number
		cout<<(rand()%6)+1<<"\n"; 
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
