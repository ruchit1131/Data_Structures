 #include<bits/stdc++.h>
 using namespace std;
 
 struct Node
 {
 	int data;
 	Node* left;
 	Node* right;
 };  
 
 Node* root = NULL; //empty BST
 
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
 
 void Search(Node* root, int x)
 {
 	if(root == NULL)
 	{
 		printf("Not present\n");
 		return;
	}
	if(root->data == x)
	{
		printf("Data found\n");
		return;
	}
	if(x <= root->data)
	{
		Search(root->left, x);
	}
	else
	Search(root->right, x);
	
 }
 
 int Find_Min_iterative()
 {
 	Node* temp = root;
 	
 	if(temp == NULL)
 	{
 		printf("Empty tree");
 		return -1;
	 }
	 
	 while(temp->left != NULL)
	 temp = temp->left;
	 
	 return temp->data;
 }
 
 int Find_Min_recursive(Node* root)
 {
 	if( root == NULL)
 	{
 		printf("Tree Empty\n");
 		return -1;
	}
	if(root->left == NULL)
	{
		return root->data;
	}
	return Find_Min_recursive(root->left);
 }
 
 
 int main()
 {
 	int m;
 	Search(root, 2);
 	root = Insert(root, 15);
 	root = Insert(root, 10);
 	root = Insert(root, 20);
 	root = Insert(root, 2);
 	root = Insert(root, 5);
 	Search(root, 10);
 	Search(root, 20);
 	Search(root, 15);
 	Search(root, 22);
 	m = Find_Min_recursive(root);
 	cout<<m<<endl;
 }
