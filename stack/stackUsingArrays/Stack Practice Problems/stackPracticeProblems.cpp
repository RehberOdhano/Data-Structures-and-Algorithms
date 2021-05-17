#include <iostream>
#define SIZE 0
using namespace std;

void push(int element);
void pop();
int top();

int stack[SIZE];
int topOfStack = -1;


int main()
{
	
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
