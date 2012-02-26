#include<iostream>
#include<math.h>
using namespace std;
int modExp(int x,int y, int N);
int main()
{
    int x,y,N;
    cout<<"Enter the value of x"<<endl;
    cin>>x;    
    cout<<"Enter the value of y"<<endl;
    cin>>y;
    cout<<"Enter the value of N"<<endl;
    cin>>N;
    int z =modExp(x,y,N);
    cout<<"The remainder is "<<z<<endl;
    system("pause");
    return 0;
}
int modExp(int x,int y, int N)
{
   float z=(float)y;
   int count=0;
   while(z>=1)
   {
              count++;
              z=z/2;
   }
   count=count-2;
   int temp=x%N;
   for(int i=0;i<count;i++)
   {
           temp=(temp*temp)%N;
   }
   int t=y-(int)pow(2,count+1);
   for(int i=0;i<t;i++)
   {
           temp=(temp*x)%N;
   }
   return temp;
   
}
