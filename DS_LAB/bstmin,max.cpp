#include<iostream>
#include<stdlib.h>
//max element ,min element
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
    display(node1->right);//post order
    cout<<node1->data<<endl;}
   /*struct node* t=node1;
    while(t->left!=NULL)
    {
    	t=t->left;
	}
	cout<<"minimum is"<<t->data<<endl;*/
    /*else if(node1==NULL) 
    {
    cout<<"Tree is empty"<<endl;}*/
}
bool search(struct node *root, int key) 
{ 
    // Traverse untill root reaches to dead end 
    while (root != NULL) 
    { 
        // pass right subtree as new tree 
        if (key > root->data) 
            root = root->right; 
  
        // pass left subtree as new tree 
        else if (key < root->data) 
            root = root->left; 
        else
            return true;// if the key is found return 1 
    } 
    return false; 
} 
int main()
{
    struct node* root=NULL;
    int a,b,c;
    cin>>a;
    for(int i=0;i<a;i++)
    {
        cin>>b;
        root=insert_node(root,b);
    }
    //display(root);
    cout<<"enter element to be searched";
    cin>>c;
    if(search(root,c))
    {
    	cout<<"found"<<endl;
	}
    display(root);
}
