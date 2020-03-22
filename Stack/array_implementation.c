#include<stdio.h>
#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;
void Push(int x)
{
 	if(top == MAX_SIZE - 1)
 	{
 		printf("Stack overflow\n");
 		return;
	}
	A[++top] = x;
} 

void Pop()
{
	if(top == -1)
	{
		printf("No elememt to pop");
		return;
	}	
		
	top--;
}

void Top()
{
	if(top == -1)
	{
		printf("Stack Empty\n");
		return;
	}
	printf("%d\n", A[top]);
}

int main()
{
	int i;
	Push(1);
	Push(2);
	Pop();
	Push(3);
	Pop();
	Push(4);
	Push(5);
	Push(6);
	Push(7);
	Push(8);
	Push(9);
	Pop();
	Pop();
	Pop();
	Top();
	
	for(i = 0; i <= top; i++)
		printf("%d", A[i]);
}
