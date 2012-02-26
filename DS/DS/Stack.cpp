# include<iostream>
# include<process.h>
using namespace std;
struct Stack
{
       int no;
        struct Stack *next;
}*start= NULL;
typedef struct Stack st;
class stack
{
      private: 
               int value;
      public:
             void push();
             int pop();
             void transverse();
};
int main()
{
    stack S;
    int choice,item;
    do
    {
        cout<<"Enter your choice"<<endl;
        cout<<"1: PUSH a number"<<endl;
        cout<<"2: POP a number"<<endl;
        cout<<"3: Tansverse"<<endl;
        cout<<"4: Exit"<<endl;
        cin>>choice;
        switch(choice)
        {
                      case 1: S.push();
                              break;
                      case 2: item=S.pop();
                              if(item!=0)
                              cout<<"The number popped is "<<item<<endl;
                              break;
                      case 3: S.transverse();
                              break;
                      case 4: cout<<"You are exiting now"<<endl;
                              break;
                      default : cout<<"Invalid choice"<<endl;
                                break;
        };
    }while(choice!=4);
    system("pause");
    return 0;
}
void stack:: push()
{
     st *node;
     node= new(st);
     cout<<"Enter the no. to be inseretd"<<endl;
     cin>>node->no;
     node->next=start;
     start = node;
}
int stack :: pop()
{
    st *temp;
    temp = start;
    if(start==NULL)
    {
                   cout<<"The stack is already empty"<<endl;
                   return 0;     
    }
    else
    {
        start =start->next;
        value=temp->no;
        delete(temp);
    }
    return value;
}
void stack :: transverse()
{
     st *temp;
     temp = start;
     while(temp-> next !=NULL)
     {
                  cout<<endl<<"Number is "<<temp->no;
                  temp=temp->next;
     }
     cout<<endl<<"Number is"<<temp->no;
}

        
    
     
                  
     
     
    
    
                   
     
             
             
       
