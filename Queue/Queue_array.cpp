#include<bits/stdc++.h>
using namespace std;

int arr[10];
int front = -1;
int rear = -1;

void Enqueue(int x)
{
	if(rear == 9)
	{
		printf("Queue full\n");
		return;
	}
	if(front == -1 && rear == -1)
	{
		front++;
		rear++;
		arr[rear] = x;
		return;
	}
	rear++;
	arr[rear] = x;
}

void Dequeue()
{
	if(front > rear || (front == -1 && rear == -1))
	{
		printf("Queue Empty\n");
		return;
	}
	arr[front] = '\0';
	front++;
	
}

void Print()
{
	printf("\n");
	for(int i = 0; i <= 9; i++ )
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
	for(int i = 0; i <= 9; i++ )
	{
		printf("%d  ", i);
	}
}

int main()
{
	Enqueue(1);
	Dequeue();
	Dequeue();
	Dequeue();
	Dequeue();
	Dequeue();
	Dequeue();
	Dequeue();
	Dequeue();
	Enqueue(7);
	Dequeue();
	Enqueue(8);
	Dequeue();
	Enqueue(9);
	Dequeue();
	Enqueue(0);
	Dequeue();
	Dequeue();
	Dequeue();
	Dequeue();
	Dequeue();
	Enqueue(5);
	Dequeue();
	Enqueue(3);
	Dequeue();
	Enqueue(7);
	Enqueue(5);
	Dequeue();
	Enqueue(3);
	Dequeue();
	Enqueue(7);
	Enqueue(7);
	Enqueue(7);
	Enqueue(7);

	Print();
}



