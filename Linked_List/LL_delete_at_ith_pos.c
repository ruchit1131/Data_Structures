#include<stdlib.h>
#include<stdio.h>

struct Node 
{
	int data;
	struct Node* next;
};

struct Node* head; //global variable; can be accessed anywhere

void Insert(int data, int pos)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	struct Node* temp1 = head; 
	struct Node* temp2 = head; 
	temp->data = data;
	temp->next = NULL;
	
	if(pos == 1)
	{
		temp->next = head;
		head = temp;
		return;
	}
	
	int i = 0;
	while(temp1 != NULL)
	{
		temp2 = temp1;
		temp1 = temp1->next;
		i++;
	}
	
	if(pos > i + 1 || pos < 1)
	{
		printf("INVALID\n");
		return;
	}
	
	i = 0;
	temp1 = head;
	temp2 = head;
	while( i != pos - 1)
	{
		temp2 = temp1;
		temp1 = temp1->next;
		i++;
	}
		
	temp2->next = temp;
	temp->next = temp1;
		
	
	
}

void Delete(int pos)
{
	int i = 0;
	struct Node* temp = head;
	struct Node* temp1 = head; 
	
	while(temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	
	if(i == 0 || pos > i || pos < 1)
	{
		printf("INVALID\n");
		return;
	}
	if(pos == 1)
	{
		head = head->next;
		free(temp);
		return;
	}
	temp = head;
	i = 0;
	while(i != pos - 1)
	{
		temp1 = temp;
		temp = temp->next;
		i++;
	}
	temp1->next = temp->next;
	free(temp);
	
	
}

void Print()
{
	struct Node* temp = head;
	
	while( temp != NULL)
	{
		printf("%d",temp->data);
		temp = temp->next;
	}
}
int main()
{
	head = NULL; //empty list
	Insert(2, 1);
	Insert(3, 2);
	Insert(4, 1);
	Insert(5, 2);
	Print();
	Delete(4);
	Print();	
	return 0;
}


