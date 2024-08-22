#include <iostream>
#include <string.h>
using namespace std;

char stack[0];
int topOfStack = -1;

void push(char element);
void pop();
char top();
bool isEmpty();
bool checkForBalancedParentheses(string Sentence);

int main()
{
	string sentence;
	cout<<"Enter an expression or a sentence: ";
	cin>>sentence;
	cout<<"Entered Expression: "<<sentence<<endl;
	
	bool balanceParentheses = checkForBalancedParentheses(sentence);
	if(balanceParentheses == true)
	{
		cout<<"Balanced Parentheses"<<endl;
	}
	else
	{
		cout<<"Not Balanced"<<endl;
	}

}

bool checkForBalancedParentheses(string Sentence)
{
	for(int index = 0; index < Sentence.length(); index++)
	{
		if(Sentence[index] == '(' || Sentence[index] == '[' || Sentence[index] == '{')
		{
			push(Sentence[index]);
		}
		else if(Sentence[index] == ')' || Sentence[index] == ']' || Sentence[index] == '}')
		{
			if((Sentence[index] == ')') && (top() == '(') || (Sentence[index] == ']') && (top() == '[')
				|| (Sentence[index] == '}') && (top() == '{'))
			{
				pop();
			}
			else
			{
				if((Sentence[index] == ')') && (!isEmpty()) || (Sentence[index] == ']') && (!isEmpty())  
			    || (Sentence[index] == '}') && (!isEmpty()))
				{
					break;
				}
				else
			    {
			    	push(Sentence[index]);
			    	break;
				}
			}
		}
		else
		{
			continue;
		}
	}
	
	return isEmpty() ? true : false;
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
	 
void push(char element)
{
	topOfStack += 1;
	stack[topOfStack] = element;
}

void pop()
{
	topOfStack -= 1;
}

char top()
{
	char topElement = stack[topOfStack];
	return topElement;
}

