#include<iostream>
using namespace std;
int main()
{
    int a[20],i;
    cout<<"How many no. you want to add"<<endl;
    int l;
    cin>>l;
    cout<<"Enter the no.s you want to add"<<endl;
    for(i=0;i<l;i++)
    {
            cin>>a[i];
    }
     cout<<"Enter the no to be entered"<<endl;
     int no;
     cin>>no;
     cout<<"enter the pos where you wan to enter the no."<<endl;
     int pos;
     cin>>pos;
     for(i=l;i>pos;i--)
     {
                     a[i]=a[i-1];
     }
     a[i]=no;
     l=l+1;  
     cout<<"New array: "<<endl;
     for(i=0;i<l;i++)
     {
     cout<<a[i]<<endl;
     }            
     system("pause");
     return 0;
     }
     
            
    
