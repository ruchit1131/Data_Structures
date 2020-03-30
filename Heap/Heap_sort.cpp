#include<bits/stdc++.h>
using namespace std;

int parent_less_than_child(int arr[], int pos, int n)
{
	int lc = pos * 2 + 1;
	int rc = pos * 2 + 2;
	if(rc < n)
	{
		if(arr[rc] >= arr[lc])
		{
			if(arr[rc] > arr[pos])
				return rc;
			else
				return 0;
		}
		else
		{
			if(arr[lc] > arr[pos])
				return lc;
			else
			return 0;
			
		}
	}
	else if(lc < n)
	{
		if(arr[lc] > arr[pos])
			return lc;
		else
			return 0;
	}
	else
	 return 0;
}

void delete_n_replace(int arr[], int n)
{
	if(n == 1)
	{
		return;
	}
	int max = arr[0];
	arr[0] = arr[n - 1];
	arr[n - 1] = max;
	n = n - 1;
	int pos = 0;
	int lc = pos * 2 + 1;
	int rc = pos * 2 + 2;
	while(parent_less_than_child(arr, pos, n))
	{
			int temp = parent_less_than_child(arr, pos, n);
			int temp1 = arr[temp];
			arr[temp] = arr[pos];
			arr[pos] = temp1;
			pos = temp;
			lc = pos * 2 + 1;
			rc = pos * 2 + 2;
	}
}

void sort(int arr[], int n)
{
	for(int i = 0; i < n; i++)
	{
		delete_n_replace(arr, n - i);
	}
}

void insert(int arr[], int pos)
{
	int element = arr[pos];
	int parent = arr[(pos - 1) / 2];
	while(parent < element && pos != 0) //max heap
	{
		int temp = parent;
		arr[(pos - 1) / 2] = element;
		arr[pos] =  temp;
		pos = (pos - 1) / 2;
		parent = arr[(pos - 1) / 2];
	}
}

int main()
{
	cout<<"Enter the number of elements: ";
	int n;
	cin>>n;
	int arr[n];
	cout<<endl<<"Enter elements:"<<endl;
	for(int i = 0; i < n; i++)
	{
		int a;
		
		cin>>a;
		
		if(i == 0)
		{
			arr[i] = a;	
			continue;
		}
		arr[i] = a;
		insert(arr, i);	
	}
	
	sort(arr, n);
	
	for(int i = 0; i < n; i++)
	{
		
		cout<<arr[i]<<" ";
	}
	
	
}
