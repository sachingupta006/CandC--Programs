#include<iostream>
#include<process.h>
using namespace std;
struct Queque
{
       int no;
       struct Queque *next;
}*start=NULL;
typedef struct Queque sq;
class queque
{
      private:
              int value;
      public:
      void add();
      int remove();
      void traverse();
};
int main()
{
    queque Q;
    int choice,item;
    do
    {
        cout<<"Enter your choice"<<endl;
        cout<<"1: Add a number"<<endl;
        cout<<"2: Remove a number"<<endl;
        cout<<"3: Traverse"<<endl;
        cout<<"4: Exit"<<endl;
        cin>>choice;
        switch(choice)
        {
                      case 1: Q.add();
                              break;
                      case 2: item=Q.remove();
                              if(item!=0)
                              cout<<"The number removed is "<<item<<endl;
                              break;
                      case 3: Q.traverse();
                              break;
                      case 4: cout<<"You are exiting now"<<endl;
                              break;
                      default : cout<<"Invalid choice Try again"<<endl;
                                break;
        };
    }while(choice!=4);
    system("pause");
    return 0;
}
void queque:: add()
{
     sq *node,*temp;
     node = new(sq);
     temp = start;
     cout<<"Enter the data"<<endl;
     cin>>node->no;
     if(start==NULL)
     {
                    start=node;
     }
     else
     {
         while(temp->next!=NULL)
         {
                                temp=temp->next;
         }
         temp->next=node;
     }
}
int queque:: remove()
{
    sq*temp;
    if(start==NULL)
    {
                   cout<<"The queque is empty"<<endl;
                   return 0;
    }
    else
    {
        temp=start;
        start=start->next;
        value = temp->no;
        delete(temp);
    }
}
void queque:: traverse()
{
     sq *temp;
     temp = start;
     while( temp->next!=NULL)
     {
            cout<<temp->no<<endl;
            temp=temp->next;
     }
     cout<<temp->no<<endl;
}
     
                
           
    
         
                    
     
     
     

       
