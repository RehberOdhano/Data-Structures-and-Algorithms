#include <iostream>
#define SIZE 0
using namespace std;

void push(int element);
void pop();
int top();
bool isEmpty();
int evaluatePostFixExpression(string postFixExpression);

int stack[SIZE];
int topOfStack = -1;

int main()
{
	string postfixExpression = "";
	cout<<"Enter a postfix expression: ";
	cin>>postfixExpression;
	cout<<endl;
	
	stack[SIZE + postfixExpression.length()];
	
	int result = evaluatePostFixExpression(postfixExpression);
	cout<<"After the evaluation of "<<postfixExpression<<" the result is: "<<result<<endl;
}

int evaluatePostFixExpression(string postFixExpression)
{
	int operandOne = 0;
	int operandTwo = 0;
	int evaluation = 0;
	int topInteger = 0;	
	
	for(int index = 0; index < postFixExpression.length(); index++)
	{	
		if(postFixExpression[index] == ' ' || postFixExpression[index] == ',')
		{
			continue;
		}
		else if(postFixExpression[index] >= '0' && postFixExpression[index] <= '9')
		{
			push(postFixExpression[index] - '0');	
		}
		else if(postFixExpression[index] >= 'A' && postFixExpression[index] <= 'Z'
			   || postFixExpression[index] >= 'a' && postFixExpression[index] <= 'z')
		{
			int input;
			cout<<"Enter a value of "<<postFixExpression[index]<<" variable: ";
			cin>>input;
			push(input);
			cout<<endl; 
		}
		else if(postFixExpression[index] == '(')
		{
			push(postFixExpression[index]);
		}
		else if(postFixExpression[index] == ')')
		{
			while(!isEmpty() && top() != '(')
			{
				if(top() == '*')
				{
					pop();
					operandOne = top(); pop();	
					operandTwo = top(); pop();
					evaluation = operandTwo * operandOne;
					push(evaluation);
				}
				else if(top() == '/')
				{
					pop();
					operandOne = top(); pop();	
					operandTwo = top(); pop();
					evaluation = operandTwo / operandOne;
					push(evaluation);
				}
				else if(top() == '+')
				{
					pop();
					operandOne = top(); pop();	
					operandTwo = top(); pop();
					evaluation = operandTwo + operandOne;
					push(evaluation);
				}
				else if(top() == '-')
				{
					pop();
					operandOne = top(); pop();	
					operandTwo = top(); pop();
					evaluation = operandTwo * operandOne;
					push(evaluation);
				}
				else
				{
					topInteger = top();
					pop();
				}
			}
			pop();
			push(topInteger);
		}
		else if(postFixExpression[index] == '*')
		{
			operandOne = top(); pop();	
			operandTwo = top(); pop();
			evaluation = operandTwo * operandOne;
			push(evaluation);
		}
		else if(postFixExpression[index] == '/')
		{
			operandOne = top(); pop();	
			operandTwo = top(); pop();
			evaluation = operandTwo / operandOne;
			push(evaluation);
		}
		else if(postFixExpression[index] == '+')
		{
			operandOne = top(); pop();	
			operandTwo = top(); pop();
			evaluation = operandTwo + operandOne;
			push(evaluation);
		}
		else if(postFixExpression[index] = '-')
		{
			operandOne = top(); pop();	
			operandTwo = top(); pop();
			evaluation = operandTwo - operandOne;
			push(evaluation);
		}
	}
	
	return (stack[topOfStack]);
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


void push(int element)
{
	topOfStack += 1;
	stack[topOfStack] = element;
}

void pop()
{
	topOfStack -= 1;
}

int top()
{
	int topElement = stack[topOfStack];
	return topElement;
}









