#include<iostream>
using namespace std;
const int MAX=20;
template<class T>
class stack
{
    private:
        int top,rear;
        T* a;
    public :
        stack() 
        {
            top=rear=-1;
            a=new T[MAX];
        }
        void isEmpty()
        {
            if(top==-1)
            cout<<"The queue is empty"<<endl;
            else
            cout<<"The queue is not empty"<<endl;
        }    
        void Enqueue(const T& x)
        {
            if((rear+1)%MAX==top)
            {
                cout<<"Queue Overflow. Cannot add anymore data"<<endl;
                return;
            }
            else if(top==-1)
            {
                top=rear=0;
                a[rear]=x;   
            }
            else
            {
                rear=(rear+1)%MAX;
                a[rear]=x;            
            }    
        }    
        T Dequeue()
        {
            T value;
            if(top==-1)
            {
                cout<<"Queue Ounderflow. Cannot remove data item"<<endl;
                value=0;
            }
            else if(rear==top)
            {
                value=a[top];
                top=rear=-1;
            }
            else    
            value=a[top++];
            return value;
        }        
        void display()
        {
            cout<<"-";
            for(int i=top;i<MAX;i++)
            {
                cout<<a[i]<<"-";
            }
        }               
};  
/*int main()
{
    stack<double> S1;
    S1.push(2.235);
    S1.push(3.446);
    S1.push(7.2389);
    S1.display();
    cout<<endl;
    cout<<"The value popped is "<<S1.pop()<<endl;
    cout<<endl;
    S1.display();
    stack<string> S2;
    cout<<endl;
    cout<<endl;
    S2.push("sachin");
    S2.push("ankit");
    S2.display();
    system("pause");
    return 0;
}
*/    
