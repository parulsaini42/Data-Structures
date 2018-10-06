//circular queues with arrays
#include<iostream>
#include<stdlib.h>
using namespace std;
class queues
{ int q[15];
 int front;
 int rear;
 public:
 	void que();
 	void insert();
 	int remove();
 	void output();
  
};
void queues::que()
{ 

front=1; //front=rear=null is empty list
rear=1;
}
void queues::insert()
{ int c;

if((rear>5)&& (q[1]==-1))
 { rear=1;   //circular
 }
if((rear>5)&& (q[1]!=-1))
    { cout<<"overflow\n";
  exit(0);
  }
  
cout<<"enter element to insert\t";
cin>>c;
 q[rear]=c;
 
 rear=rear+1; 
  if((front==rear))
{ cout<<"queue is full\n";
}
  }

int queues::remove()
{ 
int temp=q[front];
if (temp==-1)
{ cout<<"queue is empty cannot remove\n";
exit(0);
}
q[front]=-1;  //represents null value
front=front+1;
if (front>5) //greater then size of array
{ front=1; 
}
return temp;
}

void queues::output()
{ int i;
cout<<"queue is\t";
for(i=1;i<=5;i++)
  { cout<<q[i]<<"\t";
  }
  cout<<"\n";
 cout<<"indexes are\t"; 
for(i=1;i<=5;i++)  
  { cout<<i<<"\t";
  }
}


int main()
{ queues Q;
Q.que();
int n;
char choice;

do
{ cout<<"enter 1 to insert and 2 to delete and 3 to view queue\t";
cin>>n;
switch(n)
    { case 1:
    
		Q.insert();
		break;
    	case 2:
    	cout<<"element removed is\t"<<Q.remove();
    	break;
    	case 3:
    		
    		Q.output();
    		
    }
    cout<<"\ndo u wish to perform nother operation y or n\t";
    cin>>choice;
}while(choice=='y');
return 0;
}
