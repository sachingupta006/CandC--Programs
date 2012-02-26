#include<iostream>
using namespace std;
char choice;
int wish,no,check;
struct list
{
       int data;
       struct list *next;
       struct list *prev;
}*head=NULL,*end=NULL;
typedef struct list Node;
class Llist
{
      public:
             void create();
             void insert();
             void del();
             void traverse();
             void modify();
             void insertBegin();
             void insertMiddle(int);
             void insertEnd();
             void deleteBegin();
             void deleteMiddle();
             void deleteEnd();
             void search();
             int count;
             Llist()
             {
                    count=0;
             }
                    
};
int main()
{
    Llist l;
    cout<<"Do you want to create a linked list"<<endl;
    cin>>choice;
    if(choice=='y'||choice=='Y')
    l.create();
    else
    {
        system("pause");
        return 0;
    }
    /*cout<<"Now you have created a linked list"<<endl;
    cout<<"You can perform the following operations on it"<<endl;
    do
    {
               cout<<"\t \t 1: INSERTION"<<endl;
               cout<<endl;
               cout<<"\t \t 2: DELETION"<<endl;
               cout<<endl;
               cout<<"\t \t 3: TRAVERSAL"<<endl;
               cout<<endl;
               cout<<"\t \t 4: SEARCH"<<endl;
               cout<<endl;
               cout<<"\t \t 5: MODIFICATION"<<endl;
               cout<<endl;
               cout<<"\t \t 6: EXIT"<<endl;
               cin>>wish;
               switch(wish)
               {
                           case 1: l.insert();
                                   break;
                           case 2: l.del();
                                   break;
                           case 3: l.traverse();
                                   break;
                           case 4: l.search();
                                   break;
                           case 5: l.modify();
                                   break;
                           case 6: cout<<"Bye Bye"<<endl;
                                   break;
                           default: cout<<"Invalid choice. Enter again"<<endl;
                                    break;
               };
    }while(wish!=5);
    */
    system("pause");
    return 0;
}
void Llist::create()
{
     do
     {
     Node *node,*temp;
     node=new Node;
     cout<<"Enter the data item"<<endl;
     cin>>node->data; 
     node->next = NULL;
     node->prev= NULL;
     if(head!=NULL)
     {
                   temp->next = node->prev;
                   temp=node;
     }
     else
     {
         head=node;
         temp=node;
     }
     cout<<"One node created"<<endl;
     cout<<"Do you want to add more?"<<endl;
     cin>>choice;
     }while(choice=='y'||choice=='Y');
     cout<<"The linked list created is "<<endl;
     traverse();     
}
void Llist::traverse()
{
     Node *temp;
     temp=head;
     if(head==NULL)
     {
                   cout<<"The linked list is empty"<<endl;
                   return;
     }
     else
     {
         
         cout<<"-";
         while(temp->next!=NULL)
         {
                                cout<<temp->data<<"-";
                                temp=temp->next;              
                                count++;
         };
         cout<<temp->data<<"-";
         cout<<endl;
         count++;
         cout<<"No. of nodes are "<<count<<endl;                       
     }
     count=0;
}
void Llist :: Traverse()
{
     cout<<"Printing the Linked list is reverse"<<endl<<"-";
     Node *temp;
     temp=head;
     while(temp->head!=NULL)
     {
                            temp=temp->next;
     }
     while(temp->head!=NULL)
     {
                            cout<<temp->data<<"-";
                            temp=temp->prev;
                            count++;
     };
     cout<<temp->data<<"-";
     cout<<endl;
     count++;
     cout<<"No. of nodes are"<<count<<endl;
     }
     count=0;
}
     
                            
/*void Llist:: insert()
{
     b: cout<<"Where do you want to insert the data?"<<endl;
     cout<<endl;
     cout<<" 1: Insert at the beginning"<<endl;
     cout<<endl;
     cout<<" 2: Insert in the middle"<<endl;
     cout<<endl;
     cout<<" 3: Insert at the end"<<endl;
     cin>>wish;
     switch(wish)
     {
                 case 1: insertBegin();
                         break;
                 case 2: cout<<"Do you want to traverse the list"<<endl;
                         cin>>choice;
                         cout<<endl;
                         if(choice=='y'||choice=='Y')
                         traverse();
                         cout<<"Enter the no. before which you want to insert"<<endl;
                         cin>>no;
                         insertMiddle(no);
                         break;
                 case 3: insertEnd();
                         break;
                 default: cout<<"Invalid choice"<<endl;
                          goto b;
     };
}
void Llist :: insertBegin()
{
     Node *node;
     node=new Node;
     cout<<"Enter the data"<<endl;
     cin>>node->data;
     if(head==NULL)
     node->next=NULL;
     else
     node->next=head;
     head = node;
     traverse();
}
void Llist:: insertMiddle(int check)
{
     Node *node, *temp,*prev;
     node=new Node;
     cout<<"Enter the data"<<endl;
     cin>>node->data;
     node->next=NULL;
     for(temp=head;temp->next!=NULL;prev=temp,temp=temp->next)
     {
                if(temp->data==check)
                {
                                     prev->next=node;
                                     node->next=temp;
                                     cout<<"One Node added"<<endl;
                                     break;
                }
     }
     if(temp->next==NULL)
     cout<<"The no. was not found. No node added"<<endl;
     traverse();
}           
void Llist :: insertEnd()
{
     Node *node, *temp;
     node=new Node;
     cout<<"Enter the dat"<<endl;
     cin>>node->data;
     while(temp->next!=NULL)
     {
                     temp=temp->next;
     }
     temp->next=node;
     traverse();
}
void Llist::del()
{
     c: cout<<"Where do you want to delete"<<endl;
     cout<<" 1: Delete at the beginning"<<endl;
     cout<<" 2: Delete in the middle"<<endl;
     cout<<" 3: Delete at the end"<<endl;
     cin>>wish;
     switch(wish)
     {
                 case 1: deleteBegin();
                         break;
                 case 2: cout<<"Do you want to traverse the list"<<endl;
                         cin>>choice;
                         cout<<endl;
                         if(choice=='y'||choice=='Y')
                         traverse();
                         deleteMiddle();
                         break;
                 case 3: deleteEnd();
                         break;
                 default: cout<<"Invalid choice"<<endl;
                          goto c;
     };
}                    
void Llist :: deleteBegin()
{
     if(head==NULL)
     {
                   cout<<"The list is empty"<<endl;
                   return;
     }
     Node *temp;
     temp=head;
     head=head->next;
     delete temp;
     cout<<"One node deleted"<<endl;
     traverse();
}
void Llist:: deleteMiddle()
{
      Node *temp,*prev;
      cout<<"Enter the no. which you want to delete"<<endl;
      cin>>check; 
      for(temp=head;temp->next!=NULL;prev=temp,temp=temp->next)
      {
               if(temp->data==check)
               {
                                    prev->next=temp->next;
                                    delete temp;
               }
      }                     
      if(temp->next==NULL)
      {
                          cout<<"The number was not found"<<endl;
                          cout<<"No node deleted"<<endl;
      }
      traverse();                    
}
void Llist:: deleteEnd()
{
      Node *temp,*prev; 
      for(temp=head;temp->next!=NULL;prev=temp,temp=temp->next);
      prev->next=NULL;
      delete temp;
      traverse();
}
void Llist::search()
{
      Node *temp;
      int count=1; 
      cout<<"Enter the no. you want to find"<<endl;
      cin>>check;
      cout<<endl;
      for(temp=head;temp->next!=NULL;temp=temp->next)                
      {
          if(temp->data==check)
          {
                               cout<<"The number found at position "<<count<<endl;
                               break;
          }
          count++;
      }
      if(temp==NULL)
      cout<<"The number was not found"<<endl;
}
void Llist::modify()
{
     Node *temp;
     cout<<"Enter the number you want to change"<<endl;
     cin>>check;
     int rep;
     cout<<"Enter the number you want to replace with"<<endl;
     cin>>rep;
     cout<<endl;
     for(temp=head;temp->next!=NULL;temp=temp->next)
     {
             if(temp->data==check)
             temp->data=rep;
     }
     if(temp==NULL)
     {
                   cout<<"The number not found"<<endl;
                   cout<<"Cannot Replace"<<endl;
     }
     traverse();
}
*/
                           
     
     
     
      
     
         
     
                                  
                                    
                                    
                           
          
    

