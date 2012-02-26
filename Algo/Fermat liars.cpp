#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
int modExp(int ,int,int);
int euclid(int,int);
int main()
{
     int i, x;
     cout<<endl<<"Enter the Carmichael number"<<endl;
     cin>>x;
     int coprime[1000];
     int j=0;
     
     for(i = 1; i<x;i++)
     {
           int t=euclid( x, i );
           if(t==1)
           coprime[j++]=i;
     }
     //cout<<"The numbers co-prime are"<<endl;
     for(int i=0;i<j;i++)
     {
             if(modExp(coprime[i],x-1,x)==1)
             cout<<"Fermat Liar: "<<coprime[i]<<endl;
     }
     system("pause");
     return 0;
}
 
int euclid(int a,int b)
{
   if(b==0)
        return a;
   else
        return euclid(b,a%b);
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

