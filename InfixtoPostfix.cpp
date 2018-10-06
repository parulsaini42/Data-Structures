//infix to postfix with characters
#include<iostream>
#include<stdlib.h>
using namespace std;
class stacks
{ char s[50];
  int top=0;
 struct node
    { char info;
      node * link;
    };
    node * start=new node;
    node * ptr;
    node * N;
public:
	
 char pop();
 void peek();
 void push(char);
 

void input();
void output();
void list();

void insert(char);
  
   
};
void stacks::peek()
{
cout<<"\nelement at top of stck is\n";
while(top!=-1)
{
cout<<s[top];
top--;
}
}
void stacks::list()
{ start->link=NULL;
start->info=':';

}


void stacks::push(char m)
{ 
top++;
s[top]=m;

}


char stacks::pop()
{ 
char temp;
temp=s[top];
top--;
return temp;
}


void stacks::insert(char c)
{ ptr=start;
while(ptr->link!=NULL)
   { ptr=ptr->link;
     }
 N = new node;
 ptr->link=N;
 N->link=NULL;
 N->info=c;
}


void stacks::output()
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


void stacks::input()
{ char m,t;
s[0]='(';
cout<<"enter the element of infix notation";
cin>>m;

switch(m)
{

    case '(':
           push(m);
           break;
	  
	case ')':
        t=pop();
	    while (t!='(') 
	          {insert(t);
				  t=pop();
                 }
                 break;
    case '^': 
         push(m);
         break;
    case '/':   
	       
	    while( (s[top]=='*')||(s[top]=='^'))
	    { t=pop();
	    insert(t);
		}
		push(m);
		 break;
	case '*':   
	       
	    while( (s[top]=='/')||(s[top]=='^'))
	    { t=pop();
	    insert(t);
		}
			push(m);
		 break;
	case '-':   
	       
	    while( (s[top]=='/')||(s[top]=='*') ||(s[top]=='+')||(s[top]=='^'))
	    { t=pop();
	    insert(t);
		} 
			push(m);
		 break;
	case '+':   
	       
	    while( (s[top]=='/')||(s[top]=='*') ||(s[top]=='-')||(s[top]=='^'))
	    { 
		 t=pop();
	    insert(t);
		} 
			push(m);
		 break;	   
		default:
			insert(m);
}

  }

 int main()
 { 
 stacks S;
int n,i;
 S.list();
 cout<<"enter no of elements\n";
 cin>>n;
 for(i=1;i<=n;i++)
S.input();
S.peek();
 

  S.output();
  return 0;
 }
