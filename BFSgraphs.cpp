#include<iostream>
#include <queue>
using namespace std;
int flag[6];
int p[6];
int count=1;
queue <int> q;  
int n;
int graph[6][6]={{0,1,0,1,0,0},
             {1,0,1,1,0,0},
             {0,1,0,1,0,1},
             {1,1,1,0,1,0},
             {0,0,0,1,0,1},
             {0,0,1,0,1,0} };
int path(int n)
{ if(n!=-1)
  { path(p[n]);
    cout<<n;
  }
	return 0;
}

int main()
{  
  int par;
	int i;
	for(i=0;i<6;i++)
	{ flag[i]=0;
	}
	//holds parents
	p[0]=-1;
	
	par=0;
	q.push(0);
	flag[0]=1;
	cout<<"0"<<"\n";
	while(count!=6)
	{ q.pop();
	//push children of parent into stack
	for(i=0;i<6;i++)
	{ 
		if((graph[par][i]==1)&& (flag[i]==0))
		  { flag[i]=1;
		    q.push(i);
		    p[i]=par;
		  }
	}
	par=q.front();
	cout<<q.front()<<"\n";
	count++;
   }
   
   for(i=0;i<6;i++)
   { cout<<i<<"\t";
   }
   cout<<"\n";
    for(i=0;i<6;i++)
   { 
   cout<<p[i]<<"\t";
   }
   
   cout<<"\n enter node to print path\n";
   cin>>n;
   path(n);

   return 0;
   
}
