#include<bits/stdc++.h>
using namespace std;

int arr[10];
int front = -1;
int rear = -1;
int no = 0; 

bool Queue_full()
{
	if(no == 10)
		return 1;
	return 0;
}

bool Queue_Empty()
{
	if(no == 0)
	{
		return 1;
		front = -1;
		rear = -1;
	}
	
	return 0;
	
}
void Enqueue(int x)
{
	if(Queue_full())
	{
		printf("Queue full\n");
		return;
	}
	else{
	
	if(front == -1 && rear == -1)
	{
		front++;
		rear++;
		arr[rear] = x;
		no++;
		return;
	}
	rear = (rear +1) % 10;
	arr[rear] = x;
	no++;
		}
}

void Dequeue()
{
	if(Queue_Empty())
	{
		printf("Queue Empty\n");
		return;
	}
	arr[front] = '\0';
	front = (front + 1) % 10;
	no--;
	
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



