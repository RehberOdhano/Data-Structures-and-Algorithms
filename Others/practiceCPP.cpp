#include <bits/stdc++.h> 
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <array>
#define WIDTH 5
#define HEIGHT 3
using namespace std;

//both are equivalent
//int jimmy [HEIGHT][WIDTH]; //for multidimensional array
int jimmy [HEIGHT * WIDTH]; //for simple array

const int M = 3; 
const int N = 3; 

void printNumbers(); 
void printarray (int arg[], int length);
string returnFloatingPart(string str);
bool containsOnlyDigit(string str); 
string replaceBlankWith20(string str);
void print(int *arr, int m, int n);
void print1(int arr[][N], int m);
void print2(int arr[M][N]);
void increment_all (int* start, int* stop);
void print_all (const int* start, const int* stop);
void increase (void* data, int psize);
int addition (int a, int b);
int subtraction (int a, int b);
int operation (int x, int y, int (*functocall)(int,int));

int main()
{
	/*
	int a, b, c;
	cout<<"Enter three different integers: ";
	cin>>a>>b>>c;
	cout<<"\nSum: "<<a+b+c<<endl;
	cout<<"Average: "<<(a+b+c)/3.0<<endl;
	cout<<"Product: "<<a*b*c<<endl;
	
	if(a < b && a < c)
		cout<<"Smallest is: "<<a<<endl;
	if(a > b && a < c)
		cout<<"Smallest is: "<<b<<endl;
	if(a < b && a > c)
		cout<<"Smallest is: "<<c<<endl;
	if(a > b && a > c)
		cout<<"Largest is: "<<a<<endl;
	if(a < b && b > c)
		cout<<"Largest is: "<<b<<endl;
	if(a < b && b < c)
		cout<<"Largest is: "<<c<<endl;	
		
	char character;
	cout<<"Enter a char: ";
	cin>>character;
	cout<<"\n";
	cout<<static_cast<int>(character)<<endl;	
	*/
	
	/*
	int number;
	cout<<"Enter a five-digit number: ";
	cin>>number;
	int result = number / 10000;
	number %= 10000;
	cout<<"\n"<<result<<" ";
	result = number / 1000;
	number %= 1000;
	cout<<result<<" ";
	result = number / 100;
	number %= 100;
	cout<<result<<" ";
	cout<<number/10<<" "<<number%10<<"\n";
	*/
	
	/*
	cout<<"TABLE\n";
	cout<<"integer\tsquare\tcube\n";
	for(int i = 0; i <= 10; i++)
	{
		cout<<i<<"\t"<<pow(i,2)<<"\t"<<pow(i,3)<<endl;
	}
	*/
	
	/*
	cout<<"BMI Values\n";
	cout<<"Underweight: less than 18.5\n";
	cout<<"Normal: between 18.5 and 24.9\n";
	cout<<"Overweight: between 25 and 29.9\n";
	cout<<"Obese: 30 or greater\n";
	int weightInKg;
	int heightInMeters;
	float BMI;
	cin>>weightInKg>>heightInMeters;
	BMI = (weightInKg)/((float)(pow(heightInMeters, 2)));
	if(BMI < 18.5)
		cout<<"Underweight\n";
	if(BMI > 18.5 && BMI < 24.9)
		cout<<"Normal\n";
	if(BMI > 25 && BMI < 29.9)
		cout<<"Overweight\n";
	if(BMI > 30)
		cout<<"Obese\n";
	*/
	
	/*
	float totalMiles, costPerGallon, average, costPerDay, parkingFee;
	int tollsPerDay;
	
	cout<<"Enter total miles driven per day: ";
	cin>>totalMiles;
	cout<<"\nEnter cost per gallon of gasoline: ";
	cin>>costPerGallon;
	cout<<"\nEnter average miles per gallon: ";
	cin>>average;
	cout<<"\nEnter parking fees per day: ";
	cin>>parkingFee;
	cout<<"\nEnter tolls per day: ";
	cin>>tollsPerDay;
	cout<<endl;
	
	costPerDay = (tollsPerDay + parkingFee + (tollsPerDay / average) * costPerGallon);
	cout<<"Daily driving cost: "<<costPerDay<<endl;
	*/
	
	/*
	char letter[5];
	puts("Enter a character array: ");
	gets(letter);
	puts("\nThe character array you've entered is: ");
	puts(letter);		
	*/
	
	//if we want to take a phrase or a sentence as input, then the cin
	//function does not work becasue it only extracts one word before any
	//whitespace. To overcome this problem, we use getline function
	
	/*
	string fullName;
	cout<<"Enter your full name: ";
	getline(cin, fullName);
	cout<<"\nFull Name: "<<fullName<<endl;
	*/
	
	/*
	string myStr = "1025";
	int myInt;
	stringstream(myStr)>>myInt; //converts the string "1025" to integer 1025
	cout<<myInt<<endl;		
	*/
	
	/*
	What happen when we exceed valid range of built-in data types in C++?
	indefinite loops
		
	for (char a = 0; a <= 225; a++) 
        cout << a; 
	
	bool a = true; 
  
    for (a = 1; a <= 5; a++) 
        cout << a; 
  	
  	short a; 
  
    for (a = 32767; a < 32770; a++) 
        cout << a << "\n";
        
    unsigned short a; 
  
    for (a = 65532; a < 65536; a++) 
        cout << a << "\n";
        
    Explanation –

	We know that computer uses 2’s complement to represent data. 
	For example if we have 1 byte (We can use char and use %d as 
	format specifier to view it as decimal), we can represent -128 to 127. 
	If we add 1 to 127 we will get -128. Thats because 127 is 01111111 in binary. 
	And if we add 1 into 01111111 we will get 10000000. 10000000 is -128 in 2’s complement form.
  	
	*/
	
	//printNumbers(); 
	
	//Execute both if and else statements in C/C++ simultaneously
	/*
	if (1) //Replace 1 with 0 and see the magic 
	{ 
    	label_1: printf("Hello "); 
      
	    // Jump to the else statement after  
	    // executing the above statement 
	    goto label_2; 
  	}	 
  	else
  	{ 
	    // Jump to 'if block statement' if  
	    // the Boolean condition becomes false 
	    goto label_1; 
	  
	    label_2: printf("Geeks"); 
  	}	 
	*/
	
	/*
	The expression provided in the switch integral type ( int, char and enum)
	or in other words should result in a constant value otherwise it would not be valid.
	The default statement is optional.Even if the switch case statement do not have 
	a default statement, it would run without any problem.
	switch (n)
	{
		n += 1 //This statement is not executed 
	    case 1: // code to be executed if n = 1;
	        break;
	    case 2: // code to be executed if n = 2;
	        break;
	    default: // code to be executed if n doesn't match any cases (optional)
	}
	
	If break is not included, all statements following the case
	(including those under any other labels) are also executed, 
	until the end of the switch block or a jump statement (such as break) is reached.
	
	*/
	
	/*
	
	In C++ switch statement, the expression of each case label must be an integer constant
	expression.
	For example, the following program fails in compilation.
	
	int i = 10; 
  	int c = 10; 
  	switch(c)  
  	{ 
    	case i: // not a "const int" expression 
        	printf("Value of c = %d", c); 
        	break; 
    	//Some more cases
                     
  	} 
	
	Putting const before i makes the above program work.
	
	const int i = 10; 
  	int c = 10; 
  	switch(c)  
  	{ 
    	case i:  // Works fine 
        	printf("Value of c = %d", c); 
        	break; 
    	//Some more cases
                     
  	} 
	
	
	/*
	Arrays are blocks of static memory whose size must be determined at compile time,
	before the program runs.
	Array members are accessed using pointer arithmetic.
	Compiler uses pointer arithmetic to access array element. For example, 
	an expression like “arr[i]” is treated as *(arr + i) by the compiler. 
	That is why the expressions like *(arr + i) work for array arr, 
	and expressions like ptr[i] also work for pointer ptr.
	*/
	
	/*
	int arr[] = {10, 20, 30, 40, 50, 60}; 
	//OR
	//int arr[] {10, 20, 30, 40, 50, 60}; both are equivalent and this is called universal
	//									  initialization
   	int *ptr = arr; 
   	cout << "arr[2] = "<< arr[2] <<"\n"; 
   	cout << "*(arr + 2) = "<< *(arr + 2)<<"\n"; 
   	cout << "ptr[2] = "<< ptr[2]<< "\n"; 
   	cout << "*(ptr + 2) = "<< *(ptr + 2)<< "\n"; 
	*/
	
	// an array of 10 integers.  If arr[0] is stored at 
    // address x, then arr[1] is stored at x + sizeof(int) 
    // arr[2] is stored at x + sizeof(int) + sizeof(int) 
    // and so on.
	/* 
    int arr[5], i; 
  
    cout << "Size of integer in this compiler is " << sizeof(int) << "\n"; 
  
    for (i = 0; i < 5; i++) 
        // The use of '&' before a variable name, yields 
        // address of variable. 
        cout << "Address arr[" << i << "] is " << &arr[i] << "\n"; 
	*/	
	
	/*
	//both codes are equivalent, producing the same output
	//multidimensional array 
	for (int n=0; n<HEIGHT; n++)
    {
		for (int m=0; m<WIDTH; m++)
    	{
      		jimmy[n][m]=(n+1)*(m+1);
    	}
    }
    */
    
    /*
    //printing the elements
    for(int i = 0; i < HEIGHT; i++)
    {
    	for(int j = 0; j < WIDTH; j++)
    	{
    		cout<<jimmy[i][j]<<" ";
		}
		cout<<endl;
	}
    
	
	//simple array
	for (int n=0; n<HEIGHT; n++)
	{
		for (int m=0; m<WIDTH; m++)
	    {
	      jimmy[n*WIDTH+m]=(n+1)*(m+1);
	    }
	}
	
	//printing the elements
	for(int i = 0; i < HEIGHT; i++)
    {
    	for(int j = 0; j < WIDTH; j++)
    	{
    		cout<<jimmy[i*WIDTH+j]<<" ";
		}
		cout<<endl;
	}
	*/
	
	//code for printarray function
	//passing array as parameter/argument to a function
	//In C++, it is not possible to pass the entire block of memory represented 
	//by an array to a function directly as an argument. But what can be passed 
	//instead is its address. In practice, this has almost the same effect, and 
	//it is a much faster and more efficient operation.
	/*
	int firstarray[] = {5, 10, 15};
  	int secondarray[] = {2, 4, 6, 8, 10};
  	printarray (firstarray,3);
  	printarray (secondarray,5);
  	*/
  	
  	/*
  	//container library array
  	array<int,3> myarray {10,20,30};

  	for (int i=0; i<myarray.size(); ++i)
    	++myarray[i];

  	for (int elem : myarray)
    	cout << elem << '\n';
	*/
	
	/*
	//Strings
	// various constructor of string class 
  
    // initialization by raw string 
    string str1("first string"); 
  
    // initialization by another string 
    string str2(str1); 
  
    // initialization by character with number of occurrence 
    string str3(5, '#'); 
  
    // initialization by part of another string 
    string str4(str1, 6, 6); //    from 6th index (second parameter) 
                             // 6 characters (third parameter) 
  
    // initialization by part of another string : iteartor version 
    string str5(str2.begin(), str2.begin() + 5); 
  
    cout << str1 << endl; 
    cout << str2 << endl; 
    cout << str3 << endl; 
    cout << str4 << endl; 
    cout << str5 << endl; 
  	
  	//  assignment operator 
    string str6 = str4; 
  
    // clear function deletes all character from string 
    str4.clear(); 
  
    //  both size() and length() return length of string and 
    //  they work as synonyms 
    int len = str6.length(); // Same as "len = str6.size();" 
  
    cout << "Length of string is : " << len << endl; 
  
    // a particular character can be accessed using at / 
    // [] operator 
    char ch = str6.at(2); //  Same as "ch = str6[2];" 
  
  
    cout << "third character of string is : " << ch << endl; 
  
    //  front return first character and back returns last character 
    //  of string 
  
    char ch_f = str6.front();  // Same as "ch_f = str6[0];" 
    char ch_b = str6.back();   // Same as below 
                               // "ch_b = str6[str6.length() - 1];" 
  
    cout << "First char is : " << ch_f << ", Last char is : "
         << ch_b << endl; 
  
    // c_str returns null terminated char array version of string 
    const char* charstr = str6.c_str(); 
    printf("%s\n", charstr); 
  
    // append add the argument string at the end 
    str6.append(" extension"); 
    //  same as str6 += " extension" 
  
    // another version of append, which appends part of other 
    // string 
    str4.append(str6, 0, 6);  // at 0th position 6 character 
  
    cout << str6 << endl; 
    cout << str4 << endl; 
  
    //  find returns index where pattern is found. 
    //  If pattern is not there it returns predefined 
    //  constant npos whose value is -1 
  
    if (str6.find(str4) != string::npos) 
        cout << "str4 found in str6 at " << str6.find(str4) 
             << " pos" << endl; 
    else
        cout << "str4 not found in str6" << endl; 
  
    //  substr(a, b) function returns a substring of b length 
    //  starting from index a 
    cout << str6.substr(7, 3) << endl; 
  
    //  if second argument is not passed, string till end is 
    // taken as substring 
    cout << str6.substr(7) << endl; 
  
    //  erase(a, b) deletes b characters at index a 
    str6.erase(7, 4); 
    cout << str6 << endl; 
  
    //  iterator version of erase 
    str6.erase(str6.begin() + 5, str6.end() - 3); 
    cout << str6 << endl; 
  
    str6 = "This is a examples"; 
  
    //  replace(a, b, str)  replaces b characters from a index by str 
    str6.replace(2, 7, "ese are test"); 
  
    cout << str6 << endl; 
    */
    
    /*
    string fnum = "23.342"; 
    cout << "Floating part is : " << returnFloatingPart(fnum)  
         << endl; 
  
    string num = "3452"; 
    if (containsOnlyDigit(num)) 
        cout << "string contains only digit" << endl; 
  
    string urlex = "google com in"; 
    cout << replaceBlankWith20(urlex) << endl; 
	*/
	
	/*
	//Sting functions
	string str1("Rehber");
	string str2("REHBER");
	
	//comparing the strings
	if(str1.compare(str2) == 0)
		cout<<"Strings are equal\n";
	else
		cout<<"Strings are unequal\n";
		
	string str("The Geeks for Geeks"); 
  
    // find() returns position to first 
    // occurrence of substring "Geeks" 
    // Prints 4 
    cout << "First occurrence of \"Geeks\" starts from : "; 
    cout << str.find("Geeks") << endl; 
  
    // Prints position of first occurrence of 
    // any character of "reef" (Prints 2) 
    cout << "First occurrence of character from \"reef\" is at : "; 
    cout << str.find_first_of("reef") << endl; 
  
    // Prints position of last occurrence of 
    // any character of "reef" (Prints 16) 
    cout << "Last occurrence of character from \"reef\" is at : "; 
    cout << str.find_last_of("reef") << endl; 
  
    // rfind() returns position to last 
    // occurrence of substring "Geeks" 
    // Prints 14 
    cout << "Last occurrence of \"Geeks\" starts from : "; 
    cout << str.rfind("Geeks") << endl; 
    
    string str("Geeksfor"); 
  
    // Printing the original string 
    cout << str << endl; 
  
    // Inserting "Geeks" at 8th index position 
    str.insert(8,"Geeks"); 
  
    // Printing the modified string 
    // Prints "GeeksforGeeks" 
    cout << str << endl; 
    
    string str("GeeksforGeeks"); 
  
    // clearing string 
    str.clear(); 
  
    // Checking if string is empty 
    (str.empty()==1)? 
         cout << "String is empty" << endl: 
         cout << "String is not empty" << endl; 
  
	*/
	 
	/*
	//creating array of strings using pointers
	//Number of strings are fixed
	//Strings are constants and contents cannot be changed
	// Initialize array of pointer
    const char *colour[4] = { "Blue", "Red", "Orange", "Yellow" }; 
  
    // Printing Strings stored in 2D array 
    for (int i = 0; i < 4; i++) 
        cout << colour[i] << "\n"; 
        
        
    //creating array of strings using 2D array
    //This method is useful for shuffling, comparing and accessing characters randomly.
    //Both the number of Strings and Size of String are fixed.
	//A 2D array is allocated, whose second dimension is equal to maximum 
	//sized string which causes wastage of space.
    // Initialize 2D array 
    char colour[4][10] = { "Blue", "Red", "Orange", 
                           "Yellow" }; 
  
    // Printing Strings stored in 2D array 
    for (int i = 0; i < 4; i++) 
        cout << colour[i] << "\n";
        
    //creating an array of strings using string keyword
    // The array is of fixed size.
    // Initialize String Array 
    string colour[4] = { "Blue", "Red", 
                         "Orange", "Yellow" }; 
  
    // Print Strings 
    for (int i = 0; i < 4; i++) 
        cout << colour[i] << "\n";
        
    //creating an array of strings using vectors and its the best way
    // Declaring Vector of String type 
    vector<string> colour; 
  
    // Initialize vector with strings using push_back 
    // command 
    colour.push_back("Blue"); 
    colour.push_back("Red"); 
    colour.push_back("Orange"); 
    colour.push_back("Yellow"); 
  
    // Print Strings stored in Vector 
    for (int i = 0; i < colour.size(); i++) 
        cout << colour[i] << "\n"; 
		
	*/
	
	/*
	char myntcs[] = "some text";
	string mystring = myntcs;  // convert c-string to string
	cout << mystring<<endl;          // printed as a library string
	cout << mystring.c_str()<<endl;  // printed as a c-string 	
	*/
	
	/*
	// Declare an array 
    int v[3] = {10, 100, 200}; 
  
    // Declare pointer variable 
    int *ptr; 
  
    // Assign the address of v[0] to ptr 
    ptr = v; 
  
    for (int i = 0; i < 3; i++) 
    { 
        printf("Value of *ptr = %d\n", *ptr); 
        printf("Value of ptr = %p\n\n", ptr); 
  
        // Increment pointer ptr by 1 
        ptr++; 
    } 
	*/
	
	/*
	//passing 2D array as parameter using a single pointer
	int arr[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; 
    int m = 3, n = 3; 
  
    // We can also use "print(&arr[0][0], m, n);" 
    print((int *)arr, m, n);
    */
    
    
    //passing 2D array as parameter When only second dimension is available globally 
	//(either as a macro or as a global constant).
	//int arr[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; 
    //print1(arr, 3); 
	
	//passing 2D arrray as parameter using a single pointer When both dimensions are
	//available globally (either as a macro or as a global constant
	//int arr[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; 
    //print2(arr);
    
    //pointers
    /*
    int firstvalue = 5, secondvalue = 15;
	int * p1, * p2;

  	p1 = &firstvalue;  // p1 = address of firstvalue
  	p2 = &secondvalue; // p2 = address of secondvalue
  	*p1 = 10;          // value pointed to by p1 = 10
  	*p2 = *p1;         // value pointed to by p2 = value pointed to by p1
  	p1 = p2;           // p1 = p2 (value of pointer is copied)
  	*p1 = 20;          // value pointed to by p1 = 20
  
  	cout << "firstvalue is " << firstvalue << '\n';
  	cout << "secondvalue is " << secondvalue << '\n';
  	
  	int numbers[5];
  	int * p;
  	p = numbers;  *p = 10;
  	p++;  *p = 20;
  	p = &numbers[2];  *p = 30;
  	p = numbers + 3;  *p = 40;
  	p = numbers;  *(p+4) = 50;
  	for (int n=0; n<5; n++)
    	cout << numbers[n] << ", ";
	*/
	
	/*
	//pointers and const
	int numbers[] = {10,20,30};
  	increment_all (numbers,numbers+3);
  	print_all (numbers,numbers+3);
	*/
	
	/*	
	int x;
    int *p1 = &x;  // non-const pointer to non-const int
	const int *p2 = &x;  // non-const pointer to const int
    int * const p3 = &x;  // const pointer to non-const int
	const int * const p4 = &x;  // const pointer to const int 
	
	const int * p2a = &x;  //      non-const pointer to const int
	int const * p2b = &x;  // also non-const pointer to const int 
	
	const char * foo = "hello"; 
	*(foo+4)
	foo[4]
	Both expressions have a value of 'o' (the fifth element of the array).

	*/
	
	//pointers to pointers
	/*
	char a;
	char * b;
	char ** c; //pointer to pointer
	a = 'z';
	b = &a;
	c = &b;
	
	//variable c and can be used in three different levels of indirection, 
	//each one of them would correspond to a different value:

	c is of type char** and a value of 8092
	*c is of type char* and a value of 7230
	**c is of type char and a value of 'z'
	
	*/
	
	//void pointers
	// In C++, void represents the absence of type. Therefore, void pointers are pointers 
	//that point to a value that has no type (and thus also an undetermined length and 
	//undetermined dereferencing properties).
	
	/*
	This gives void pointers a great flexibility, by being able to point to any data type,
	from an integer value or a float to a string of characters. In exchange, they have a great 
	limitation: the data pointed to by them cannot be directly dereferenced 
	(which is logical, since we have no type to dereference to), and for that reason, 
	any address in a void pointer needs to be transformed into some other pointer type 
	that points to a concrete data type before being dereferenced.
	
	=> See increase function for void pointers...
	*/

	/*
	char a = 'x';
 	int b = 1602;
  	increase (&a,sizeof(a));
  	increase (&b,sizeof(b));
  	cout << a << ", " << b << '\n';
	*/
	
	/*
	In principle, pointers are meant to point to valid addresses, such as the address 
	of a variable or the address of an element in an array. But pointers can actually 
	point to any address, including addresses that do not refer to any valid element. 
	Typical examples of this are uninitialized pointers and pointers to nonexistent 
	elements of an array:
	*/
	//invalid and null pointers
	/*
	int * p;               // uninitialized pointer (local variable)

	int myarray[10];
	int * q = myarray+20;  // element out of bounds
	
	/*
	Neither p nor q point to addresses known to contain a value, but none of the above statements
	causes an error. In C++, pointers are allowed to take any address value, no matter whether 
	there actually is something at that address or not. What can cause an error is to dereference 
	such a pointer (i.e., actually accessing the value they point to). Accessing such a pointer
	causes undefined behavior, ranging from an error during runtime to accessing some random value.
	*/

	/*
	But, sometimes, a pointer really needs to explicitly point to nowhere, and not just an invalid
	address. For such cases, there exists a special value that any pointer type can take: 
	the null pointer value. This value can be expressed in C++ in two ways: either with an 
	integer value of zero, or with the nullptr keyword:
	*/
	
	//int * p = 0;
	//int * q = nullptr;
	
	/*
	Here, both p and q are null pointers, meaning that they explicitly point to nowhere, 
	and they both actually compare equal: all null pointers compare equal to other null pointers. 
	It is also quite usual to see the defined constant NULL be used in older code to refer 
	to the null pointer value:
	*/

	//int * r = NULL;
	
	/*
	NULL is defined in several headers of the standard library, and is defined as an alias 
	of some null pointer constant value (such as 0 or nullptr).

	Do not confuse null pointers with void pointers! A null pointer is a value that any pointer 
	can take to represent that it is pointing to "nowhere", while a void pointer is a type of 
	pointer that can point to somewhere without a specific type. One refers to the value stored 
	in the pointer, and the other to the type of data it points to.
	*/
	
	//pointer to function
	/*
	C++ allows operations with pointers to functions. The typical use of this is for 
	passing a function as an argument to another function. Pointers to functions are declared
	with the same syntax as a regular function declaration, except that the name of the
	function is enclosed between parentheses () and an asterisk (*) is inserted before the name.
	*/
	
	/*
	int m,n;
  	int (*minus)(int,int) = subtraction;

  	m = operation (7, 5, addition);
  	n = operation (20, m, minus);
  	cout <<n;
  	
  	//In the example above, minus is a pointer to a function that has two parameters of type int. 
	//It is directly initialized to point to the function subtraction:
	
	*/
	
	
	
	
    
		
}

