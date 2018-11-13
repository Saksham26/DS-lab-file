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
void deleteFirstNode()
{
    struct node *toDelete;

    if(start == NULL)
    {
        cout<<("List is already empty.");
    }
    else
    {
        toDelete = start;
        start = start->next;

        cout<<("\nData deleted =", toDelete->data);

        /* Clears the memory occupied by first node*/
        //free(toDelete);

        cout<<("SUCCESSFULLY DELETED FIRST NODE FROM LIST\n");
    }
}
int main(){
    start=NULL;
    insert_beg();
    insert_last();
    insert_last();
    insert_last();
    deleteFirstNode();
    traverse();
    return 0;
}

