
// This is an implementation of a Binary tree and 
// it supports the following functions
// Insertion 
// Deletion 
// Search 
// Preorder traversal
// Inorder traversal 
// Postorder traversal 
// Both recursive and serial implementation are given

// It uses a Stack.h  file, stacks are used for 
// iterative traversals

#include < iostream >
#include "Stack.h"
using namespace std;
stack <int> S1;
stack <int> S2;
bool check;

struct Tree
{      
       int ele;
       Tree *left;
       Tree *right;
}*root=NULL;

stack <Tree *> S3;
// stacks S1 and S2 are used during insertion 
// and deletion and S3 is used for traversals

class makeTree
{
      private:
			  // To count the totals node in the tree
              int count;
			  // used to record the success or failure of actions
			  // such as insertion or deletion of nodes
              bool flag;
      public:
             makeTree()
             {
                       count=1;
                       flag = false;
             }
             int check;
             void add(int );
             void Preorder(Tree *);
             void IPreorder(Tree *);
             void Inorder(Tree *);
             void IInorder(Tree *);
             void Postorder(Tree *);
             void IPostorder(Tree *);
             void deleteNode(Tree *, int);
             void search(Tree *,int);
             bool tempSearch(Tree *,int); 
             void replaceValue(Tree *,int,int);
};                                            
int main()
{
  int choice,digit,choice2;
  bool flag;
  makeTree M;
  do
  {
  cout<<endl<<"1: Insert a node in a tree"<<endl;
  cout<<endl<<"2: Preorder traversal of tree"<<endl;
  cout<<endl<<"3: Inorder traversal of a tree"<<endl;
  cout<<endl<<"4: Postorder traversal of tree"<<endl;
  cout<<endl<<"5: Delete an element from the tree"<<endl;
  cout<<endl<<"6: Search an element"<<endl;
  cout<<endl<<"7: Iterative Traversals"<<endl;
  cout<<endl<<"8: Exit"<<endl;
  cin>>choice;
  switch(choice)
  {
	case 1: cout<<"Enter the value to be inserted"<<endl;
			cin>>digit;
			M.add(digit);
			break;
			
	case 2: cout<<"The tree traversed in preorder is"<<endl;
			M.Preorder(root);
			break;
		 
	case 3: cout<<"The tree traversed in Inorder is"<<endl;
			M.Inorder(root);
			break;
			
	case 4: cout<<"The tree traversed in Postoder is"<<endl;
			M.Postorder(root);
			break;
			
	case 5: cout<<"Enter the digit whose node has to be deleted"<<endl;
			cin>>digit;
			check=M.tempSearch(root,digit);
			if(check)
			{
				M.deleteNode(root,digit);
			}
			else
			cout<<"the element is not in the tree"<<endl;    
			break;
			
	case 6: cout<<"Enter the digit which has to be searched"<<endl;
			cin>>digit;
			check=M.tempSearch(root,digit);
			if(!check)
			cout<<"The element was not found"<<endl;
			else
			cout<<"The element was found"<<endl;
			break;
	case 7: cout<<"Enter your choice"<<endl;
			cout<<"1: Preorder"<<endl;
			cout<<"2: Inorder"<<endl;
			cout<<"3: Postorder"<<endl;
			cin>>choice2;
			switch(choice2)
			{
				case 1: M.IPreorder(root);
						break;
				case 2: M.IInorder(root);
						break;
				case 3: M.IPostorder(root);
						break;
				case 4: cout<<"Sorry wrong choice"<<endl;
						break;
			};
			break;                           
			
	case 8: cout<<"Bye Bye"<<endl;
			break;
	
	default: cout<<"Invalid choice"<<endl;
			 break;
  };
 }while(choice!=8);
 
system("pause");
return 0;

} 

// This given algorithm always makes a balanced tree
// obviously that is done at an extra cost
// we always maintain a count of many nodes are currently in the
// tree and depending on that we insert the values in such a manner 
// that the tree is filled level by level
void makeTree :: add(int value)
{
     int c=count;
     if(count==1)
     {
        root=new Tree;     
        root->left=NULL;
        root->right=NULL;
        root->ele=value;
        count++;    
     }
     else
     {
         Tree *p=root;
         c=c/2;
		 //This calculates how many levels down we have to go
         while(c!=1)
         {
			  S1.push(c);
			  c=c/2;                                   
         }
		 // This selects whether we have to go to left or right child
         while(!S1.isEmpty())
         {
			c=S1.pop();
			if(c%2==0)
			p=p->left;
			else
			p=p->right;
         }
         Tree *temp=new Tree;
         temp->left=NULL;
         temp->right=NULL;
         temp->ele=value;
         if(count%2==0)
         p->left=temp;
         else
         p->right=temp;
         count++;
     }      
}  
bool makeTree :: tempSearch(Tree *p, int value)
{
    flag=false;
    search(p,value);
    return flag;
} 

