#include <iostream>
#include <string>
using namespace std;

//creating a class named Book
class Book
{
	//attributes/memebers of the class
	private:
		string ISBN;
	
	public:
		string title;
		string author;
		int pages;
		
		//constructors and memeber functions
		//non-argument constructor
		Book()
		{
			//initial values of the attributes
			title = "Unknown";
			author = "Unknown";
			pages = 0;
		}
		
		//deconstructor
		//doesn't contain any parameters, and return type, never!
		//and desconstructor overloading isn't supported or in other words
		//we can't overload deconstructor
		~Book();
		
		//parameterized constructor
		Book(string name)
		{
			cout<<"Author: "<<name<<endl;
		}
		
		Book(string aTitle, string aAuthor, int aPages)
		{
			title = aTitle;
			author = aAuthor;
			pages = aPages;
		}
		
		//setters and getters in order to access private attributes of the class
		void setISBN(string isbn)
		{
			ISBN = isbn;
		}
		
		string getISBN()
		{
			return ISBN;
		}
		
		//creating a constant function
		void printHello() const
		{
			cout<<"Constant Function!"<<endl;
		}
		
		//display the object's info
		void displayInfo()
		{
			cout<<title<<"\n";
			cout<<author<<"\n";
			cout<<pages<<"\n";
		}	
};

//deconstructor
Book::~Book()
{
	cout<<"I'm the deconstructor of the class Book\n";
}

//inheritance
//base class: Book and child class: BookSell
class BookSell : public Book
{
	private:
		int sellCount;
	public:
		BookSell()
		{
			sellCount = 0;
		}
		
		void setSellCount(int sC)
		{
			sellCount = sC;
		}
		
		int getSellCount()
		{
			return sellCount;
		}
		
		void displayInfo()
		{
			cout<<title<<"\n";
			cout<<author<<"\n";
			cout<<pages<<"\n";
			cout<<sellCount<<"\n";
		}
		
		
};

class Birthday
{
	public:
		Birthday(int m, int d, int y)
		{
			month = m;
			day = d;
			year = y;	
		}
		void printDate()
		{
			cout<<month<<"/"<<day<<"/"<<year<<endl;
		}
	private:
		int month;
		int day;
		int year;
};

class Person : public BookSell
{
	private:
		//int regularVar;
		//const int constVar;
		string name;
		
		//object of class Birthday as a member means the Person and Birthday class
		//has a "has-a" relationship, which is known as composition
		Birthday dateOfBirth;
	public:
		//constructor
		/*
		Person()
		{
			cout<<"I'm the constructor of the Peron class!\n";
		}
		*/
		
		Person(string nameOfPerson, Birthday DOB)
		: name(nameOfPerson), dateOfBirth(DOB)
		{
		}
		
		/*
		//: tells the C++ that we're working with member initialization list
		//at the end of this list, don't put semi-colon
		Person(int a, int b)
		: regularVar(a), constVar(b)
		{
		}
		*/
		//function overloading
		void printNumber(int a)
		{
			cout<<a<<endl;
		}
		
		void printNumber(float a)
		{
			cout<<a<<endl;
		}
		
		/*
		void printValues()
		{
			cout<<"regularVar: "<<regularVar<<" and constVar: "<<constVar<<endl;
		}
		*/
		
		void printDOB()
		{
			cout<<name<<" was born on ";
			dateOfBirth.printDate();
		}
};

class Number
{
	public:
		//constructor
		Number()
		{
			number = 0;
		}
		
		Number(int x)
		{
			number = x;
		}
		
		void printNumber()
		{
			//whenever we printout this variable, C++ assumes that we're 
			//working with the current/correct object...
			cout<<"Number: "<<number<<endl;
			
			//printing the value of variable 'number' using 'this' keyword
			//and 'this' is a pointer and it's an special keyword that identifies
			//the special pointer and stores the address of the current object...
			//whenever we printout like this way, we're explicitly telling C++ that
			//we're working with the current object...
			cout<<"Number: "<<this->number<<endl;
			
			//here we're dereferencing the 'this' pointer, which means again 
			//we're telling C++ explicitly that go to the location of the current
			//object where the 'this' pointer is pointing to and access its member 
			//variable 'number' in this case... 
			cout<<"Number: "<<(*this).number<<endl;
		}
	private:
		int number;
	
	//friend function prototype and this function has access to everything 
	//present inside the class
	friend void numberFriend(Number &numObj);	
};

//friend function of class Number
void numberFriend(Number &numObj)
{
	numObj.number = 10;
	cout<<"Number: "<<numObj.number<<endl;
}

int main()
{
	//creating an instance/object of class Book using non-argumented constructor
	Book book; 
	book.title = "Harry Potter";
	book.author = "JK Rowling";
	book.pages = 500;
	
	cout<<book.title<<"\n";
	cout<<book.author<<"\n";
	cout<<book.pages<<"\n";
	
	//creating an object using parameterized constructor
	Book book1("Rehber");
	book1.title = book.title;
	cout<<book1.title<<endl;
	
	
	Book book2("Unknown", "Unknown", 5000);
	cout<<book2.title<<"\n";
	cout<<book2.author<<"\n";
	cout<<book2.pages<<"\n";
	
	//creating an object using a non-argumented constructor and setters and gettors
	Book book3("Rehber", "Unknown", 5000);
	book3.setISBN("123456789456");
	cout<<book3.title<<"\n";
	cout<<book3.author<<"\n";
	cout<<book3.pages<<"\n";
	cout<<book3.getISBN()<<"\n";
	
	//inheritance
	BookSell bookSell;
	bookSell.title = "Hello World!";
	bookSell.author = "Rehber Odhano";
	bookSell.pages = 1000;
	bookSell.setSellCount(500);
	bookSell.displayInfo();
	
	/*
	//testing overloaded functions
	Person person;
	person.printNumber(2);
	person.printNumber(2.5F); //if we don't specify it's a float the compiler consider 2.5 as double
							 // and we get an error message
	*/
							
	//using indirection operator (->)
	Book *bookPtr = &book;
	cout<<bookPtr->author<<endl; //instead of dot operator, we can also access the properties of
								//an object using indirection operator
	
	//creating a constant object
	//these objects have constant functions not regular functions like others
	const Book constBookObj;
	constBookObj.printHello();
	
	/*
	//creating an object for testing member initialization list
	Person person1(4, 6);
	person1.printValues();
	*/
	
	//composition - Person and Birthday classes]
	Birthday birthday(4,30,2000);
	Person person2("Rehber", birthday);
	person2.printDOB(); 
	
	//testing friend function
	Number num;
	numberFriend(num);
	
	//testing 'this' keyword
	Number num1(10);
	num1.printNumber(); 
	
	//when the main function will completely be executed, C++ automatically calls the deconstructor
	//and destroys all the objects created...
	
	return 0;
	
}
