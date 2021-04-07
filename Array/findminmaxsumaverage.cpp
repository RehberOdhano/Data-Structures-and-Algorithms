/*
For this programming quiz, we are going to find the min and max and average of 15 numbers 
that a user will input. The numbers range from 0 to 100.
We will do it now for practice and then we will do it with arrays. So you do not have 
to keep all fifteen numbers stored in memory. Find the min and max and average of 15 numbers 
that a user will input. The numbers range from 0 to 100.
So you do not have to keep all fifteen numbers stored in memory.
*/

/*Find the min and max and average of 15 numbers that a user will input.
**The numbers range from 0 to 100. 
**We will do it now for practice and again later when we learn arrays and 
**functions. So you do not have to keep all fifteen numbers stored in memory.
**HINT: you will need to use scanf for input text.
*/

#include <iostream>
using namespace std;

int main()
{
    int sum = 0;
    float average = 0;
    int min = 100;
    int max = 0;
    int input;
    
    for(int i = 0; i < 15; i++)
    {
        cout<<"Enter a number: ";
        cin>>input;
        cout<<input<<"\n";
        sum += input;
        if(input > max)
            max = input;
        if(input < min)
            min = input;
    }
    
    average = sum/15.0;
    cout<<"Sum: "<<sum<<"\n";
    cout<<"Average: "<<average<<"\n";
    cout<<"Maximum: "<<max<<"\n";
    cout<<"Minimum: "<<min<<"\n";
    
    return 0;
}
