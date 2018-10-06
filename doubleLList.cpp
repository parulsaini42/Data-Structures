// doubly linked list
#include<iostream>
using namespace std;
class list
{ struct node
  {  int info;
    node * next;
    node * back;
  };
  node * start;
  node * last;
  node * ptr;
  node * N;
  public:
  	void insert();
  	void insertend();
  	void insertbw(int);
  	void delend();
  	void delbw(int);
  	void output();
  	void outputlast();
  	int count();
};

 void list::insert() 
 { start=new node;
 start->next=start;
 last=start;
 start->info=count();
 output();
 }
 
 
 int list::count()
{ int n=0;
 ptr=start;
 while(ptr->next!=start)
 { 
 ptr=ptr->next;
  n=n+1;
 }
 return (n);
}

 void list::insertend()
 { N=new node; 
 ptr=start;
 while(ptr->next!=start)
 {  ptr=ptr->next;
 }
 ptr->next=N;
 N->back=ptr;
 N->next=start;
 last=N;
 cout<<"\ninsert data of node\n";
 cin>>N->info;
 }
 
 void list::insertbw(int item)
 { 
  N=new node;
 ptr=start;
 while(ptr->info!=item)
   { if(ptr->next==start)
      { cout<<"\nitem not found - CANNOT INSERT\n";
      break;
	  }
	  ptr=ptr->next;
   }
   if(ptr->info==item)
   { N->next=ptr->next;
   N->back=ptr;
   ptr->next->back=N;
   ptr->next=N;
   cout<<"\nenter data of new node\n";
   cin>>N->info;
   cout<<"\n new list is\n";
   output();
   }
 }
 
 void list::delend()
 { if(start->next==start)
   { cout<<"\nno item in list\n";
      exit(0);
    } 
 node * save =start;
 ptr=start->next;
 while(ptr->next!=start)
 { save =ptr;
  ptr=ptr->next;
 }
 save->next=start;
 delete ptr;
 output();
 
}
void list::delbw(int item)
{ if(start->next==start)
 { cout<<"\nno item in list\n";
 exit(0);
  }  
ptr=start;
 while(ptr->info!=item)
 { if(ptr->next==start)
      { cout<<"\nitem not found - CANNOT delete\n";
      break;
	  }
  ptr=ptr->next;
 }
 if(ptr->info==item)
{ ptr->back->next=ptr->next;
ptr->next->back=ptr->back;
delete ptr;
output();
}
 
}
 
 void list::output()
 { start->info=count();
 ptr=start;
 while(ptr->next!=start)
 {  
 cout<<ptr->info<<"\t";
 ptr=ptr->next;
 }
  cout<<ptr->info;
 }
 
  void list::outputlast()
 { 
 ptr=last;
 cout<<ptr->info<<"\t";
 while(ptr->back!=start)
 {  
 ptr=ptr->back;
 cout<<ptr->info<<"\t";

 }
 ptr=ptr->back;
cout<<ptr->info<<"\t";
 }
 
 int main()
 { list l;
 int i ,m,e,c;
 char choice;

cout<<"\nlist is\n";
 l.insert();
  do
    { cout<<"\n ENTER\n  1.insert bw \n 2.insert end ";
	     cout<<"\n  3.delete bw \n 4.delete end \n 5. output\n 6. output from last\n";
    cin>>c;
	  switch(c)
        {      	 
        	case 1:
        		cout<<"\n enter element after which you wish to insert\n";
        		cin>>e;
        		l.insertbw(e);
        		 break;
        		case 2:
        			l.insertend();
        			 break;
        			case 3:
        				cout<<"\n enter data you wish to delete\n";
        		        cin>>e;	
        				l.delbw(e);
        				 break;
        					case 4:
        						l.delend();
        						 break;
        						 case 5:
        						 	cout<<"\nlist is\n";
        						 	l.output();
        						 	break;
        						 	case 6:
        						 		cout<<"\nlist from back is\n";
        						 	     l.outputlast();
        						 	     break;
    
		}
	cout<<"\ndo u wiah to perform another operation, enter y or n\n";
	cin>>choice;
	}while(choice=='y');

 return 0;
  }
