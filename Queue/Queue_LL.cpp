#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* front = NULL;
Node* rear = NULL;

Node* Create_Node(int x)
{
	Node* temp = new(Node);
	temp->data = x;
	temp->next =NULL;
	return temp;
}
void Enqueue(int x)
{
	Node* temp = Create_Node(x);
	if(front == NULL)
	{
		front = temp;
		rear = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
	
}

void Dequeue()
{
	Node *temp = front;
	if(front == NULL)
	{
		printf("Empty queue\n");
		return;
	}
	 front = front->next;
	 delete(temp);
	
}

void Print()
{
	Node* temp = front;
	while(temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
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
