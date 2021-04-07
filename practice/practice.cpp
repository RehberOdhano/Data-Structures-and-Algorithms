#include <iostream>
#include <string>
using namespace std;

const int size = 5;

void sortByNames(string* names);
void sortByNumbers(string* numbers);
void sortByGradDates(string* gradDates);

int main()
{
    string names[size];
    string numbers[size];
    string gradDates[size];

    for (int i = 0; i < size; i++)
    {
        cout<<"Enter your name: ";
        getline(cin, names[i]);
        cout<<"Enter your number: ";
        getline(cin, numbers[i]);
        cout<<"Enter your gradDate: ";
        getline(cin, gradDates[i]);
        cout<<"\n";
    }
    
    sortByNames(names);
    sortByNumbers(numbers);
    sortByGradDates(gradDates);
    
    for(int i = 0; i < size; i++)
    {
    	cout<<names[i]<<" "<<numbers[i]<<" "<<gradDates[i]<<"\n";
	}
	cout<<endl;
	return 0;
}

void sortByNames(string* names)
{
    string temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (names[j] > names[i])
            {
                temp = names[j];
                names[j] = names[i];
                names[i] = temp;
            }   
        }
    }
    
}

void sortByNumbers(string* numbers)
{
	string temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (numbers[j] > numbers[i])
            {
                temp = numbers[j];
                numbers[j] = numbers[i];
                numbers[i] = temp;
            }   
        }
    }
}

void sortByGradDates(string* gradDates)
{
	string temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (gradDates[j] > gradDates[i])
            {
                temp = gradDates[j];
                gradDates[j] = gradDates[i];
                gradDates[i] = temp;
            }   
        }
    }
}
