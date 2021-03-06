#include<stdlib.h>
#include<iostream>
#include<stack>
using namespace std;

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

void Stack_Reverse()
{
	stack<Node*> S;
	struct Node* temp = head;
	S.push(NULL);
	while(temp != NULL)
	{
		S.push(temp);
		temp = temp->next;
	}
	
	head = S.top();
	
	temp = head;
	
	while(S.top() != NULL) 
	{
		temp = S.top();
		S.pop();
		temp->next = S.top();
	}

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
	Insert(1, 1);
	Insert(2, 2);
	Insert(3, 1);
	Insert(4, 2);
	Insert(5, 1);
	Insert(6, 2);
	Insert(7, 1);
	Print();
	Stack_Reverse();
	Print();	
	return 0;
}


