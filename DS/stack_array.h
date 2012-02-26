#include<iostream>
#include<string>
using namespace std;
const int n=10;
template<class T>
class stack
{
    public:
    int top;
    T a[n];
    stack(){top=-1;}
    void push(T);
    void pop();
    void display();
};
template<class T>
void stack<T>::display()
{
    for(int i=0;i<=top;i++)
    {
       cout<<a[i]<<" ";
    }
    cout<<endl;
}
template<class T>
void stack<T>::push(T x)
{
    if(top==n)
    {
       cout<<"stack overflow\n";
    }
    else
    {
       top++;
       a[top]=x;
    }
}
template<class T>
void stack<T>::pop()
{
    if(top==-1)
    {
       cout<<"stack underflow\n";
    }
    else
    {
        cout<<a[top];
        top--;
    }
}

/*int main()
{
    stack<string> v;
    v.push("ankit");
    v.push("mohit");
    v.display();
    cin.ignore();
    cin.get();
    return 0;
}*/
