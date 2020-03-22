#include<stdlib.h>
#include<stdio.h>

int top = -1;

struct Node
{
	int data;
	struct Node* next;
};

struct Node* head;

struct Node* Create_node(int x)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = NULL;
	return temp;
}

void Push(int x)
{
	struct Node* temp = Create_node(x);
	temp->next = head;
	head = temp;
	top++;
}

void Pop()
{
	if(top == -1)
	{
		printf("Empty Stack");
		return;
	}
	top--;
	struct Node* temp = head;
	head = head->next;
	free(temp);
	
}

void Print()
{
	struct Node* temp = head;
	while(temp != NULL)
	{
		printf("%d", temp->data);
		temp = temp->next;
	}
}

int main()
{
	head = NULL;
	Push(1);
	Push(2);
	Push(3);
	Push(4);
	Push(5);
	Push(6);
	Push(7);
	Push(8);
	Push(9);
	Push(0);
	Pop();
	Pop();
	Pop();
	Pop();
	Pop();
	Pop();
	Pop();
	Pop();
	Pop();
	Print();	
}
