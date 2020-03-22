#include<bits/stdc++.h>
#include<iostream>
#include<stack>
using namespace std;

float eval(int a, int b, char c)
{
	if(c == '+')
		return a+b;
	if(c == '-')
		return a-b;
	if(c == '*')
		return a*b;
	if(c == '/')
		return a/b;
}

void evaluate_prefix(char c[], int n)
{
	stack<float> S;
	int j = 0;
	int i = n - 1;
	char num[10];
	while( i != -1)
	{
		if(isdigit(c[i]))
		{
		while(isdigit(c[i]))
		{
			num[j] = c[i];
			i--;
			j++;
		}
		num[j] = '\0';
		j = 0;
		int no = atoi(strrev(num));
		S.push(no);
		continue;
		}
		if(c[i] == ' ')
		{
			i--;
			continue;
		}
		
		if(c[i] == '+' || c[i] == '-' || c[i] == '*' || c[i] == '/')
		{
			float a = S.top();
			S.pop();
			if(S.empty())
			{
				printf("INVALID EXPRESSION\n");
				return;
			}
			float b = S.top();
			S.pop();
			S.push(eval(a, b, c[i]));
			i--;
			continue;
			
		}
		printf("INVALID SYMBOL");
		return;
	}
	
		i = S.top();
	S.pop();
	if(S.empty())
	{
		printf("Answer: %d", i);	
	}
	else
		printf("INVALID EXPRESSION");
}

void evaluate_postfix(char c[])
{
	stack<float> S;
	int i = 0, no;
	char num[10];
	int j = 0;
	while(c[i] != '\0')
	{
		if(isdigit(c[i]))
		{
		while(isdigit(c[i]))
		{
			num[j] = c[i];
			i++;
			j++;
		}
		num[j] = '\0';
		j = 0;
		no = atoi(num);
		S.push(no);
		continue;
		}
		if(c[i] == ' ')
		{
			i++;
			continue;
		}
		
		if(c[i] == '+' || c[i] == '-' || c[i] == '*' || c[i] == '/')
		{
			float b = S.top();
			S.pop();
			if(S.empty())
			{
				printf("INVALID EXPRESSION\n");
				return;
			}
			float a = S.top();
			S.pop();
			S.push(eval(a, b, c[i]));
			i++;
			continue;
			
		}
		printf("INVALID SYMBOL");
		return;
		
		
		
	}
	i = S.top();
	S.pop();
	if(S.empty())
	{
		printf("Answer: %d", i);	
	}
	else
		printf("INVALID EXPRESSION");
	
}

int main()
{
	char c[50];
	gets(c);
	//evaluate_postfix(c);
	evaluate_prefix(c, strlen(c));
	
}
