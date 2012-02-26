#include <iostream>
using namespace std;
struct node
{
       int data;
       node *left;
       node *right;
}*tree = NULL;
class makeTree
{
      int count;
      public:
             node *insert(node *,int digit)
             {
                  if(tree==NULL)
                  {
                    tree=new node;
                    tree->left=NULL;
                    tree->right=NULL;
                    tree->data=digit;
                    count++;
                  }
                  else
                  {
                    if (count%2==0)
                    tree->left=insert(tree->left,digit);           
                    else
                    tree->right=insert(tree->right,digit);
                    return tree;
                  }
             }
             void preorder(node *)
             {
                  if(tree!=NULL)
                  {
                   preorder(tree->left);
                   cout<<endl<<tree->data;
                   preorder(tree->right);
                   }
             }    
             void inorder(node *tree)
             {
                  if(tree!=NULL)
                  {
                   inorder(tree->left);
                   cout<<endl<<tree->data<<"-";
                   inorder(tree->right);
                   }
             } 
             void postorder(node *tree)
             {
                  if(tree!=NULL)
                  {
                   postorder(tree->left);
                   postorder(tree->right);
                   cout<<endl<<tree->data;
                   }
             }
                   
             makeTree()
             {
                       count=1;
             }
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
                        tree=M.insert(tree,digit);
                        break;
                        
                case 2: cout<<"The tree traversed in preorder is"<<endl;
                        M.preorder(tree);
                        break;
                     
                case 3: cout<<"The tree traversed in Inorder is"<<endl;
                        M.inorder(tree);
                        break;
                        
                case 4: cout<<"The tree traversed in Postoder is"<<endl;
                        M.postorder(tree);
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
/*node* makeTree :: insert(node *tree,int digit)
{
      if(tree==NULL)
      {
                    tree=new node;
                    tree->left=NULL;
                    tree->right=NULL;
                    tree->data=digit;
                    count++;
      }
      else
      {
          if (count%2==0)
          tree->left=insert(tree->left,digit);           
          else
          tree->right=insert(tree->right,digit);
          return tree;
};
void makeTree :: preorder(node *tree)
{
     if(tree!=NULL)
     {
                   cout<<endl<<tree->data;
                   preorder(tree->left);
                   preorder(tree->right);
     }
};
void makeTree :: inorder(node *tree)
{
     if(tree!=NULL)
     {
                   inorder(tree->left);
                   cout<<endl<<tree->data;
                   inorder(tree->right);
     }
};
void makeTree :: postorder(node *tree)
{
     if(tree!=NULL)
     {
                   postorder(tree->left);
                   postorder(tree->right);
                   cout<<endl<<tree->data;
     }
};*/
                   
     
                   
                   
                                 
                    
                           
                                                 
