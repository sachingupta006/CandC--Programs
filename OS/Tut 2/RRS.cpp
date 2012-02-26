#include<iostream>
using namespace std;
void rotate(int *,int,int);
int main()
{
    int n;
    cout<<"Enter the number of teams"<<endl;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
            a[i]=i+1;
    }
    for(int i=0;i<n-1;i++)
    {
            cout<<endl<<"Day "<<2*i+1<<":"<<endl;
            cout<<" Team "<<a[0]<<" VS "<<"Team "<<a[5]<<endl;
            cout<<" Team "<<a[1]<<" VS "<<"Team "<<a[4]<<endl;
            cout<<" Team "<<a[2]<<" VS "<<"Team "<<a[3]<<endl;            
            rotate(a,1,5);
    }
    system("pause");
    return 0;
}
void rotate(int *a,int start,int end)
{
     int len=end-start+1;
     int rep[len];
     rep[0]=a[end];
     for(int i=1;i<len;i++)
     {
             rep[i]=a[i];

     }
     for(int i=0;i<len;i++)
     {
             a[start++]=rep[i];
     }
};
