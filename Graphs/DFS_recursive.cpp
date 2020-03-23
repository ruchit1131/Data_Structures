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

void DFS(vector<int> adj[], int arr[], int V, int u)
{
	arr[u] = 1;
	cout<<u<<" ";
	vector<int>::iterator i;
	for(i = adj[u].begin(); i != adj[u].end(); i++)
	{
		if(arr[*i] == 0)
		{
			DFS(adj, arr, V, *i);
		}
	}
	return;
}

int main()
{
	int V = 5;
	int arr[V];
	memset(arr, 0, sizeof(arr));
	vector<int> adj[V];
    addEdge(adj, 1, 0); 
    addEdge(adj, 0, 2); 
    addEdge(adj, 2, 1); 
    addEdge(adj, 0, 3); 
    addEdge(adj, 1, 4); 
    print(adj, V); 
    DFS(adj, arr, V, 0);
    return 0;
}
