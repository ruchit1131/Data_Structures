#include<iostream>
#include<stack>
using namespace std;

bool match(char c, char d)
{
	if(c == ']' && d == '[' || c == '}' && d == '{' || c == ')' && d == '(' )
	return 1;
	return 0;
}

void Check_Par(char c[])
{
	stack<char> S;
	int i = 0;
	while(c[i] != '\0')
	{
		if(c[i] == '[' || c[i] == '{' ||c[i] == '(')
		{
			S.push(c[i]);
		}
		
		if(c[i] == ']' || c[i] == '}' || c[i] == ')')
		{
			if(S.empty())
			{
				printf("Parenthesis not balanced");
				return;
			}
			if(match(c[i], S.top()))
			{
				S.pop();
			}
			else
			{
				printf("Parenthesis not balanced");
				return;	
			}
		}
		if(c[i] != '(' && c[i] != ')' && c[i] != '{' && c[i] != '}' && c[i] != '[' && c[i] != ']')
		{
			printf("INVALID AGRUEMENTS");
			return;
		}
		i++;
	}
	printf("Parenthesis balanced");
}

int main()
{
	char c[50];
	gets(c);
	Check_Par(c);
}
