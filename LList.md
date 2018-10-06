# Data-Structures
linked lists insertion and deletion
#include<iostream>
using namespace std;
class linkedlist
{ 
   struct node
    { int info;
      node * link;
    };
    node * start=new node;
    node * ptr;
    int n;
    public:
    	void input();
    	void output();
    	void insertf();
    	void insertbw();
    	void deletef();
    	void deletebw();
};
void linkedlist::input()
{ int i; 
cout<<"enter the number of nodes\n";
cin>>n;
cout<<"enter the data of \t 1 \t node\n"; 
cin>>start->info;
ptr=start;
  for(i=2;i<=n;i++)
  { cout<<"enter the data of \t"<<i<<"\t node\n";
    ptr->link=new node;
    ptr=ptr->link;
    cin>>ptr->info;
   }
  ptr->link=NULL;
}
void linkedlist::output()
{ cout<<"list is\n";
  ptr=start;
  while((ptr->link)!=NULL)
  { 
  cout<<ptr->info;
  cout<<"\t";
  ptr=ptr->link;
  }
  cout<<ptr->info;
}
void linkedlist::insertf()
{ node * N=new node;
N->link=start;
start=N;
cout<<"\nenter the data in new node\n";
cin>>N->info;
output();
}
void linkedlist::insertbw()
{ int m,i;
cout<<"\ninsert after which node\n";
cin>>m;
ptr=start;
for(i=1;i<m;i++)
  { ptr=ptr->link;
   }
   node * loc=ptr;
   node * N=new node;
   N->link=loc->link;
   loc->link=N;
   
   cout<<"\nenter the data in new node\n";
   cin>>N->info;
output();
}
void linkedlist::deletef()
{ ptr=start;
start=ptr->link;
delete ptr;
output();
}
void linkedlist::deletebw()
{ node * loc;
int m,i;
cout<<"\n enter the node after which u wish to delete\n";
cin>>m;
ptr=start;
for(i=1;i<m;i++)
  { ptr=ptr->link;
  }
loc=ptr->link;
ptr->link=loc->link;
delete loc;
output();
}
int main()
{ linkedlist l;
l.input();
l.output();
cout<<"\ninserting in beginning of list\n";
l.insertf();
cout<<"\ninserting after a node of list\n";
l.insertbw();
cout<<"\ndelete first node of list\n";
l.deletef();
cout<<"\ndelete after which node of list\n";
l.deletebw();
return 0;
}
