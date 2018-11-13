//bst deletion
#include<iostream>
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
struct node* insert_node(struct node* root,int val)
{
    if(root==NULL)
    {
        return create_node(val);
    }
    if(val<root->data)
    {
        root->left=insert_node(root->left,val);
    }
    else if(val>root->data)
    {
        root->right=insert_node(root->right,val);
    }
    return root;
}
int display(struct node* root)
{
	static int sum=0;
    if(root!=NULL)
    {
        //cout<<root->data<<endl;
        display(root->left);
        display(root->right);
        if(root->left==NULL&&root->right==NULL)
        {
        	sum=sum+root->data;
		}
    }
    return sum;
}
struct node* minval(struct node* root)
{
    struct node* cur=root;
    while(cur->left!=NULL)
    {
        cur=cur->left;
    }
    return cur;
}
struct node* node_delete(struct node* root,int data)
{
    //no child
    if(root==NULL)
    {
       cout<<"No such element is in the tree"<<endl;
        return root;
    }
    if(data<root->data)
    {
        root->left=node_delete(root->left,data);
    }
    else if(data>root->data)
    {
        root->right=node_delete(root->right,data);
    }
    else
    {
        if(root->left==NULL)
        {
            struct node* temp=root->right;
            delete(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            struct node* temp=root->left;
            delete(root);
            return temp;
        }
        struct node* temp=minval(root->right);
        
        root->data=temp->data;
        root->right=node_delete(root->right,temp->data);
         
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
        root=insert_node(root,b);
    }
    //sum of leaf node
    cout<<display(root);
    /*
    cin>>c;
    for(int j=0;j<c;j++)
    {
        cin>>d;
        node_delete(root,d);
    }
    display(root);*/
}
//5 14 15 16 17 18 //2 15 16


