#include<iostream>
#include<string.h>
using namespace std;
template<class T>
struct node
{
    T data;
    node<T> *next;
};
template<class T>
class Queue
{
    private:
        node<T> *head,*end;
    public:
        Queue()
        {
            head=NULL;
            end=NULL;
        }
        void Enqueue(T x)
        {
            node<T> *temp=new node<T>;
            temp->data=x;
            temp->next=NULL;
            if(head==NULL)
            {
                head=temp;
                end=temp;
            }    
            else
            {
                end->next=temp;
                end=temp;
            }
            cout<<"Data added"<<endl;
        }    
        T Dequeue()
        {
            node<T> *temp;
            T value;
            temp=head;
            if(temp==NULL)
            {
                cout<<"Queue is already empty"<<endl;
                value= 0;
            }
            else
            {
                head=head->next;
                value=temp->data;
                delete temp;
            }
            cout<<"Data Removed"<<endl;
            return value;
        }                   
        void display()
        {
            node<T> *temp;
            if(head==NULL)
            {
                cout<<"The queue is already empty"<<endl;
            }    
            cout<<"-";
            for(temp=head;temp!=NULL;temp=temp->next)
            {
                cout<<temp->data<<"-";
            }
            cout<<endl;
        }
        bool isEmpty()
        {
             if(head==NULL)
             return true;
             else
             return false;
        }     
};
/*int main()
{
    Queue<float> Q;
    int choice;
    float item;
    do
    {
        cout<<endl;
        cout<<"Enter your choice"<<endl;
        cout<<"1: Enqueue data"<<endl;
        cout<<"2: Dequeue data"<<endl;
        cout<<"3: Display"<<endl;
        cout<<"4: Exit"<<endl;
        cin>>choice;
        switch(choice)
        {
                      case 1: Q.Enqueue();
                              break;
                      case 2: item=Q.Dequeue();
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
}*/
