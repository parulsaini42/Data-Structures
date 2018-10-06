#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{ int info;
node *left;
node *right;
};
node * tree=NULL;

node * insert (node * tree,int treeval)
{ if (tree==NULL)
 { tree=new node;
   tree->left=NULL;
   tree->right=NULL;
   tree->info=treeval;
 }
 else if (tree->info>=treeval)
  tree->left=insert(tree->left,treeval);
  else 
  tree->right=insert(tree->right,treeval);
  
  return (tree);
}

void binarytree()
{ int val; 
  char choice; 
  cout<<"do u wish to insert element into tree  y/n \n";
 cin>>choice;
 if(choice=='y')
 { cout<<"enter element\n";
 cin>>val;
 tree=insert(tree,val);
 binarytree();
 }
 
}

void pretrav(node * tree)
{  if (tree!=NULL)
{ cout<<tree->info<<"\t";
  pretrav(tree->left);
  pretrav(tree->right);
}
} 
void intrav(node * tree)
{ if (tree!=NULL)
{ intrav(tree->left);
cout<<tree->info<<"\t";
  
  intrav(tree->right);
}
}
void posttrav(node * tree)
{
if (tree!=NULL)
{
posttrav(tree->left);
posttrav(tree->right);
cout<<tree->info<<"\t";
}
}

void Printtree( node * tree, int spaces )
{
  int i;
 
  if( tree != NULL )
  {
    Printtree( tree->right, spaces + 3 );
    for( i = 0; i < spaces; i++ )
      cout <<"    ";
    cout << tree->info << endl;
    Printtree( tree->left, spaces + 3 );
  }
}

int main()
{ int n;
char choice;
binarytree();

do
{ cout<<"enter 1.pretrav , 2.intrav ,3.posttrav ,4. display\n";
cin>>n;
switch(n)
  { case 1:
  	cout<<"preorder traversal is as follow:\t";
  	pretrav(tree);
  	break;
  	case 2:
  	cout<<"inorder traversal is as follow:\t";
  	intrav(tree);
  	break;
	  case 3:
	  cout<<"postorder traversal is as follow:\t";
  	posttrav(tree);
  	break;
	  case 4:
	  cout<<"tree as follow:\n";
	  Printtree(tree,0);
	  break;	
  }
cout<<"\ndo u wish to perform another operation\n";
cin>>choice;
}while(choice=='y');

return 0;
}
