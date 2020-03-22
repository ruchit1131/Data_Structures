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
 
 void Insert(int data)
 {
 	Node *temp = Create_Node(data);
 	Node* temp1 = root;
 	Node* temp2;
 	int x;
 	if(root == NULL)
 	{
 		root = temp;
		 return;	
	}
	
	while(temp1 != NULL)
	{
		if(data <= temp1->data)
		{
			temp2 = temp1;
			temp1 = temp1->left;
			x = 0;
			continue;
		}
		
		if(data > temp1->data)
		{
			temp2 = temp1;
			temp1 = temp1->right;
			x = 1;
			continue;
		}
		
	}
	
	if(x == 0)
		temp2->left = temp;
	else
		temp2->right = temp;
		
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
 
 
 int main()
 {
 	Search(root, 2);
 	Insert(15);
 	Insert(10);
 	Insert(20);
 	Search(root, 10);
 	Search(root, 20);
 	Search(root, 15);
 	Search(root, 22);
 }
