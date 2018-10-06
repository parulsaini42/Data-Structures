// header node
#include<iostream>
using namespace std;
class list
{ struct node
  { int info;
   node * link;   
   };
   node *start;
   node *ptr;
   node * N;
   public:
   		void insert();
          	void insertend();
          	void insertbw(int);
          	void delend();
          	void delbw(int);
          	void output();
          	int count();
          	int maximum();
};
void list::insert()
{  
       //inserting the first node
        start=new node;  //header node
	   start->link=start;
	   N=new node;
      N->link=start->link;
      start->link=N;
      cout<<"\nenter the data of the node\n";
      cin>>N->info;
      }
   

int list::count()
{ int n=0;
 ptr=start;
 while(ptr->link!=start)
 { 
 ptr=ptr->link;
  n=n+1;
 }
 return (n);
}

int list::maximum()
{ int m,i=0;
ptr=start->link;
 m=ptr->info;
 while(ptr->link!=start)
 {    ptr=ptr->link;
 if(m<ptr->info)
  { m=ptr->info;
  
    }
 
}
    return (m);
 }

void list::insertend()
{     
	 ptr=start;
	 while(ptr->link!=start)
	   {    ptr=ptr->link;
         } 
		 N=new node; 
         ptr->link=N;
         N->link=start;
         cout<<"\nenter the data of the node\n";
         cin>>N->info;
	  } 
	  
void list::insertbw(int item)   
{ 
ptr=start->link;
while(ptr->info!=item)
   { if(ptr->link==start)
      { cout<<"\nelement not found in list-CANNOT INSERT\n";
	   break;
       } 
   ptr=ptr->link;
  
    }
   
    if(ptr->info==item)
   { N=new node;
   N->link=ptr->link;
   ptr->link=N;
   cout<<"\nenter data of new node\n";
   cin>>N->info;
   cout<<"\n new list is\n";
   output();
	}    
  
}
void list::delend()
{ node * save=start;
ptr=start->link;
while(ptr->link!=start)
   { save=ptr; 
   ptr=ptr->link;
     }
     save->link=start;
     delete ptr;
     cout<<"\n new list is\n";
   output();
}

void list::delbw(int item)
{  node * save=start;
  ptr=start->link;
  
   while(ptr->info!=item)
     { if(ptr->link==start)
      { cout<<"\nelement not found in list-CANNOT DELETE\n";
	   break;
       } 
	 save=ptr;
     ptr=ptr->link;
	 }
  
	 if(ptr->info==item)
	 { save->link=ptr->link;
	 delete ptr;
	 cout<<"\n new list is\n";
     output();
	 }
  }
  

void list::output()
{   start->info=count();
ptr=start;

while(ptr->link!=start)
{ 
cout<<ptr->info<<"\t";
ptr=ptr->link;
}
cout<<ptr->info;
} 
int main()
{ int m,i,d; 
list L;
cout<<"\nenter number of nodes you wish to enter\n";
cin>>m;
L.insert();
for(i=1;i<m;i++)
   {L.insertend();
    }
    cout<<"\n list is\n";
    L.output();
    cout<<"\nmax is \n";
    cout<<L.maximum();
    cout<<"\nenter element after which you wish to insert\n";
    cin>>d;
    L.insertbw(d);
    cout<<"\nlist after deletion of last node\n";
    L.delend();
    cout<<"\nenter element you wish to delete\n";
    cin>>d;
    L.delbw(d);
    return 0;
}
