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

void BFS(vector<int> adj[], int V, int u)
{
	int arr[V];
	memset(arr, 0, sizeof(arr));
	queue<int> Q;
	vector<int>::iterator i;
	Q.push(u);
	arr[u] = 1;
	while(!Q.empty())
	{
		int a = Q.front();
		Q.pop();
		cout<<a<<" ";
		for(i = adj[a].begin(); i != adj[a].end(); i++)
		{
			if(arr[*i] == 0)
			{
				Q.push(*i);
				arr[*i] = 1;
			}
		}
	}
	cout<<endl;
}
int main()
{
	int V = 5;
	vector<int> adj[V];
	addEdge(adj, 0, 1); 
    addEdge(adj, 0, 4); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 1, 3); 
    addEdge(adj, 1, 4); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 4); 
    print(adj, V); 
    BFS(adj, V, 0);
    BFS(adj, V, 1);
    return 0;
}