/*
goto allows to make an absolute jump to another point in the program. This unconditional jump 
ignores nesting levels, and does not cause any automatic stack unwinding. Therefore, it is a 
feature to use with care, and preferably within the same block of statements, especially in the 
presence of local variables. The destination point is identified by a label, which is then used 
as an argument for the goto statement. A label is made of a valid identifier followed by a colon (:).
*/
void printNumbers() 
{ 
    int n = 1; 
label: 
    printf("%d ",n); 
    n++; 
    if (n <= 10) 
        goto label; //goto statement also called unconditional jump statement
    /*    
    the first line tells the compiler to go to or jump to the statement marked as a label.
	Here label is a user-defined identifier which indicates the target statement. 
	The statement immediately followed after ‘label:’ is the destination statement. 
	The ‘label:’ can also appear before the ‘goto label;’ statement in the above syntax.
	*/
}

void printarray (int arg[], int length) 
{
  for (int n=0; n<length; ++n)
    cout << arg[n] << ' ';
  cout << '\n';
}

// this function returns floating point part of a number-string 
string returnFloatingPart(string str) 
{ 
    int pos = str.find("."); 
    if (pos == string::npos) 
        return ""; 
    else
        return str.substr(pos + 1); 
} 
  
// This function checks whether a string contains all digit or not 
bool containsOnlyDigit(string str) 
{ 
    int l = str.length(); 
    for (int i = 0; i < l; i++) 
    { 
        if (str.at(i) < '0' || str.at(i) > '9') 
            return false; 
    } 
    //  if we reach here all character are digits 
    return true; 
} 
  
