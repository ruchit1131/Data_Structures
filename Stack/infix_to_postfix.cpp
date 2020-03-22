#include<bits/stdc++.h>
#include<iostream>
#include<stack>
using namespace std;

bool high_prec(char a, char b)
{
	if((a == '+' || a== '-') && (b == '*' || b == '/') )
	return 1;
	
	if(a == '(')
	return 1;
	
	return 0;
}

bool low_prec(char a, char b)
{
	if(b == '-' || b == '+')
		return 1;
	if((a == '*' || a == '/') && (b == '*' || b == '/'))
		return 1;
	
	return 0;
	
}

void infix_to_postfix(char c[], int n)
{
	stack<char> S;
	char ch;
	int i = 0;
	char expr[n];
	int j = 0;	
	while(c[i] != '\0')
	{
		if(isalpha(c[i]))
		{
			expr[j] = c[i];
			i++;
			j++;
			continue;
		}
		if( c[i] == '*' || c[i] == '+' || c[i] == '-' || c[i] == '/' || c[i] == '(' || c[i] == ')')
		{
			if(S.empty() || high_prec(S.top(), c[i]) || c[i] == '(')
			{
				S.push(c[i]);
				i++;
				continue;
			}
			

			if(c[i] == ')')
			{
				while(S.top() != '(')
				{
					ch = S.top();
					S.pop();
					expr[j] = ch;
					j++;
				}
				S.pop();
				i++;
				continue;
			}
			if(low_prec(S.top(), c[i]))
			{
				ch = S.top();
				S.pop();
				S.push(c[i]);
				expr[j] = ch;
				j++;
				i++;
				continue;
			}
			
			printf("INVALID INPUT");
			return;
			
		}
	}
	while(!S.empty())
	{
		ch = S.top();
		S.pop();
		expr[j] = ch;
		j++;
	}
	expr[j] = '\0';
	printf("%s", expr);
}

int main()
{
	char c[50];
	gets(c);
	infix_to_postfix(c, strlen(c));
	
}
