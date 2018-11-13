#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
int data;
struct node *next;
struct node *prev;
}*start;
struct node* create_node(int val)
{
	struct node *temp;
	temp=new(struct node);
	temp->data=val;
	temp->next=NULL;
	temp->prev=NULL;
	return temp;
}
void insert_beg()
{
	struct node *p;
	int x;
	cin>>x;
	p=create_node(x);
	if(start==NULL)
	{
		start=p;
		p->next=NULL;
		p->prev=NULL;
	}
	else
	{
		p->next=start;
		start->prev=p;
		start=p;
		p->prev=NULL;	
	}
}
void insert_last()
{
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
	//else
	//p->next=NULL;
	temp->next=p;
	p->prev=temp;
}
void insert_after()
{
	cout<<"enter value to insert node after"<<endl;
	int q,t;
	cin>>q;
	cout<<"enter value of new node"<<endl;
	cin>>t;
		struct node *p;
	struct node *temp;
	temp=start;
	p=create_node(t);
	while(temp->data!=q)
	{
		temp=temp->next;
	}
	if(temp->next==NULL)
	{
		temp->next=p;
	p->prev=temp;
	}
	else
	{
	p->prev=temp;
	p->next=temp->next;
	temp->next->prev=p;
	temp->next=p;
}
}
void insert_before()
{
	cout<<"enter value to insert node before"<<endl;
	int h,g;
	cin>>h;
	cout<<"enter value of new node"<<endl;
	cin>>g;
		struct node *p;
	struct node *temp;
	temp=start;
	p=create_node(g);
	while(temp->data!=h)
	{
		temp=temp->next;
	}
	if(temp->prev==NULL)
	{
		start=p;
		p->next=NULL;
		p->prev=NULL;
	}
	else
	temp->prev->next=p;
	p->prev=temp->prev;
	p->next=temp;
	temp->prev=p;	
}
void delete_beg()
{
	struct node *p;
	if(start==NULL)
	{
		cout<<"no linked list formed"<<endl;
		
	}
	else
	
		if(start->next==NULL)
		{
			p=start;
			free(p);
			start=NULL;
		}
	
	else
	{
		p=start;
		start=p->next;
		start->prev=NULL;
		free(p);
	}
}
void delete_last()
{
	struct node *temp;
	temp=start;
	if(start==NULL)
	{
		cout<<"no linked list formed"<<endl;
	}
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->prev->next=NULL;
	free(temp);
}
void delete_before()
{
	cout<<"enter value to delete node before"<<endl;
	int h,g,count=0;
	cin>>h;
	struct node *p;
	struct node *temp0;
	struct node *temp;
	struct node *p1;
	p=start;
	temp0=start;
	temp=start;
	while(p->data!=h)
	{
		temp0=temp;
		temp=p;
		p=p->next;
		count+=1;	
	}
	if(count==0)
	{
		cout<<"couldnt delete befor 1st node sry"<<endl;
	}
	else
	if(count==1)
	{
			p1=start;
		start=p1->next;
		start->prev=NULL;
		free(p1);
	}
	else
	p->prev=temp0->next;
	temp0->next=p;
	temp->next=NULL;
	temp->prev=NULL;
	free(temp);
	//boundary condition count
}
void delete_after()
{
	cout<<"enter value to delete node after"<<endl;
	int h,g,count=0;
	cin>>h;
	struct node *ptr;
	struct node *temp0;
	struct node *temp;
	struct node *p1;
	temp=start;
	while(temp->data!=h)
	{
		temp=temp->next;
		count++;
	}
	//if(count==count-1)
	//else  
	ptr=temp->next;
	temp0=ptr->next;
	temp->next=temp0;
	temp0->prev=temp;
	free(ptr);
}
void delete_entire()
{
	
	
	
}
traverse(){
    struct node *pt;
    pt=start;
    while(pt->next!=NULL)
	{
        cout<<pt->data<<endl;
        pt=pt->next;
    }
    cout<<pt->data;
}
int main()
{
	start=NULL;
	insert_beg();
	insert_last();
	insert_last();
	insert_last();
	//insert_after();
	//insert_before();
	//delete_beg();
	//delete_last();
	//delete_before();
	delete_after();
	delete_entire();
	traverse();
}



