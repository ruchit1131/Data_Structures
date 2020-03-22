#include<stdlib.h>
#include<stdio.h>

struct Node 
{
	int data;
	struct Node* next;
};

//struct Node* head; //global variable; can be accessed anywhere

struct Node* Insert(struct Node* head, int x)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = head;
	head = temp;
	return head;
}
void Print(struct Node* head)
{
	while( head != NULL)
	{
		printf("%d",head->data);
		head = head->next;
	}
}
int main()
{
	struct Node* head;
	head = NULL;
	printf("How many no.s? ");
	int n, i, x;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		printf("Enter the number: ");
		scanf("%d", &x);
		head = Insert(head, x);		
	}
	Print(head);
	
}


