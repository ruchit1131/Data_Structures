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
 int FindMin(Node* root)
 {
 	while(root->left != NULL)
 	{
 		root = root->left; 
	}
	return root->data;
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

Node* Delete(Node *root, int data) {
	if(root == NULL) return root; 
	else if(data < root->data) root->left = Delete(root->left,data);
	else if (data > root->data) root->right = Delete(root->right,data);
	// Wohoo... I found you, Get ready to be deleted	
	else {
		// Case 1:  No child
		if(root->left == NULL && root->right == NULL) { 
			delete root;
			root = NULL;
		}
		//Case 2: One child 
		else if(root->left == NULL) {
			Node *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) {
			Node *temp = root;
			root = root->left;
			delete temp;
		}
		// case 3: 2 children
		else { 
			int temp = FindMin(root->right);
			root->data = temp;
			root->right = Delete(root->right,temp);
		}
	}
	return root;
}
 
/*Node* Delete(Node*, int data)
 {
 	if(root == NULL) return root;
 		
 	else if(data < root->data) root->left = Delete(root->left, data);
 		
 	else if(data > root-> data )root->right = Delete(root->right, data);
 	
 	else {
	 
	 if(root->left == NULL && root->right == NULL)
 	{
	 
 		delete(root);
 		root = NULL;
	}
	else if(root->left == NULL)
	{
		Node* temp = root;
		root = root->right;
		delete temp;
	}
	else if(root->right == NULL)
	{
		Node* temp = root;
		root = root->left;
		delete temp;
	}
	else{
	
	
	int temp = FindMin(root->right);
	root->data = temp;
	root->right = Delete(root->right , temp);
}
	
  } 
  return root;
}
  
 */
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
 	LevelOrder(root);
 	Delete(root, 8);
 	LevelOrder(root);
}

