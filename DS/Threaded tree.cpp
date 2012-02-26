#include <iostream>
#include "Stack.h"
using namespace std;
stack <int> S;
struct Tree
{      
       int ele;
       Tree *left;
       Tree *right;
}*root=NULL;
class makeTree
{
      private:
              int count;
      public:
             makeTree()
             {
                       count=1;
             }
             void add(int );
             void Preorder(Tree *);
             void Inorder(Tree *);
             void Postorder(Tree *);  
};                                            
int main()
{
  int choice,digit;
  makeTree M;
  do
  {
  cout<<endl<<"1: Insert a node in a tree"<<endl;
  cout<<endl<<"2: Preorder traversal of tree"<<endl;
  cout<<endl<<"3: Inorder traversal of a tree"<<endl;
  cout<<endl<<"4: Postorder traversal of tree"<<endl;
  cout<<endl<<"5: Exit"<<endl;
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
                        
                case 5: cout<<"Bye Bye"<<endl;
                        break;
                
                default: cout<<"Invalid choice"<<endl;
                         break;
  };
 }while(choice!=5);
system("pause");
return 0;
}
void makeTree :: add(int value)
{
     int c=count;
     if (count==1)
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
         while(c!=1)
         {
                      S.push(c);
                      c=c/2;                                   
         }
         while(!S.isEmpty())
         {
                            c=S.pop();
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
void makeTree :: Postorder(Tree *p)
{
                  if(p!=NULL)
                  {
                   Postorder(p->left);
                   Postorder(p->right);
                   cout<<p->ele<<"-";
                   }
}
void makeTree :: Inorder(Tree *p)
{
     if(p!=NULL)
     {
     Inorder(p->left);
     cout<<p->ele<<"-";
     Inorder(p->right);
     }
}
void makeTree :: Preorder(Tree *p)
{
       if(p!=NULL)
       {
       Preorder(p->left);
       cout<<p->ele<<"-";
       Preorder(p->right);
       }   
}
       
                                                 
