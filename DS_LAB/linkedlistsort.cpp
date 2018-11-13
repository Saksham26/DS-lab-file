#include<iostream>
using namespace std;

struct node
    {
        int data;
        struct node *next;
    }*start;

    node * create_node(int val)
    {
        struct node * temp;
        temp = new(struct node);
        temp->data = val;
        temp->next = NULL;
        return temp;
    }

    insert_beg(int val)
    {
        struct node *P;
        P = create_node(val);
        if(start==NULL)
        {
            start=P;
            P->next=NULL;
        }

        else
        {
            P->next=start;
            start=P;
        }
    }

    insert_end(int val)
    {
        struct node *P,*temp;
        P=create_node(val);
        temp=start;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=P;
        P->next=NULL;
    }

    printList()
    {
        struct node *temp;
        temp=start;
        cout<<endl;
         while(temp->next!=NULL)
        {
            cout<<temp->data<<endl;
            temp=temp->next;
        }
        cout<<temp->data;
    }

    insert_sortorder(int val)
    {
        struct node *temp,*ptr,*P;
        P=create_node(val);
        temp=start;
        while((temp->data<val)&&(temp->next!=NULL))
        {
            ptr=temp;
            temp=temp->next;
        }
        if(temp->next==NULL)
        {
            temp->next=P;
            P->next=NULL;
        }
        else if(temp=start)
        {
            start=P;
            P->next=temp;
        }
        else
        {
            ptr->next=P;
            P->next=temp;
        }

    }
    int main()
    {
        start = NULL;

        int val,val2;
        cin>>val;
        while(val!=0)
        {
            insert_beg(val);
            cin>>val;
        }

        printList();

        cout<<"\n\nEnter the value to  be inserted in a list : ";
        cin>>val2;

        insert_sortorder(val2);
        printList();



        return 0;


    }




