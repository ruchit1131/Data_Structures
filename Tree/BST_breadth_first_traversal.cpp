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

void LevelOrder(Node* root)
{
	if(root == NULL)
	return;
	
	queue<Node*> Q;
	Q.push(root);
	Node* front;
	
	while(!Q.empty())
	{
		front = Q.front();
		cout<<front->data<<" ";
		if(front->left != NULL)
		Q.push(front->left);
		if(front->right != NULL)
		Q.push(front->right);
		Q.pop();
		
	}
	
	  
}

int main()
{
	root = Insert(root, 15);
 	root = Insert(root, 10);
 	root = Insert(root, 20);
 	root = Insert(root, 2);
 	root = Insert(root, 5);
 	LevelOrder(root);
}

