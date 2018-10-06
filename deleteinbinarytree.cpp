//deletion in a binary tree`
#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{ int info;
node *left;
node *right;
};
node * tree;
node * par=NULL;
node * loc;
node * suc;
node * sucpar;
node * root;
int c;

node * insert (node * tree,int treeval)
{ 
if (tree==NULL)
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
        root=tree;
        binarytree();
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

node * deletenode(node * tree,node * loc ,node* par)
{ 
   if(  ( loc->left==NULL)  &&    (loc->right==NULL))
  { cout<<"\ncase when location to be deleted has no child\n";
    if(par==NULL)
    { cout<<"\nitem is the root-TREE EMPTY\n";
      }
	
	else 
     {
	    if (loc==par->left)
          par->left=NULL;
	    else
	      par->right=NULL;
     }
    delete loc;
     
    }

   
   else if((   (loc->left!=NULL)&&(loc->right==NULL) ) ||( (loc->right!=NULL)&&(loc->left==NULL) ))
        { 
  
   		cout<<"\ncase when location to be deleted has one child\n";
  
  
     if (loc->left!=NULL)
    {      if(par==NULL)
           	{ cout<<"item is the root\n";
			   tree=loc->left;
	          delete loc;
	          return (tree);
	        } 
        	else
            {	par->left=loc->left;
                delete loc;
            
             }
	}
	
	
     else if(loc->right!=NULL)
    { 
            if(par==NULL)
             	{ cout<<"item is the root\n";
				 tree=root=loc->right;
	          delete loc;
	           return (tree);
	          
	        } 
	         else
			 {
			   par->right=loc->right;
               delete loc;
            
              }
    }
     
  } 
 
   else if  (((loc->left!=NULL)&&(loc->right!=NULL)))
		{ 
		 int n;
		sucpar=loc->right;

  	
	  			if(sucpar->left==NULL)
   					{
					   suc=sucpar;
   						loc->info=suc->info ;
   						n=1;
  					 }
   
  
  				else
  					{  suc=sucpar->left;
					  	while(suc->left!=NULL)
      						{   sucpar=suc;
							  	suc=suc->left;
      							
      						}
     				loc->info=suc->info ; 
     				n=2;
     				
 					}

    switch(n)

{
	 case 1: 		if((suc->left==NULL)&&(suc->right==NULL))
  		       	{		
			        cout<<"\ncase when suc to be deleted has no child\n";
			        delete suc;
    		        loc->right=NULL;
   			      }
 
   	     	else if((suc->right!=NULL)&&(suc->left==NULL))
 		 	{  
			  cout<<"\ncase when suc to be deleted has one right child\n";
					loc->right=suc->right;
    				delete suc;
    			}
    
   			
   	case 2:   	if((suc->left==NULL)&&(suc->right==NULL))
  		       	{		
			        cout<<"\ncase when suc to be deleted has no child\n";
			        delete suc;
    		        sucpar->left=NULL;
   			      }
   			    
   	else if((suc->right!=NULL)&&(suc->left==NULL))
 		 	{ 
			  cout<<"\ncase when suc to be deleted has one right child\n";
		      sucpar->left=suc->right;
    		  delete suc;
    			
    
   			} 
	}
 if(par==NULL)
 return(tree);
  }
  
}

node * trav(node*tree,int item)
{ 
 if (tree->info!=item)
    {
          if (tree->info>=item)
           {par=tree;
              trav(tree->left,item);
              } 
          else 
           { par=tree;
            trav(tree->right,item);
            }
    }
 
 else
       {cout<<"\nitem found\n";
            loc=tree;
            cout<<"loc:"<<loc->info<<"\t";
              if (item!=root->info)
                  { 
			      cout<<"par:"<<par->info;
		        	deletenode(root,loc,par);
			       return (root);
                  }
              else
                  {par=NULL;
                   tree=deletenode(root,loc,par);
                    return (tree);
			      }
	   }
	
}

int countnode(node * tree)
{
 if (tree!=NULL)
{ countnode(tree->left);
c++;
  
  countnode(tree->right);
}
return c;
}

int maxdepth(node * tree)
{ int ld;
int rd;

 if(tree==NULL)
   return 0;
   else 
   {ld=maxdepth(tree->left);
   rd=maxdepth(tree->right);
    }
   
   if(ld>rd)
     return (ld+1);
    else
      return (rd+1);
}

int main()
{ int n;
char choice;
binarytree();

do
{ cout<<"enter 1.delete , 2. display, 3. insert, 4.count 5. depth\n";
cin>>n;
switch(n)
  { case 1:
  	cout<<"enter element you wish to delete\n";
  	cin>>n;
  	tree=trav(tree,n);
  	
  	break;
  	case 2:
  	Printtree(tree,3);
  	break;
	case 3:
	  binarytree();
	  break;
	case 4:
		c=0;
	cout<<"no. of nodes:"<<countnode(tree);	
	break;
	case 5:
		cout<<"depth:"<<maxdepth(tree);
	  
  }
cout<<"\ndo u wish to perform another operation\n";
cin>>choice;
}while(choice=='y');

return 0;
}
