#include<stdlib.h>
#include<stdio.h>
struct Node
{
	int data;
	struct Node* prev;
	struct Node* next;
};

struct Node* head;

void InsertAtHead(int x)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->prev = NULL;
	temp->next = NULL;
	if(head == NULL)
	{
		head = temp;
		return;
	}
	temp->next = head;
	head->prev = temp;
	head = temp;	
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

void Print_rev()
{
	struct Node* temp = head;
	while(temp->next != NULL && temp != NULL)
		temp = temp->next;
	while(temp != NULL)
	{
		printf("%d",temp->data);
		temp = temp->prev;
	}
}

 int main()
 {
 	head = NULL;
 	InsertAtHead(5);
 	InsertAtHead(4);
 	InsertAtHead(3);
 	InsertAtHead(2);
 	InsertAtHead(1);
 	InsertAtHead(0);
 	Print();
 	printf("\n");
 	Print_rev();
 	return 0;
 }
