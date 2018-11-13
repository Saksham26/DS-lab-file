#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node * create(int val)
{
	struct node *temp;
	temp=new(struct node);
	temp->data=val;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
void insert(struct node **root,struct node **p)
{
	struct node *temp;
	if(*root==NULL)
	{
		*root=*p;
	}
	else
	{
		if((*p)->data>(*root)->data)
		{
			if((*root)->right==NULL)
			{
			(*root)->right=*p;
			}
			else
			{
				insert(&(*root)->right,&(*p));
			}
		}
		else if((*p)->data==(*root)->data)
		{
			cout<<"value cannot be inserted";
		}
		else
		{
			if((*root)->left==NULL)
			{
			(*root)->left=*p;
			}
			else
			{
				insert(&(*root)->left,&(*p));
			}
		}
	}
}
void display(struct node *root)
{
	if(root==NULL)
	{
		return;
		
	}
	else
	{
		cout<<root->data<<" ";
		display(root->left);//RECURSION pre
		display(root->right);
	}
}
void search(struct node *root,int val)
{
	if(root->data==val)
	{
		cout<<"found"<<endl;
	}
	else
	{
		 if(root->data>val)
		{
			if(root->left!=NULL)
			search(root->left,val);
			else
			cout<<"not found"<<endl;
		}
		else 
		{
		if(root->right!=NULL)
		search(root->right,val);
		else 
		cout<<"not found"<<endl;
		}
	}
}
void delete_fun(struct node **root,struct node *temp,int val)
{
	struct node *s;
	if((*root)->left==NULL)
	{
		s=(*root)->right;
	}
	else
	{
	s=(*root)->left;
	}
	if(*root==NULL)
	{
		cout<<"there is no tree"<<endl;
	}
else if((*root)->data==val)
	{
		if(temp->data<val)
		{
			temp->right=s;
		}
		else 
		temp->left=s;
		free(*root);
	}
	else
	{
		if((*root)->data<val)
		{
			delete_fun(&(*root)->right,(*root),val);
		}
		else
		{
			delete_fun(&(*root)->left,(*root),val);
		}
	}
}
int main()
{
	struct node *p;
	struct node *root;
	root=NULL;
	int val;
	for(int i=0;i<8;i++)
	{
		cin>>val;
		p=create(val);
		insert(&root,&p);
	}
		int x;
	cout<<"enter item to be searched"<<endl;
	cin>>x;
	search(root,x);
	struct node *temp;
	temp=root;
	int d;
	cout<<"enter node to be deleted"<<endl;
	cin>>d;
	delete_fun(&root,temp,d);
	display(root);
}
