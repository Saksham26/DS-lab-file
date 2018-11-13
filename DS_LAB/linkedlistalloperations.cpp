#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
int data;
struct node *next;
}*start;
struct node* create_node(int val)
{
	struct node *temp;
	temp=new(struct node);
	temp->data=val;
	temp->next=NULL;
	return temp;
}
void insert_beg()
{
	//int b=val;
    struct node *p;
    int x;
    cin>>x;
	p=create_node(x);
	if(start==NULL)
	{
	    start=p;
		p->next=NULL;
		}	
		else 
		p->next=start;
		start=p;
	
}
void insert_last()
{
	//int b=val;
	struct node *p;
	struct node *temp;
	int x;
	cin>>x;
    p=create_node(x);
    temp=start;
    while(temp->next!=NULL)
    {
    	temp=temp->next;
	}
	temp->next=p;
    p->next=NULL;
	
}
void traverse(struct node* k)
{
	struct node* t;
	t=start;
	while(t->next!=NULL)
	{
		cout<<t->data<<" ";
		t=t->next;
	}
	cout<<t->data;
	
}
void insert_before(int x)
{
	struct node *p;
	struct node *ptr;
	p=create_node(45);
    struct node *temp;
    temp=start;
    while(temp->data!=2)
    {
    	ptr=temp;
    	temp=temp->next;
	}
	p->next=temp;
	ptr->next=p;
}
void insert_after(int x)
{
	struct node *p;
	struct node *temp;
	temp=start;
	p=create_node(102);
	while(temp->data!=3)
	{
		temp=temp->next;
		}
		p->next=temp->next;	
		temp->next=p;
}
void delete_beg()
{
	struct node *p;
	p=start;
	if(start!=NULL)
	{
		if(start->next!=NULL)
		{
      		start=start->next;
      		free(p);
		}
	    else
			start=NULL;
			
	}
}

void delete_last()
{
	struct node *p;
	struct node *temp;
	p=start;
	while(p->next!=NULL)
	{
		temp=p;
		p=p->next;
	}
	temp->next=NULL;
	free(p);
}
void delete_after(int x)
{
	int val=x;
	struct node *p;
	struct node *temp;
	struct node *ptr;
	struct node *temp1;
	p=start;
	temp=start;
	ptr=start;
	temp1=start;
	while(p->data!=val)
	{
		p=p->next;
	}
	temp1=p->next;
	ptr=temp1->next;
	free(temp1);
	p->next=ptr;
	/*while(p->data!=val)
	{
		p=p->next;
	}
	struct node *temp;
	temp=p->next;
	p->next=temp->next;
	free(temp);*/
	
}
void delete_before(int x)
{
	int val=x;
	struct node *p;
	struct node *temp;
	struct node *temp1;
	struct node *temp2;
	p=start;
	temp=start;
	temp1=start;
	while(temp->data!=val && temp->next!=NULL)
	{
		p=temp1;
		temp1=temp;
		temp=temp->next;
	}
	p->next=temp;
	/*while(p->data!=val)
	{
		temp=p;
		p=p->next;
	}
	if(temp!=start)
	{
	
	temp1=start;
	temp2=start;
	while(temp1!=temp)
	{
		temp2=temp1;
		temp1=temp1->next;
	}
	
	temp2->next=p;
	//free(temp);
	free(temp1);*/
	
}
//else 
//delete_beg();

int main()
{
	start=NULL;
	insert_beg();
	insert_last();
	insert_last();
	insert_last();
	//insert_before(2);
	//insert_after(3);
	delete_after(1);
	//delete_beg();
	//delete_last();
	//delete_before(3);
	traverse(start);
}
