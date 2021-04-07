/*The header file for main.cpp*/
#include<iostream>
#include "Dog.cpp"

using namespace std;

void printRoster(Dog roster[], int size);

void printRoster(Dog roster[], int size)
{
    for(int i = 0; i < 3; i++)
    {
        roster[i].printInfo();
    }
    cout<<endl;
}

