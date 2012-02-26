#include <iostream>
using namespace std;
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
             int count;
             void insert(int);
             void del(int);
             void Search(int);
             void Print1(int);
             void Print2(int,int);
             void printLeft(int,int);
             void printRight(int,int);
             void Print3();
             void Print4();
             Llist()
             {
                    count=0;
             }
                    
};
int no,wish;
int main()
{
    Llist l;
    cout<<"Creating a doubly linked list"<<endl;
    cout<<"Enter the digits. Press 0 whenever you want to exit"<<endl;
    cin>>no;
    while(no!=0)
    {
        l.insert(no);
        cin>>no;
    }
    cout<<"You have created a doubly Linked List. You can do the Following operations"<<endl;
    do
    {
               cout<<"\t \t 1: INSERT"<<endl;
               cout<<endl;
               cout<<"\t \t 2: REMOVE"<<endl;
               cout<<endl;
               cout<<"\t \t 3: SEARCH"<<endl;
               cout<<endl;
               cout<<"\t \t 4: PRINT"<<endl;
               cout<<endl;
               cout<<"\t \t 5: EXIT"<<endl;
               cout<<endl;
               cin>>wish;
               switch(wish)
               {
                           case 1: cout<<"Enter the number to be inserted"<<endl;
                                   cin>>no;
                                   l.insert(no);
                                   break;
                           case 2: cout<<"Enter the number to be deleted"<<endl;
                                   cin>>no;
                                   l.del(no);
                                   break;
                           case 3: cout<<"Enter the number to be searched"<<endl;
                                   cin>>no;
                                   l.Search(no);
                                   break;    
                           case 4: cout<<"How do you want to print the list"<<endl;
                                   cout<<endl;
                                   cout<<"\t \t 1: All the elements preceding a number"<<endl;
                                   cout<<"\t \t 2: All the elements within k units from a particular number."<<endl;
                                   cout<<"\t \t 3: The whole list from front"<<endl;
                                   cout<<"\t \t 4: The whole list from back"<<endl;
                                   int b;
                                   cin>>b;
                                   switch(b)
                                   {
                                       case 1: cout<<"Enter thr number preceding which numbers are to be printed"<<endl;
                                               cin>>no;
                                               l.Print1(no);
                                               break;
                                       case 2: cout<<"Enter the number"<<endl;
                                               cin>>no;
                                               cout<<"Enter the limits"<<endl;
                                               int x;
                                               cin>>x;
                                               l.Print2(no,x);
                                               break;
                                       case 3: l.Print3();
                                               break;
                                       case 4: l.Print4();
                                               break;
                                       default: cout<<"Invalid choice"<<endl;
                                                break;
                                    };
                                   break;
               };
    }while(wish!=5);
    system("pause");
    return 0;
}
void Llist:: insert(int a)
{
     Node *node,*temp,*temp2;
     node=new Node;
     node->data=a;
     node->next=NULL;
     node->prev=NULL;
     temp=head;
     temp2=head;
     if(head==NULL)
     {             head=node;
                   temp=node;
                   end=node;
                   count++;
     }
     else
     {
            for(int i=0;i<count;i++)
                {
                    if(a>=temp->data)
                    {
                                if(temp==head&&temp==end)
                                {
                                temp->next=node;
                                node->prev=temp;
                                if(node->next==NULL)
                                {
                                    end=node;
                                }   
                                count++;
                                return;
                                }
                                else if(temp==end)
                                {
                                    temp->next=node;
                                    node->prev=temp;
                                    node->next=NULL;
                                    end=node;
                                    count++;
                                    return;
                                }    
                                else
                                {
                                    temp2=temp;
                                    temp=temp->next;
                                }    
                            }
                            else
                            {
                                if(temp==head)
                                {
                                    node->next=temp;
                                    head=node;
                                    count++;
                                    return;
                                }
                                else
                                {
                                     node->next=temp;
                                     node->prev=temp2;
                                     count++;
                                     return;
                                }
                            }    
              }
     }
}
void Llist::del(int a)
{
  Node *temp,*temp2,*temp3;
  for(temp=head;temp->next!=NULL;temp2=temp,temp=temp->next)
  {
      if(a==temp->data)
      {
          if(temp==end)
          {
              temp2->next=NULL;
              end=temp2;
              delete temp;
          }
          else if(temp==head)
          {
              head=temp->next;
              head->prev=NULL;
              delete temp;
          }
          else
          {
               temp3=temp->next;
               temp2->next=temp3;
               temp3->prev=temp2;   
               delete temp;
           }
       }
       else
       {
           cout<<"The number not found in the list"<<endl;
       }
   }                
} 
void Llist::Search(int b)
{
    Node *temp;
    int counter=1;
    int flag=0;
    for(temp=head;temp->next!=NULL;temp=temp->next)
    {
        if(b==temp->data)
        {
           flag++;
           cout<<"The number found at the "<<counter<<" postion"<<endl;
        } 
        counter++;
    }
    if(flag==0)
    {
        cout<<"the number not found in the list"<<endl;
    }
}        
void Llist :: Print1(int c)
{
    Node *temp;
    int flag=0;
    for(temp=head;temp->next!=NULL;temp=temp->next)
    {
        if(flag ==1)
        {
            cout<<temp->data<<endl;
        }    
        if(temp->data==c)
        {
            flag=1;
            cout<<temp->data<<endl;
        }
    }
}
void Llist:: Print2(int a, int b)
{
    cout<<"You can print in the following manner"<<endl;
    cout<<"1: Towards right"<<endl;
    cout<<"2: Towards left"<<endl;
    cin>>wish;
    switch(wish)
    {
        case 1: printLeft(a,b);
                break;
        case 2: printRight(a,b);
                break;
        default: cout<<"You have entered wrong choice"<<endl;
    };
}
void Llist ::printLeft(int a,int b)
{
    Node *temp;
    for(temp=head;temp->next!=NULL;temp=temp->next)
    {
        if(temp->data==a)
        break;
    }
    for(int i=0;i<b;i++)
    {
            if(temp==head&&i<(b-1))
            {
                cout<<temp->data<<endl;
                cout<<"The list has reached its begining cannot go any further left"<<endl;
                return;
            }
            cout<<temp->data<<endl;   
            temp=temp->prev;  
    }
}
void Llist ::printRight(int a,int b)
{
    Node *temp;
    for(temp=head;temp->next!=NULL;temp=temp->next)
    {
        if(temp->data==a)
        break;
    }
    for(int i=0;i<b;i++)
    {    
    if(temp==end&&i<(b-1))
    {
        cout<<temp->data<<endl;
        cout<<"The list has reached its end. cannot go any further"<<endl;
        return;
    }
    cout<<temp->data<<endl;
    temp=temp->next;
    }    
}
void Llist :: Print3()
{
    Node *temp;
    for(temp=head;temp!=NULL;temp=temp->next)
    {
        cout<<temp->data<<endl;
    }
}
void Llist :: Print4()
{
    Node *temp;
    for(temp=end;temp->prev!=NULL;temp=temp->prev)
    {
        cout<<temp->data<<endl;
    }
}
        
            
                       
            
                                    

