#include<stdlib.h>
#include<stdio.h>

int MAX_SIZE = 5;
int top = -1;
int *a;

void Push(int x)
{
	if(top == MAX_SIZE - 1)
	{
		MAX_SIZE *= 2;
		a = (int*)realloc(a, sizeof(int)*MAX_SIZE);
		top++;
		a[top] = x;
		return;
	}
	
		top = top + 1;
		a[top] = x;
}

void Pop()
{
	if(top == -1)
	{
		printf("Stack Empty");
		return;
	}
	top--;
}

int main()
{
	a = (int*)malloc(sizeof(int)*MAX_SIZE);
	int i;
	Push(1);
	Push(2);
	Push(3);
	Push(4);
	Push(5);
	Push(6);
	Push(7);
	Push(8);
	Push(9);
	Push(1);
	Push(2);
	Push(3);
	Push(4);
	Push(5);
	Push(6);
	Push(7);
	Push(8);
	Push(9);
	
	for(i = 0; i <= top; i++)
		printf("%d", a[i]);
}