// Recursively searches the tree for given value
// If the value is found it sets the flag which is read above
void makeTree :: search(Tree *p,int value)
{
    if(p!=NULL)
     {
          search(p->left,value);
          if(p->ele==value)
          {
              flag=true;
          }    
          search(p->right,value);
     }    
}

//Used to replace some value by another value if it
// exists
void makeTree :: replaceValue(Tree *p,int value,int value2)
{
    if(p!=NULL)
     {
          replaceValue(p->left,value,value2);
          if(p->ele==value)
          {
              p->ele=value2;
              return;
          }                  
          replaceValue(p->right,value,value2);
     }    
}

// Delete becomes a complex operation in such a balanced tree
// because we need to maintain the balance of the tree
// In this case the node's value is replaced by the lowermost
// rightmost node of the tree
void makeTree :: deleteNode(Tree *p,int value)
{
         Tree *t,*p2;
         p2=p;
         int element;
         int c_count=count-1;
         if(c_count==1)
         {
             delete p;
             count--;
             cout<<"The tree is empty now"<<endl;
             root=NULL;
             return;
         }    
		 
         int c=c_count/2;
         while(c!=1)
         {
			  S2.push(c);
			  c=c/2;                                   
         }
		 
         while(!S2.isEmpty())
         {
			c=S2.pop();
			if(c%2==0)
			p=p->left;
			else
			p=p->right;
         }
		 
         if(c_count%2==0)
         {
             t=p->left;
             element=t->ele;
             p->left=NULL;
             delete t;
         }
         else
         {
             t=p->right;
             element=t->ele;
             p->right=NULL;
             delete t;    
         }
         count--;
         replaceValue(p2,value,element);  
         cout<<"Node Deleted"<<endl;     
}        

//recursive  
void makeTree :: Postorder(Tree *p)
{
	  if(p!=NULL)
	  {
		   Postorder(p->left);
		   Postorder(p->right);
		   cout<<p->ele<<"-";
	  }
}

//recursive
void makeTree :: Inorder(Tree *p)
{
     if(p!=NULL)
     {
     Inorder(p->left);
     cout<<p->ele<<"-";
     Inorder(p->right);
     }
}

//recursive
void makeTree :: Preorder(Tree *p)
{
       if(p!=NULL)
       {
       Preorder(p->left);
       cout<<p->ele<<"-";
       Preorder(p->right);
       }   
}

// The best trick to understand these traversals is tp
// work them out on a piece of paper
//Iterative
void makeTree :: IInorder(Tree *p)
{
    do 
    { 
        while (p!=NULL)                      
        { 
            S3.push(p);
            p=p->left; 
        }
        if (!S3.isEmpty())
        { 
            p=S3.pop();
            cout<<p->ele<<"-";
            p=p->right; 
        } 
    }while(!S3.isEmpty()||p!=NULL);
}    

//Iterative
void makeTree :: IPreorder(Tree *p)    
{ 
    do 
    {     
        while (p!=NULL)
        { 
            S3.push(p);
            cout<<p->ele<<"-";
            p = p->left; 
        }
        if (!S3.isEmpty())
        {
             p=S3.pop();
             p = p->right; 
        } 
    } while(!S3.isEmpty()||p!=NULL);
}

//Iterative postorder traversal is the 
// trickiest one  
void makeTree :: IPostorder(Tree *p)  
{
    Tree *q;
    do 
    { 
        while (p!=NULL)
        { 
            S3.push(p);
            p=p->left;
        }
        if(!S3.isEmpty())
        {
            p=S3.pop();
            cout<<p->ele<<"-";
            q=S3.peep();
            if(p=q->left)
            p=q->right;
            else
            p=NULL;
        }    
    }while(!S3.isEmpty()||p!=NULL);
}
   


