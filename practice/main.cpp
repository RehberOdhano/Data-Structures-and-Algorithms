/*Goal: practice using a class. 
**Create an array called roster, populate it 
**with multiple instances of Dog, it has a size of SIZE. 
**The create a function called 
**printRoster(roster, SIZE) that will print 
**all the information about all the dogs on the roster.
*/

#include "main.hpp"
const int SIZE = 3;

int main()
{
    //ToDo: assign the dogs to an array called roster
    //Then assign names to the Dog.
    Dog roster[SIZE];
    
    roster[0].setName("Blue");
    roster[1].setName("King");
    roster[2].setName("Spot");
    
    //ToDo: declare and define this function
    //in the header file
    printRoster(roster,SIZE);
    return 0;
}

