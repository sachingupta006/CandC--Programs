#include<iostream>
using namespace std;
const int MAX=20;
template<class T>
struct node
{
    T data;
    node<T> *next;
};
template<class T>
class stack
{
    private:
        node<T> *head;
    public:
        stack()
        {
            head=NULL;
        }
        void push(T x)
        {
            node<T> *temp=new node<T>;
            temp->data=x;
            temp->next=NULL;
            temp->next=head;
            head=temp;
        }    
        T pop()
        {
            node<T> *temp;
            T value;
            temp=head;
            if(temp==NULL)
            {
                cout<<"Stack Underflow"<<endl;
                return 0;
            }
            else
            {
                head=head->next;
                value=temp->data;
                delete temp;
                return value;
            }
        }  
        T peep()
        {
            return head->data;
        }                     
        void display()
        {
            node<T> *temp;
            if(head==NULL)
            {
                cout<<"The stack is already empty"<<endl;
                return;
            }    
            //cout<<"-";
            T array[20];
            int i=0;
            for(temp=head;temp!=NULL;temp=temp->next)
            {
                array[i]=temp->data;
                i++;
            }
            for(int l=i-1;l!=0;l--)
              cout<<array[l];
            //cout<<endl;
        }
        bool isEmpty()
        {
             if(head == NULL)
             return true;
             else
             return false;
        }     
};
/*int main()
{
    stack<double> S;
    int choice;
    double item;
    do
    {
        cout<<"Enter your choice"<<endl;
        cout<<"1: PUSH the data"<<endl;
        cout<<"2: POP the data"<<endl;
        cout<<"3: Display"<<endl;
        cout<<"4: Exit"<<endl;
        cin>>choice;
        switch(choice)
        {
                      case 1: S.push();
                              break;
                      case 2: item=S.pop();
                              if(item!=0)
                              cout<<"The data popped is "<<item<<endl;
                              break;
                      case 3: S.display();
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
*/
                
    
