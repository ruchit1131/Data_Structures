#include<bits/stdc++.h>
#include<queue>
using namespace std;
struct Node
{
	int data;
	Node* left;
	Node* right;
};

Node* root = NULL;

 Node* Create_Node(int x)
 {
 	Node* temp = new(Node);
 	temp->data = x;
 	temp->left = NULL;
 	temp->right = NULL;
 	return temp;
 }
 

Node* Insert(Node* root, int data)
 {
 	if(root == NULL)
 	{
 		root = Create_Node(data);
			
	}
	else if(data <= root->data)
	{
		root->left =  Insert(root->left, data);
	}
	else
	{
		root->right = Insert(root->right, data);
	}
	return root;
	
	
 }
 
 int minof(int a, int b, int c)
 {
 	if(a == INT_MIN && b == INT_MIN)
 		return c;
 	if(a == INT_MIN)
 		return minof(b, c, INT_MAX);
 	if(b == INT_MIN)
 		return minof(a, c, INT_MAX);
	
 	if(a <= b)
 	{
 		if(a <= c)
			return a;
		else
			return c;
	}
	else
	{
		if(b <= c)
			return b;
		else
			return c;
	}
 }
 
  int maxof(int a, int b, int c)
 {
 	if(a == INT_MAX && b == INT_MAX)
 		return c;
 	if(a == INT_MAX)
 		return maxof(b, c, INT_MIN);
 	if(b == INT_MAX)
 		return maxof(a, c, INT_MIN);
 		
 	if(a >= b)
 	{
 		if(a >= c)
			return a;
		else
			return c;
	}
	else
	{
		if(b >= c)
			return b;
		else
			return c;
	}
 }
 
int Min(Node* root)
{
	if(root == NULL)
	{
		return INT_MIN;
	}
	int L_V = Min(root->left);
	int R_V = Min(root->right);
	return minof(L_V, R_V, root->data);
}

int Max(Node* root)
{
	if(root == NULL)
	{
		return INT_MAX   ;
	}
	int L_V = Max(root->left);
	int R_V = Max(root->right);
	return maxof(L_V, R_V, root->data);
}

bool isBST(Node* root)
{
	if(root == NULL)
		return 1;
	if((root->left == NULL && root->right == NULL))
		return 1;
	
	if((Min(root->left) <= root->data) && (Max(root->right) > root->data) && isBST(root->left) && isBST(root->right))
		return 1;
}

int main()
{
	root = Insert(root, 15);
 	root = Insert(root, 10);
 	root = Insert(root, 1);
 	root = Insert(root, 17);
 	root = Insert(root, 16);
 	root = Insert(root, 12);
 	root = Insert(root, 5);
 	root = Insert(root, 8);
 	printf("%d ", Min(root));
 	printf("%d ", Max(root));
 	cout<<isBST(root);
}

