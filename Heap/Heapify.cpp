#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int i, int n)
{
	int lc = 2*i + 1;
	int rc = 2*i + 2;
	int greatest = i;
	if(lc < n && arr[lc] > arr[i])
	{
		greatest = lc;
	}
		
	if(rc < n && arr[rc] > arr[greatest])
	{
		greatest = rc;	
	}
		
		
	if(greatest != i)
	{
		int temp = arr[greatest];
		arr[greatest] = arr[i];
		arr[i] = temp;	
		heapify(arr, greatest, n);
	}
		
	
}

void make_heap(int arr[], int n)
{
	for(int i = n/2 - 1 ; i >= 0; i--)
	{
		heapify(arr, i, n);
	}
}
int main()
{
	int n;
	cout<<"Enter the no. of elements: ";
	cin>>n;
	cout<<endl;
	int arr[n];
	
	for(int i = 0; i < n; i++)
	{
		int b;
		cin>>b;
		arr[i] = b;
	}
	
	make_heap(arr, n);
	
	for(int i = 0; i < n; i++)
	{
		cout<<arr[i]<<" ";
	}
}
