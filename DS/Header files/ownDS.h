#include<iostream>
#include<string.h>
using namespace std;
template<class T>
struct node
{
    T data;
    node<T> *next;
    node<T> *prev;
};
template<class T>
class SQueue
{
    private:
        node<T> *head,*end;
    public:
        SQueue()
        {
            head=NULL;
            end=NULL;
        }
        void Enqueue(T x)
        {
            node<T> *temp=new node<T>;
            temp->data=x;
            temp->next=NULL;
            temp->prev=NULL;
            if(head==NULL)
            {
                head=temp;
                end=temp;
            }    
            else
            {
                end->next=temp;
                temp->prev=end;
                end=temp;
            }
            //cout<<"Data added"<<endl;
        }    
        T Deque()
        {
            node<T> *temp,*temp1;
            T value;
            temp=end;
            if(temp==NULL)
            {
                return 0;
            }
            else if(head==end)
            {
                 head=NULL;
                 end=NULL;
                 value=temp->data;
                 delete temp;
            }
            else      
            {
                //for(temp=head;temp->next!=NULL;temp1=temp,temp=temp->next);
                value=temp->data;
                temp1=temp->prev;
                end=temp1;
                delete temp;
            }
            //cout<<"Data Removed"<<endl;
            return value;
        }                   
        void display()
        {
            node<T> *temp;
            if(head==NULL)
            {
                //cout<<"The queue is already empty"<<endl;
                return;
            }    
            else
            {
                for(temp=head;temp!=end;temp=temp->next)
                {
                       cout<<temp->data<<"->";
                }
            cout<<temp->data;
            }
            cout<<endl;
        }
        int isEmpty()
        {
             if(head==NULL)
             return 1;
             else
             return 0;
        }     
};
/*
int main()
{
    SQueue<int> Q;
    int choice;
    int item;
    do
    {
        cout<<endl;
        cout<<"Enter your choice"<<endl;
        cout<<"1: Enqueue data"<<endl;
        cout<<"2: Deque data"<<endl;
        cout<<"3: Display"<<endl;
        cout<<"4: Exit"<<endl;
        cin>>choice;
        switch(choice)
        {
                      case 1: cout<<"enter the data"<<endl;
                              cin>>item;
                              Q.Enqueue(item);
                              break;
                      case 2: item=Q.Deque();
                              if(item!=0)
                              cout<<"The data removed is "<<item<<endl;
                              break;
                      case 3: Q.display();
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
*/
