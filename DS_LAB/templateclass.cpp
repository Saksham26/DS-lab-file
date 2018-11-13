//class template
//#include<iostream>
/template <class T>
//template <class T1,class T2,class T3>
class array
{
	T *ptr;
		int n;//size of array
			public:
				array(int a)
				{
					n=a;
					ptr=new T[n];
				}
				void read()
				{
					for(int i=0;i<n;i++)
					{
						cin>>ptr[i];
					}
				}
				void print()
				{
					for(int i=0;i<n;i++)
					{
						cout<<ptr[i]<<"";
					}
					cout<<"\n";
				}
				
};
int main()
{
	array <int> A(3);
	A.read();
	A.print();
	array <char> B(7);//7 characters
	B.read();
	B.print();
	//array<int,float,int> C(5),D(6),E(7);
	return 0;
}
//wap to add and subtract 2 arrays defined as a template class?*/
#include<iostream>
using namespace std;
template <class T1>
class add
{
	T1 *ptr1;
	T1 *ptr2;
	int a,b,c;
	public:
	add(int z,int y)
	{
		a=z;
		b=y;
		ptr1=new T1[a];
		ptr2=new T1[b];
	}	
	void read()
	{
	for(int i=0;i<a;i++)
	{
	cin>>ptr1[i];
    }
	}
	void read2()
				{
					cout<<"enter 2nd array"<<"\n";
					for(int i=0;i<a;i++)
					{
						cin>>ptr2[i];
					}
				}
				void print()
				{
					for(int i=0;i<a;i++)
					{
						cout<<ptr1[i]+ptr2[i]<<"\n";
					}
				}
				void print1()
				{
					for(int i=0;i<a;i++)
					{
						cout<<ptr1[i]-ptr2[i]<<"\n";
					}
				}	
};
int main()
{
	add <int> A(5,5),B(5,5);
	A.read();
	A.read2();
	A.print();
	B.read();
	B.read2();
	B.print1();
	return 0;
}
