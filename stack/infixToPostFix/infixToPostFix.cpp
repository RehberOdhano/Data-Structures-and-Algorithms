#include <iostream>
#include<string>
#define SIZE 0
using namespace std;

void push(char element);
void pop();
char top();
bool isEmpty();
int precedenceOfOperators(char Operator);
string conversionFromInFixToPostFix(string inFixExpression);

char stack[SIZE];
int topOfStack = -1;

int main()
{
	string infixExpression;
	stack[SIZE + infixExpression.length()];
	
	int counter;
	cout<<"How many times do you want to run this program? ";
	cin>>counter;
	cout<<endl;
	for(int count = 1; count <= counter; count++)
	{
		cout<<"Enter an Infix expression: ";
		cin>>infixExpression;
		cout<<endl;
		string postFixExpression = conversionFromInFixToPostFix(infixExpression);
		cout<<"InFix Expression: "<<infixExpression<<endl;
		cout<<"PostFix Expression: "<<postFixExpression<<endl;
	}

}

string conversionFromInFixToPostFix(string inFixExpression)
{
	string postFixExpression = "";
	
	for(int index = 0; index < inFixExpression.length(); index++)
	{
		if((inFixExpression[index] == ' ') || (inFixExpression[index] == ','))
		{
			continue;
		}
		else if(inFixExpression[index] == '(' || inFixExpression[index] == '[' || inFixExpression[index] == '{')
		{
			push(inFixExpression[index]);
		}
		else if(inFixExpression[index] == ')')
		{
			while(!isEmpty() && top() != '(')
			{
				postFixExpression += top();
				pop();
			}
			pop();
		}
		else if((inFixExpression[index] >= '0' && (inFixExpression[index] <= '9')))
		{
			postFixExpression += inFixExpression[index];
		}
		else if((inFixExpression[index] >= 'A') && (inFixExpression[index] <= 'Z') || 
				  (inFixExpression[index] >= 'a') && (inFixExpression[index] <= 'z'))
		{
			postFixExpression += inFixExpression[index];
		}
		else if((inFixExpression[index] == '^') || (inFixExpression[index] == '*') || 
				(inFixExpression[index] == '/') || (inFixExpression[index] == '+') || 
				(inFixExpression[index] == '-'))
		{
			if(isEmpty())
			{
				push(inFixExpression[index]);
			}
			else if(top() == '(')
			{
				push(inFixExpression[index]);
			}
			else if(precedenceOfOperators(inFixExpression[index]) > precedenceOfOperators(top()))
			{	
				push(inFixExpression[index]);
			}
			else if(precedenceOfOperators(inFixExpression[index]) < precedenceOfOperators(top()))
			{	
				while(!isEmpty())
				{
					if(top() == '(')
					{
						break;
					}
					else if(precedenceOfOperators(inFixExpression[index]) < precedenceOfOperators(top()))
					{
						postFixExpression += top();
						pop();
					}
					else if(precedenceOfOperators(inFixExpression[index]) == precedenceOfOperators(top())
							&& inFixExpression[index] != top())
					{
						postFixExpression += top();
						pop();
					}
					else if(precedenceOfOperators(inFixExpression[index]) == precedenceOfOperators(top())
							&& inFixExpression[index] == top())
					{
						postFixExpression += top();
						pop();
					}
					else
					{
						break;
					}
				}
				push(inFixExpression[index]);
			}
			else if((precedenceOfOperators(inFixExpression[index])) == (precedenceOfOperators(top()))
					&& inFixExpression[index] == top())
			{
				if(inFixExpression[index] == '^')
				{
					postFixExpression += inFixExpression[index + 1];
					postFixExpression += top();
					pop();
					push(inFixExpression[index]);
					index = (index + 1);
				}
				else
				{
					postFixExpression += inFixExpression[index];
					pop();
					push(inFixExpression[index]);
				}	
			}
			else if((precedenceOfOperators(inFixExpression[index])) == (precedenceOfOperators(top()))
					&& inFixExpression[index] != top())
			{
				postFixExpression += top();
				pop();
				push(inFixExpression[index]);
			}
		}
		else
		{
			continue;
		}
	}
	
	while(!isEmpty())
	{
		postFixExpression += top();
		pop();
	}
	return postFixExpression;
}

bool isEmpty()
{
	if(topOfStack == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int precedenceOfOperators(char Operator)
{
	if(Operator == '^')
	{
		return 3;
	}
	else if(Operator == '*' || Operator == '/')
	{
		return 2;
	}
	else if(Operator == '+' || Operator == '-')
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
}

void push(char element)
{
	topOfStack += 1;
	stack[topOfStack] = element;
}

void pop()
{
	topOfStack--;
}

char top()
{
	int e = stack[topOfStack];
	cout<<e<<endl;
	char topElement = stack[topOfStack];
	return topElement;
}

