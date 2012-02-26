#include<iostream>
using namespace std;
const int MAX=20;
template<class T>
class stack
{
    private:
        int top;
        T* a;
    public :
        stack() 
        {
            top=-1;
            a=new T[MAX];
        }
        void isEmpty()
        {
            if(top==-1)
            cout<<"The stack is empty"<<endl;
            else
            cout<<"The stack is not empty"<<endl;
        }    
        void push(const T& x)
        {
            if(top==MAX-1)
            {
                cout<<"Stack Overflow"<<endl;
                return;
            }
            else    
            a[++top]=x;
        }    
        T pop()
        {
            if(top==-1)
            {
                cout<<"Stack Ounderflow"<<endl;
                return 0;
            }
            else
            return a[top--];
        }        
        void display()
        {
            cout<<"-";
            for(int i=0;i<=top;i++)
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
