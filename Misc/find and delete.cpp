#include <iostream>
using namespace std;
void del(int a[],int n,int size)
{
     for(int i=size-1;i>=0;i--)
     {
             if(a[i]==n)
             {
                        for(int j=i;j>=0;j--)
                        {
                        a[j]=a[j-1];
                        }
                        a[0]=0;
                        continue;
             }
     }
}
int main()
{
int a[5],no,i=0;
cout<<"Enter 5 no.s for an array"<<endl;
do
{
             cin>>a[i];
             i++;
}while(i<5);
cout<<"Enter the no. to be deleted"<<endl;
cin>>no;
del(a,no,5);
for(int j=0;j<5;j++)
{
        cout<<a[j]<<endl;
}
system("pause");
return 0;
}        
