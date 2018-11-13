#include<iostream>
using namespace std;
#define maximum 50
int top=-1;
int top1=-1;
char stack1[maximum];
char stack12[maximum];
void push(char a)
{
		if(top>=maximum-1)
	{
		cout<<"stack overflow\n";
	}
	else
	{
		stack1[++top]=a;
	}
}
void push1(char a)
{
		if(top1>=maximum-1)
	{
		cout<<"stack overflow\n";
	}
	else
	{
		stack12[++top1]=a;
	}
}
void peek()
{
	if(top!=-1)
	{
	cout<<stack1[top]<<endl;
    }
}
void peek1()
{
	if(top1!=-1)
	cout<<stack12[top1]<<endl;
}
void pop()
{
	if(top!=-1)
	{
			top-=1;
	}	
	else
	cout<<"stack underflow\n";
}
void pop1()
{
	if(top1!=-1)
	{
			top1-=1;
	}	
	else
	cout<<"stack underflow\n";
}
int main()
{
	string s;
	cin>>s;
	int count=0;
	int a=s.length();
	for(int i=0;i<a;i++)
	{
		if(s[i]=='('||s[i]=='{'||s[i]=='[')
		{
			push(s[i]);
			count++;
		}
	}
	for(int i=a-1;i>=0;i--)
	{
		if(s[i]==')'||s[i]==']'||s[i]=='}')
		{
			push1(s[i]);
		}
	}
	for(int i=0;i<count;i++)
	{
	peek();
	pop();
    }
    for(int i=0;i<count;i++)
	{
	peek1();
	pop1();
    }
    int j=0;
    int flag=0;
    for(int i=0;i<count;i++)
    {
    	if(stack1[i]=='('&&stack12[j]==')')
    	{
    		flag++;
		}
		else if(stack1[i]=='{'&&stack12[j]=='}')
    	{
    		flag++;
		}
		else if(stack1[i]=='['&&stack12[j]==']')
    	{
    		flag++;
		}
		j++;
	}
	if(count==flag)
	{
		cout<<"valid"<<endl;
	}
	else cout<<"invalid"<<endl;
	return 0;
}
