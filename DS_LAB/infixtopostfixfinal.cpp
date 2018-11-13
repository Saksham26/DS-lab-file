#include<iostream>
using namespace std;
class In2post
{	int arr[50];
    char output[50];
    static int i;
	int top=0;
	public:
		void initiate()
		{arr[0]=0;
		}
		void push(char ch)
		{switch (ch)
		 {case '-':if(arr[top]>0)
		 			{pop();}
		 			 top++;
		 			 arr[top]=1;
					 break;
		  case '+':if(arr[top]>0)
		           {pop();}
		            top++;
		            arr[top]=2;
					break;
		  case '/':if(arr[top]==3||arr[top]==4)
		  			{pop();}
		  			 top++;
		  			 arr[top]=3;
		  			 break;
		  case '*':if(arr[top]==3||arr[top]==4)
		  			{pop();}
		  			top++;
		  			arr[top]=4;
		  			break;
		  case '(':top++;
		   		   arr[top]=0;
		   		   break;
		  case ')':while(arr[top]!=0)
		  			{pop();
					  }
					  pop();
					break;
		  default:output[i++]=ch;
		 }

	   }
	   void pop()
	  {  if(top==-1)
	  	 {cout<<"Stack is empty"<<endl;
		   }
		else{



		switch (arr[top])
		{case 0:top--;
				break;
		case 1:output[i++]='-';
				top--;
				 break;
		 case 2:output[i++]='+';
		 		top--;
		 		break;
		 case 3:output[i++]='/';
		 		top--;
		 		break;
		 case 4:output[i++]='*';
		 		top--;
		 		break;

		}

	}

		  }
	   int validate()
	   {if(top!=-1)
	    return 0;
	    else
	    return 1;
	   }
	   void display()
	   {for(int k=0;k<i;k++)
	    {cout<<output[k]<<" ";
		}
	   }

};
int In2post::i=0;

int main()
{	char arr[50];
    In2post p1;
    p1.initiate();
    int k=0;
    cin>>arr[k];
    while(arr[k]!='!')
    {p1.push(arr[k]);
     k++;
     cin>>arr[k];
	}
	p1.push(')');
	int j=p1.validate();
	if(j)
	{p1.display();
	}
	else
	cout<<"Parenthesis were not balanced";
	return 0;
}
