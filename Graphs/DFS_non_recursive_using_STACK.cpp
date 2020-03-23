#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int a, int b)
{
	adj[a].push_back(b);
	adj[b].push_back(a);
}

void print(vector<int> adj[], int V)
{
	vector<int>::iterator i;
	for(int j = 0; j < V; j++)
	{
		for(i = adj[j].begin(); i != adj[j].end(); i++)
		{
			cout<<j<<"->"<<*i<<endl;
		}
	}
}

void DFS(vector<int> adj[], int V,  int u)
{
	int arr[V];
	memset(arr, 0, sizeof(arr));
	vector<int>::iterator i;
	stack<int> S;
	S.push(u);
	arr[u] = 1;
	cout<<u<<" ";
	while(!S.empty())
	{
		int a = S.top();
		int flag = 1;
		for(i = adj[a].begin(); i != adj[a].end(); i++)
		{
			if(arr[*i] == 0)
			{
				flag = 0;
				arr[*i] = 1;
				S.push(*i);
				cout<<*i<<" ";
				break;
			}
		}
		if(flag == 1)
		S.pop();
	}
	cout<<endl;
}
int main()
{
	int V = 5;
	vector<int> adj[V];
    addEdge(adj, 1, 0); 
    addEdge(adj, 0, 2); 
    addEdge(adj, 2, 1); 
    addEdge(adj, 0, 3); 
    addEdge(adj, 1, 4); 
    print(adj, V); 
    DFS(adj, V, 0);
    DFS(adj, V, 1);
    return 0;
}
