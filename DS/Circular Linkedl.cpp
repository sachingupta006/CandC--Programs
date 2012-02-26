#include<iostream>
using namespace std;
char choice;
int wish,no,check;
struct list
{
       int data;
       struct list *next;
}*head=NULL;
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
    cout<<"Now you have created a circular linked list"<<endl;
    cout<<endl;
    cout<<"You can perform the following operations on it"<<endl;
    cout<<endl;
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
    }while(wish!=6);
    system("pause");
    return 0;
}
void Llist::create()
{
     cout<<"How many nodes do you want to add"<<endl;
     cin>>no;
     for(int i=0;i<no;i++)
     {
     Node *node,*temp;
     node=new Node;
     cout<<"Enter the data item"<<endl;
     cin>>node->data; 
     node->next = NULL;
     if(head!=NULL)
     {
                   temp->next =node;
                   temp=node;
                   node->next=head;
     }
     else
     {
         head=node;
         temp=node;
         node->next=head;
     }
     cout<<"One node created"<<endl;
     cout<<endl;
     }
     cout<<"The Linked list created is"<<endl;
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
         do
         {
                                cout<<temp->data<<"-";
                                temp=temp->next;              
                                count++;
         }while(temp->next!=head);
         cout<<temp->data<<"-";
         cout<<endl;
         count++;
         cout<<endl;
         cout<<"No. of nodes are "<<count<<endl;                       
     }
     count=0;
}
void Llist:: insert()
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
     Node *node,*temp;
     node=new Node;
     cout<<"Enter the data"<<endl;
     cin>>node->data;
     temp=head;
     do
     {
               temp=temp->next;
     }while(temp->next!=head);
     temp->next=node;                
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
     for(temp=head;temp->next!=head;prev=temp,temp=temp->next)
     {
                if(temp->data==check)
                {
                                     prev->next=node;
                                     node->next=temp;
                                     cout<<"One Node added"<<endl;
                                     break;
                }
     }
     if(temp->next==head)
     cout<<"The no. was not found. No node added"<<endl;
     traverse();
}           
void Llist :: insertEnd()
{
     Node *node, *temp;
     temp=head;
     node=new Node;
     cout<<"Enter the data"<<endl;
     cin>>node->data;
     do
     {
               temp=temp->next;
     }while(temp->next!=head);
     temp->next=node;
     node->next=head;
     traverse();
}
void Llist::del()
{
     c: cout<<"Where do you want to delete"<<endl;
     cout<<endl;
     cout<<" 1: Delete at the beginning"<<endl;
     cout<<endl;
     cout<<" 2: Delete in the middle"<<endl;
     cout<<endl;
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
     do
     {
               temp=temp->next;
     }while(temp->next!=head);
     temp->next=head->next;
     temp=head;
     head=head->next;
     delete temp;
     cout<<"One node deleted"<<endl;
     cout<<endl;
     traverse();
}
void Llist:: deleteMiddle()
{
      Node *temp,*prev;
      cout<<"Enter the no. which you want to delete"<<endl;
      cin>>check; 
      for(temp=head;temp->next!=head;prev=temp,temp=temp->next)
      {
               if(temp->data==check)
               {
                                    prev->next=temp->next;
                                    delete temp;
               }
      }                     
      if(temp->next==head)
      {
                          cout<<"The number was not found"<<endl;
                          cout<<"No node deleted"<<endl;
      }
      traverse();                    
}
void Llist:: deleteEnd()
{
      Node *temp,*prev; 
      for(temp=head;temp->next!=head;prev=temp,temp=temp->next);
      prev->next=head;
      delete temp;
      cout<<endl;
      traverse();
}
void Llist::search()
{
      Node *temp;
      int count=1; 
      cout<<"Enter the no. you want to find"<<endl;
      cin>>check;
      cout<<endl;
      for(temp=head;temp->next!=head;temp=temp->next)                
      {
          if(temp->data==check)
          {
                               cout<<"The number found at position "<<count<<endl;
                               break;
          }
          count++;
      }
      if(temp==head)
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
     for(temp=head;temp->next!=head;temp=temp->next)
     {
             if(temp->data==check)
             temp->data=rep;
     }
     if(temp==head)
     {
                   cout<<"The number not found"<<endl;
                   cout<<"Cannot Replace"<<endl;
     }
     traverse();
}

                           
     
     
     
      
     
         
     
                                  
                                    
                                    
                           
          
    

