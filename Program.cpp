#include<iostream>
#include<stdio.h>
using namespace std;
struct list
{
       char name[24];
       int index;
       list *next;
}*head=NULL;
typedef struct list Node;

int main()
{
    cout<<"Enter EOF at the end of the input"<<endl;
    char a[20];
    cin>>a;
    while(a[0]!='E')
    {
         char *b=a+1;
         int val=0;         
         while(*b!=NULL)
         {
                  
                  val=val*10+(int)(*b) - 48; 
                  b++;
         }
         Node *node = new Node;
         Node *temp=head,*temp2=head;
         int j=0;
         char *p=a;
         while(*p!='\0')
         {
                        node->name[j++]=*p;
                        p=p+1;
         }
         node->name[j]='\0';
         node->index=val;
         if(head==NULL)
         {
                       head=node;
                       head->next=NULL;
         }
         else
         {
             for(; temp!=NULL && val > temp->index; temp2=temp,temp=temp->next);
             node->next=temp;
             temp2->next=node;
         }     
         cin>>a;
    }
    cout<<"Output"<<endl<<endl;
    Node* t2=head;
    do
    {
          cout<<t2->name<<endl;
          t2=t2->next;
    }while(t2!=NULL);
   
    system("pause");
    return 0;
}
