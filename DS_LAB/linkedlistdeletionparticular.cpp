#include<iostream>
using namespace std;
struct node{
    int data;
    struct node *next;
}*start;
struct node *create_node(int val){
    struct node *temp;
    temp=new struct node;
    temp->data=val;
    temp->next=NULL;
    return temp;
};
insert_beg(){
    struct node *p;
    int val;
    cin>>val;
    p=create_node(val);
    if(start==NULL){
        start=p;
        p->next=NULL;
    }
    else{
        p->next=start;
        start=p;
    }
}
insert_last(){
    struct node *p,*temp;
    int val;
    cin>>val;
    p=create_node(val);
    temp=start;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=p;
    p->next=NULL;
}

void particular(int val)
{
	int value1 =val;
	struct node *toDelete, *pt;
	if(start == NULL)
    {
        cout<<("List is already empty.");
    }
    else
    {
        toDelete = start;
        pt = start;

        /* Traverse to the last node of the list */
        while(toDelete->data!=value1)
        {
            pt = toDelete;
            toDelete = toDelete->next;
        }

        if(toDelete == start)
        {
            start = NULL;
        }
        else
        {
			
            pt->next = toDelete->next;
        }

        /* Delete the last node */
        //free(toDelete);

        cout<<("SUCCESSFULLY DELETED element from LIST\n");
    }
}
traverse(){
    struct node *p;
    p=start;
    while(p->next!=NULL)
	{
        cout<<p->data<<endl;
        p=p->next;
    }
    cout<<p->data;
}
int main(){
    start=NULL;
    int value;
    insert_beg();
    insert_last();
    insert_last();
    insert_last();
    cout<<"enter element to delete"<<endl;
    cin>>value;
    particular(value);
    traverse();
    return 0;
}

