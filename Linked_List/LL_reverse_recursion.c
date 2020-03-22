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

void Reverse()
{
	struct Node *t, *t1, *t2;
	t = head;
	t1 = t->next;
	t2 = t1->next;
	while(t2 != NULL)
	{
		t1->next = t;
		t = t1;
		t1 = t2;
		t2 = t2->next;
	}
	t1->next = t;
	head->next = NULL;
	head = t1;
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
void Print_rec(struct Node* temp)
{
	if(temp != NULL)
	{
	printf("%d", temp->data);
	Print_rec(temp->next);
	return;
	}
	else
	return;
	
	
}

void Print_rec_rev(struct Node* temp)
{
	if(temp != NULL)
	{
		Print_rec_rev(temp->next);
		printf("%d", temp->data);
		return;
	}
	else
	return;
}
void Reverse_rec(struct Node* temp)
{
	if(temp == NULL)
		return;
		
	if(temp->next == NULL)
	{
		head = temp;
		return;
	}
	struct Node* temp1 = temp->next;
	Reverse_rec(temp1);
	temp1->next = temp;
	temp1 = NULL;
	return;
}

int main()
{
	head = NULL; //empty list
	Insert(1, 1);
	Insert(2, 2);
	Insert(3, 1);
	Insert(4, 2);
	Insert(5, 1);
	Insert(6, 2);
	Insert(7, 1);
	Print_rec(head);
	printf("\n");
	Print_rec_rev(head);	
	return 0;
}