// this function replaces all single space by %20 
// Used in URLS 
string replaceBlankWith20(string str) 
{ 
    string replaceby = "%20"; 
    int n = 0; 
  
    // loop till all space are replaced 
    while ((n = str.find(" ", n)) != string::npos ) 
    { 
        str.replace(n, 1, replaceby); 
        n += replaceby.length(); 
    } 
    return str; 
}

void print(int *arr, int m, int n) 
{ 
    int i, j; 
    for (i = 0; i < m; i++) 
      for (j = 0; j < n; j++) 
        cout<<(*((arr+i*n) + j)); 
}

void print1(int arr[][N], int m) 
{ 
    int i, j; 
    for (i = 0; i < m; i++) 
      for (j = 0; j < N; j++) 
        cout<<(arr[i][j]); 
}

void print2(int arr[M][N]) 
{ 
    int i, j; 
    for (i = 0; i < M; i++) 
      for (j = 0; j < N; j++) 
        printf("%d ", arr[i][j]); 
}

void increment_all (int* start, int* stop)
{
  int * current = start;
  while (current != stop) {
    ++(*current);  // increment value pointed
    ++current;     // increment pointer
  }
}

/*
Note that print_all uses pointers that point to constant elements. These pointers 
point to constant content they cannot modify, but they are not constant themselves:
i.e., the pointers can still be incremented or assigned different addresses, 
although they cannot modify the content they point to
*/
void print_all (const int* start, const int* stop)
{
  const int * current = start;
  while (current != stop) {
    cout << *current << '\n';
    ++current;     // increment pointer
  }
}

void increase (void* data, int psize)
{
  if ( psize == sizeof(char) )
  { char* pchar; pchar=(char*)data; ++(*pchar); }
  else if (psize == sizeof(int) )
  { int* pint; pint=(int*)data; ++(*pint); }
}

int addition (int a, int b)
{ return (a+b); }

int subtraction (int a, int b)
{ return (a-b); }

int operation (int x, int y, int (*functocall)(int,int))
{
  int g;
  g = (*functocall)(x,y);
  return (g);
}     
