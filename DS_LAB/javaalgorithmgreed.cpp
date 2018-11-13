#include<iostream>
#include <algorithm>
using namespace std;
#define weight1 60
int main()
{
	cout<<"enter size"<<endl;
	int n;
	cin>>n;
	int profit[n],weight[n],pwper[n];
	cout<<"enter profit and weight parallel"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>profit[i]>>weight[i];
		pwper[i]=profit[i]/weight[i];
	}
	cout<<"enter choice 1 for profit greed 2 for weight greed 3 for profit/weight"<<endl;
	int ch;
	cin>>ch;
	if(ch==1)
	{    
		// apply bubble 
	    for(int i=0;i<n-1;i++)
	    {
	    	for(int j=0;j<n-i-1;j++)
	    	{
	    		if (profit[j] < profit[j+1])
              //swap(&arr[j], &arr[j+1]);
              {
              	int temp=profit[j];
              	profit[j]=profit[j+1];
              	profit[j+1]=temp;
              	int temp1=weight[j];
              	weight[j]=weight[j+1];
              	weight[j+1]=temp1;
			  }
			}
		}
		for(int i=0;i<n;i++)
		{
			cout<<profit[i]<<" "<<weight[i]<<endl;
		}
		/*int t=0,weigh=0,pro=0;
		for(int i=0;i<n;i++)
		{
			weigh+=weight[t];
			pro+=profit[t];
			t++;
			if(weigh==60)
			{
				break;
			}	
			if(weigh>60)
			{
				//p/w*60-weight[]
				pro-=profit[i];
				int r=60-weight[i-1];
				pro+=profit[i]/weight[i]*r;
				break;
			}
	   }
	   cout<<pro;*/
	   int t,weigh=0,pro=0,s;
		for(int i=0;i<n;i++)
		{
			s=weigh;
			weigh+=weight[i];
			if(weigh<60)
			{
				pro+=profit[i];
				//cout<<"profit"<<pro<<endl;
			}
			else
			{
				
				t=60-s;
				cout<<"t"<<t<<endl;
				t=t*profit[i]/weight[i];
				cout<<"t"<<t<<endl;
				break;
			}
		}
		pro+=t;
		cout<<"profit"<<pro<<endl;
	}
	if(ch==3)
	{
		for(int i=0;i<n-1;i++)
	    {
	    	for(int j=0;j<n-i-1;j++)
	    	{
	    		if (pwper[j] < pwper[j+1])
              {
              	int temp=profit[j];
              	profit[j]=profit[j+1];
              	profit[j+1]=temp;
              	
              	int temp1=weight[j];
              	weight[j]=weight[j+1];
              	weight[j+1]=temp1;
              	
              	int temp2=pwper[j];
              	pwper[j]=pwper[j+1];
              	pwper[j+1]=temp2;
			  }
			}
		}
		for(int i=0;i<n;i++)
		{
			cout<<profit[i]<<" "<<weight[i]<<" "<<pwper[i]<<endl;
		}
		int t,weigh=0,pro=0,s;
		for(int i=0;i<n;i++)
		{
			s=weigh;
			weigh+=weight[i];
			if(weigh<60)
			{
				pro+=profit[i];
				//cout<<"profit"<<pro<<endl;
			}
			else
			{
				t=60-s;
				cout<<"t"<<t<<endl;
				t=t*pwper[i];
				//cout<<"t"<<t<<endl;
				break;
			}
		}
		pro+=t;
		cout<<"profit"<<pro<<endl;
		
	}
}
