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
void deleteLastNode()
{
    struct node *toDelete, *secondLastNode;

    if(start == NULL)
    {
        cout<<("List is already empty.");
    }
    else
    {
        toDelete = start;
        secondLastNode = start;

        /* Traverse to the last node of the list */
        while(toDelete->next != NULL)
        {
            secondLastNode = toDelete;
            toDelete = toDelete->next;
        }

        if(toDelete == start)
        {
            start = NULL;
        }
        else
        {
            /* Disconnect link of second last node with last node */
            secondLastNode->next = NULL;
        }

        /* Delete the last node */
        //free(toDelete);

        cout<<("SUCCESSFULLY DELETED LAST NODE OF LIST\n");
    }
}
int main(){
    start=NULL;
    int value;
    insert_beg();
    insert_last();
    insert_last();
    insert_last();
    deleteLastNode();
    traverse();
    return 0;
}

