#include<iostream>
using namespace std;
struct rec
{
	long num;
    rec *left;
    rec *right;
    bool rthread;
}*tree;
class searchTree
{
 public: 
        rec *delnum(long,rec *);
	    rec *insert(rec *,long);
	    void deletenode(long,rec *);
	    void search(rec *,long);
	    void preorder(rec *);
	    void inorder(rec *);
	    void postorder(rec *);
	    searchTree()
	    {
		tree=NULL;
	    }
};
int main()
{
    int choice;
    long digit;
    int element;
    searchTree ST;
    do
    {
        cout<<endl<<"Enter 1: Insert a node in the BST";
		cout<<endl<<"Enter 2: Search a node in BST";
		cout<<endl<<"Enter 3: Display(preorder)the BST";
		cout<<endl<<"Enter 4: Display(inorder)the BST";
		cout<<endl<<"Enter 5: Display(postorder) the BST";
		cout<<endl<<"Enter 6: Delete the element";
		cout<<endl<<"Enter 7: END";
		cout<<endl<<"Enter your choice ";   
        cin>>choice;
		switch(choice)
	    {
		   case 1: cout<<"Enter value: To quit enter 0"<<endl;
			       cin>>digit;
			       while(digit!=0)
				   {
				                  tree=ST.insert(tree,digit);
				                  cin>>digit;
                   };
                   break;
		   case 2: cout<<"Enter the number to be searched";
			       cin>>digit;
			       ST.search(tree,digit);
			       break;
		   case 3: cout<<endl<<"preorder traversing TREE"<<endl;
			       ST.preorder(tree);
                   break;
		   case 4: cout<<endl<<"inorder traversing TREE"<<endl;
			       ST.inorder(tree);
                   break;
		   case 5: cout<<endl<<"postorder traversing TREE"<<endl;
			       ST.postorder(tree);
                   break;
		   /*case 6: cout<<"Enter element which do you want delete from  the BST"<<endl;
			       cin>>digit;
			       ST.deletenode(digit,tree);
			       break;*/
		   case 6: cout<<"END";
			       break;
		};
  }while(choice!=6);
  system("pause");
  return 0;
}
void searchTree::insert(rec *tree,long digit)
{
	int check =0;
    if(tree==NULL)
	  {
		tree=new rec;
		tree->left=NULL;
		tree->num=digit;
		tree->right=tree;
	  }
     else
     {
         bool l=false;
         while(check!=1)
         {
                        if(digit<tree->num&&tree->left=NULL)
                        {
                              check =1;
                              l=true;
                        }
                        else if(digit<tree->num)
                        tree=tree->left;
                        else if(digit>tree->num&&tree->right=NULL)
                        {
                             l=false;
                             check=1;
                        }
                        else if(digit>tree->num)
                        tree=tree->right;
                        else
                        cout<<"Duplicate node:Node not added";
                        break;
         }
         if(l)
         setleft(tree,digit);
         else
         setright(tree,digit);
}
void searchTree::deletenode(long digit,rec *tree)
{
    rec *r,*q,*p=tree;
    bool l=false;
    if(tree==NULL)
    {
                  cout<<endl<<"Tree is empty.";
    }
    if(digit<tree->num)
    {
                       p=tree;
                       l=true;
                       deletenode(digit,tree->left);
    }                   
    if(digit>tree->num)
    {
                       p=tree;
                       l=false;
                       deletenode(digit,tree->right);
    }                   
    q=tree;
    if((q->right==NULL)&&(q->left==NULL))
    {
                                         if(l)
                                         p->left=NULL;
                                         else
                                         p->right=NULL;
    }                         
    else 
    {
         if(q->right==NULL)
         {
                           tree=q->left;
                           if(l)
                           p->left=tree;
                           else
                           p->right=tree;
         }                  
         else if(q->left==NULL)
         {
              tree=q->right;
              if(l)
              p->left=tree;
              else
              p->right=tree;
         }
         else
         {
             r=q->right;
             if(r->left=NULL)
             {
                        tree=r;
                        tree->left=q->left;
                        if(l)
                        p->left=tree;
                        else
                        p->right=tree;
             }
             else
             {
                 while(r->left!=NULL)
                 {
                          r=r->left;
                 }
                 q->num=r->num;
                 q=r;
             }
         } 
    }                                   
    delete q;
}

void searchTree::search(rec *tree,long digit)
{
	if(tree==NULL)
	   cout<<"The number does not exits"<<endl;
   else
	if(digit==tree->num)
	cout<<endl<<"Number is "<<digit;
   else
	if(digit<tree->num)
	   search(tree->left,digit);
   else
	  search(tree->right,digit);
}

void searchTree::preorder(struct rec *tree)
{
	if(tree!=NULL)
	  {
		cout<<endl<<tree->num;
		preorder(tree->left);
		preorder(tree->right);
	  }
}

void searchTree::inorder(struct rec *tree)
{
	if(tree!=NULL)
	    {
		inorder(tree->left);
		cout<<endl<<tree->num;
		inorder(tree->right);
	    }
}

void searchTree::postorder(struct rec *tree)
{
	if(tree!=NULL)
	  {
		postorder(tree->left);
		postorder(tree->right);
		cout<<endl<<tree->num;
	  }

}
