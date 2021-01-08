#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int stack[10000];
int n = 0;
void push(int data);
int pop();
int empty();
int size();
int top();

int main()
{
	int N=0,input=0;
	char a[100];
	char _push[10] = "push";
	char _top[10] = "top";
	char _empty[10] = "empty";
	char _size[10] = "size";
	char _pop[10] = "pop";
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", a);
		if (strcmp(a, _push) == 0) {
			scanf("%d", &input);
			push(input);
		}
		if (strcmp(a,_top) == 0)
			printf("%d\n",top());
		if (strcmp(a, _size) == 0)
			printf("%d\n", size());
		if (strcmp(a, _empty) == 0)
			printf("%d\n", empty());
		if (strcmp(a, _pop) == 0)
			printf("%d\n", pop());
		
		
	}
	
}

void push(int data) 
{
	stack[n] = data;
	n += 1;
}

int pop()
{
	int data;
	if (empty())
		return -1;
	else {
		data = stack[n - 1];
		stack[n - 1] = 0;
		n -= 1;
		return data;
	}
		
}

int empty()
{
	if (stack[n - 1] > 0)
		return 0;
	else
		return 1;
}

int size()
{
	return n;
}

int top()
{
	if (empty())
		return -1;
	else
		return stack[n - 1];
}