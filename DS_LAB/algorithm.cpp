//algorithms
#include<algorithm>
1-max_element(first,last):returns the index/address of the largest element in the range first,last.
e.g- itr=max_element(v.begin(),v.end());
cout<<*itr;
2-- min_element(first,last):________
__smallest___________
e.g-- cout<<min_elements(itr,itr+4);//*itr
				or
				itr=min_element(v,v+4);
								+---base of vector
								
3-- max(a,b): returns larger value from the two values passed.
e.g-- cout<<max('a','b')<<endl;
	or
	cout<<max(10,7);
	
4-- min(a,b):_____smaller__________
e.g:cout<<min('a','2');
	OR
	cout<<min(3.14,2.72);
5-- unique: removes duplicate values from the containers; by replacing the duplicate value by the next non-duplicate element.
e.g-- int arr[]={10,20,30,40,50};
 vector<int>vect;
 for(i=0;i<5;i++)
 {
 	vect[i]=arr[i]+i;
 }
 vector<int>::iterator i1,i;
 i1=unique(vect.begin(),vect.end());
 for(i=vect.begin();i!=i1;i++)
 {
 	cout<<vect[i]<<" "<<endl;
 }
 //copies the elements in the range (1,last) except the consecutive duplicate values...
 //only one element from every conseuctive loop of equivalent elements is copied 
6-- unique-copy
i1=unique_copy(arr,arr+5,vect.begin());
7-- reverse:reverse order in the range
e.g: reverse (vect.begin(),vect.end());

8-- reverse.copy:copies in the reverse order:
	e.g -- reverse_copy(arr,arr+5,vect.begin());
	                    beg   end   
						{source     }    dest.

9-- replace
replace(v,begin(),v.end(),3,10);
	or
	replace(itr,itr+5,5,6);
	
10-- replace_copy
replace_copy(arr,arr+5,vect.begin()3,10);
						dest.      old value,new value;
11-remove 
vector<int>::iterator itr;
remove (v.begin(),v.end(),3);

12-- remove_copy--
itr=remove_copy(v.begin(),v,end(),newv.begin(),3);

13--remove-copy:-
itr= 
