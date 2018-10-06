#include<iostream>
using namespace std;
int main()
{ int a[20],i,n;
cout<<"enter the number of elements you wish to enter in array\n";
cin>>n;
cout<<"enter the elements of the array\n";
for (i=1;i<=n;i++)
{
  cin>>a[i];
}
int hold,j;

 for(i=2;i<=n;i++)
 {
 hold=a[i];
 { for(j=i-1;(j>0)&&(hold<a[j]);j--)
     { 
     a[j+1]=a[j];
	   }
	 a[j+1]=hold;	 
 }
}
cout<<"list after sorting\n";
cout<<"sorted list is\n";
for (i=1;i<=5;i++)
{
  
  cout<<a[i]<<"\n";
}

  cout<<"enter roll no. to be searched";
  int rollno;
  cin>>rollno;
  int f=1,l=n;
  int m=(f+l)/2;
  while(f<=l)
 {
  if (a[m]==rollno)
  { cout<<"element found at"<<m<<"th location";
    break;
  }
  if(rollno>a[m])
  { f=m+1;
    m=(f+l)/2;
  }
  if(rollno<a[m])
  {  l=m-1;
     m=(f+l)/2;
  }
  
}
if(f>l)
{ cout<<"element not found";
}

	return 0;
}
