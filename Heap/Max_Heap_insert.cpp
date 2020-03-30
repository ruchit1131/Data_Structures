#include<bits/stdc++.h>
using namespace std;

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
	
	for(int i = 0; i < n; i++)
	{
		cout<<arr[i]<<" ";
	}
	
	
}
