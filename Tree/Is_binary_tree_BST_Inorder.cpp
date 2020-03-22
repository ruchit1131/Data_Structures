#include<bits/stdc++.h>
#include<queue>
using namespace std;
struct Node
{
	int data;
	Node* left;
	Node* right;
};

int MIN = INT_MIN;
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

bool isBST(Node* root)
{
	if(root == NULL)
		return 1;
	
	if(isBST(root->left) && root->data >= MIN && isBST(root->right))
	{
		MIN = root->data;
		return 1;
	}
	return 0;
	
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
 	cout<<isBST(root);
}

