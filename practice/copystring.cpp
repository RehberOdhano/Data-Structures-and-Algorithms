#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	string str;
	cout<<"Enter a string: ";
	getline(cin, str);
	cout<<"\n";
	
	char* s = &str[0];
	
	char* t = new char();
	
	int n = str.length();
	
	//copy string s to t
	for(int i = 0; i < n; i++)
	{
		t[i] = s[i];
	}
	
	t[0] = toupper(t[0]);
	cout<<s<<"\n"<<t<<"\n";
	
	delete s, t;
	return 0;
}

