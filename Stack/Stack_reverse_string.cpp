#include<iostream>
#include<stack>//stack from STL
using namespace std;


void Reverse(char c[])//or you can also write: void Reverse(char *c) as array passes a pointer only.
{
	stack<char> S;
	int i = 0;
	while(c[i] != '\0')
	{
		S.push(c[i]);
		i++;
	}
	i = 0;
	while(!S.empty())
	{
		c[i] = S.top();
		S.pop();
		i++;
	}
	
}
int main()
{
	char c[51];
	printf("Enter a string\n");
	gets(c);
	Reverse(c);
	printf("Output = %s", c);
}
