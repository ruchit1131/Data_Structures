#include<stdlib.h>
#include<stdio.h>

int *a;
int top = -1;

void Push(int x)
{
	top++;
	*(a + top) = x;
}

void Pop()
{
	if(top == -1)
	{
		printf("Stack empty");
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
	printf("%d\n", *(a + top));
}

int main()
{
	a = (int*)malloc(sizeof(int));
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
	printf("%d\n", top);
	Pop();
	
	for(i = 0; i <= top; i++)
		printf("%d", *(a + i));

}

//the memory we are working on is not allocated and can be reallocated to another program. so dont allocate memory like this. always allocate memory in array if you need more.
