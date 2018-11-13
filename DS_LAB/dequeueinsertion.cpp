//deque double ended queue insertion and deletion at bth sides 
//input restricted-- input insertion at one side deletion can be on both sides
//output restricted- vice versa deletion at one side l or r but insertion can be on both sides  
// left=-1,reight=-1;  
//insertion at left                                           //insertion at right 
//
/*#include<iostream>
using namespace std;
int left1=-1,right1=-1;
# define n 4 //elements
int arr[n];
void push_right1(int val)
{
	if(left1==-1&&right1==-1)
	{
		left1=right1=0;
		arr[left1]=val;
	}
	if(left1==0&&right1==n-1)
	{
		cout<<"overflow in pushright1"<<endl;
	}
	if(left1!=0&&right1==n-1)//delete from -> right1 side towards left1
	{
		right1=0;
		left1=right1+1;
	}
	else
	arr[right1++]=val;
}
void push_left1(int val)
{
		if(left1==0&&right1==n-1)
	{
		cout<<"overflow in pushleft1"<<endl;
	}
	if(left1=right1=-1)
	{
		left1=right1=0;
		arr[left1]=val;
	}
	if(left1==0&&right1!=n-1)
	{
		left1=n-1;
	}
	if(left1==right1+1)
	{
		cout<<"overflow"<<endl;
	}
	else 
	arr[left1--]=val;
}
void delete_right1()
{
	if(left1=right1=-1)
	{
		cout<<"underflow"<<endl;
	}
	if(left1==right1)
	{
		left1=right1=-1;
	}
	if(right1==0&&right1!=left1)
	{
		right1=n-1;
	}
	else
	right1-=1;
}
void delete_left1()
{
	if(left1=right1=-1)
	{
		cout<<"underflow"<<endl;
	}
	if(left1==right1)
	{
		left1=right1=-1;
	}
	if(left1==n-1&&left1!=right1)
	{
		left1=0;
	}
	else
	left1+=1;
}
void dispright1()
{
	for(int i=left1;i<=right1;i++)
	{
		cout<<arr[i]<<endl;
	}
}
int main()
{
	push_right1(10);
	push_right1(10);
	push_right1(10);
	push_right1(10);
	dispright1();
	
}*/
#include<iostream>
using namespace std;
class dequeue
{
    int l,r,*a,n;
public:
    dequeue(int s)
    {
        l=r=-1;
        n=s;
        a=new int(n);
    }
    void insertright(int v)
    {
        if(l==0&&r==n-1||(l=r+1))
            cout<<"Overflow"<<endl;
        else if(l==-1&&r==-1)
            {
                l=r=0;
                a[r]=v;
            }
        else if(l!=0&&r==n-1)
            {
                r=0;
                a[r]=v;
            }
        else a[++r]=v;
    }
    void insertleft(int v)
    {
        if((l==0&&r==n-1)||(l==r+1))
            cout<<"Overflow"<<endl;
        else if(l==-1&&r==-1)
            {
                l=r=0;
                a[l]=v;
            }
        else if(l==0&&r!=n-1)
            {
                l=n-1;
                a[l]=v;
            }
        else a[--l]=v;
    }
    void deleteleft()
    {
        if(r==-1)
            cout<<"Underflow"<<endl;
        else if(l==r)
            l=r=-1;
        else if(l==0&&r!=l)
            l=n-1;
        else l++;
    }
    void deleteright()
    {
        if(l==-1)
            cout<<"Underflow"<<endl;
        else if(l==r)
            l=r=-1;
        else if(r==n-1&&l!=r)
            r=0;
        else r--;
    }
    void display()
    {
        int f=l,rr=r;
        cout<<"Elements are:"<<endl;
        if(f<=rr)
        {
            while(f<=rr)
            {
                cout<<a[f]<<" ";
                f++;
            }
        }
        else
        {
            while(f<=n-1)
            {
                cout<<a[f]<<" ";
                f++;
            }
            f=0;
            while(f<=rr)
            {
                cout<<a[f]<<" ";
                f++;
            }
        }
    }
};
int main()
{
    dequeue d(10);
    d.insertleft(10);
    d.insertleft(20);
    d.insertleft(30);
    d.deleteleft();
    d.display();
}
