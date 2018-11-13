//st ques 
#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* create_node(int val)
{
    struct node* temp=new(struct node);
    temp->data=val;
    temp->right=NULL;
    temp->left=NULL;
    return temp;
}
struct node * minValueNode(struct node* node) 
{ 
	struct node* current = node; 

	/* loop down to find the leftmost leaf */
	while (current->left != NULL) 
		current = current->left; 

	return current; 
} 

/*void insert_node(struct node** root,struct node** p)
{
    if()
}*/
struct node* insert(struct node* node, int data) 
{ 
	/* If the tree is empty, return a new node */
	if (node == NULL) 
	return create_node(data); 

	/* Otherwise, recur down the tree */
	if (data < node->data) 
		node->left = insert(node->left, data); 
	else
		node->right = insert(node->right, data); 
	/* return the (unchanged) node pointer */
	return node; 
} 
void display(struct node* root)
{
    if(root!=NULL){
    display(root->left);
    cout<<root->data<<endl;
    display(root->right);}//in traversal
}
struct node* deleteNode(struct node* root, int data) 
{ 
	// base case 
	if (root == NULL) return root; 

	// If the key to be deleted is smaller than the root's key, 
	// then it lies in left subtree 
	if (data < root->data) 
		root->left = deleteNode(root->left, data); 

	// If the key to be deleted is greater than the root's key, 
	// then it lies in right subtree 
	else if (data > root->data) 
		root->right = deleteNode(root->right,data); 
        
	// if key is same as root's key, then This is the node 
	// to be deleted 
	else
	{ 
		// node with only one child or no child 
		if (root->left == NULL) 
		{ 
			struct node *temp = root->right; 
			delete(root); 
			return temp; 
		} 
		else if (root->right == NULL) 
		{ 
			struct node *temp = root->left; 
			delete(root); 
			return temp; 
		} 

		// node with two children: Get the inorder successor (smallest 
		// in the right subtree) 
		struct node* temp = minValueNode(root->right); 

		// Copy the inorder successor's content to this node 
		root->data = temp->data; 

		// Delete the inorder successor 
		root->right = deleteNode(root->right, temp->data); 
	} 
	return root; 
} 

int main()
{
    struct node* root=NULL;
    int a,b,c,d;
    cin>>a;
    for(int i=0;i<a;i++)
    {
        cin>>b;
   // p=create_node(b);
    //insert_node(&root,&p);
    root=insert(root,b);
    }
    cin>>c;
    for(int j=0;j<c;j++)
    {
        cin>>d;
        deleteNode(root,d);
    }
    display(root);
    
}
//q2 postorder traversal
#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    struct node* left;
    struct node* right;
    int data;
};
struct node* create_node(int data)
{
    struct node* temp=new (struct node);
    temp->data=data;
    temp->right=NULL;
    temp->left=NULL;
    return temp;   
}
struct node* insert_node(struct node* root,int data)
{
    if (root==NULL)
    {   
        return create_node(data);;
    }
    if(data<root->data)
    {
        root->left=insert_node(root->left,data);
    }
    else if(data>root->data)
    {
        root->right=insert_node(root->right,data);
    }
    return root;
}
void display(struct node* node1)
{   
    if(node1!=NULL)
    {
    display(node1->left);
    display(node1->right);
    cout<<node1->data<<endl;}
    /*else if(node1==NULL) 
    {
    cout<<"Tree is empty"<<endl;}*/
}
int main()
{
    struct node* root=NULL;
    int a,b;
    cin>>a;
    for(int i=0;i<a;i++)
    {
        cin>>b;
        root=insert_node(root,b);
    }
    display(root);
}
//q3-- max depth
#include<iostream>
using namespace std;
struct node
{
    struct node* left;
    struct node* right;
    int data;
};
struct node* create_node(int val)
{
    struct node* temp=new(struct node);
    temp->data=val;
    temp->right=NULL;
    temp->left=NULL;
    return temp;
}
struct node* insert_node(struct node* root,int data)
{
    if(root==NULL)
    {
        return create_node(data);
    }
    if(data<root->data)
    {
        root->left=insert_node(root->left,data);
    }
    else if(data>root->data)
    {
        root->right=insert_node(root->right,data);
    }
    return root;
}
int height (struct node* root)
{
    if(root==NULL)
    {
        return -1;
    }
    return max(height(root->left),height(root->right))+1;
}
int main()
{
    struct node* root=NULL;
    int a,b;
    cin>>a;
    for(int i=0;i<a;i++)
    {
        cin>>b;
        root=insert_node(root,b);
    }
    cout<<"Maximum Depth: "<<height(root)<<endl;
}

