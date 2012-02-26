#include<sys/types.h>
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<unistd.h>
#include<math.h>

using namespace std;

int main()
{

int n,count1=0,count2=0;
int f[100] , g[100];
cout<<"enter the no. n"<<endl;
cin>>n;


pid_t pid;


pid=fork();
//pid=fork();

if(pid<0)
{
  cout<<"sry!! error occured"<<endl;
  return 0 ;
}

else if(pid==0)
{
   //int f1=0;
   for(int i=1;i<=(sqrt(n)/2);i++)
    {  
      
       if(!(n%i))
      {   
          f[count1++]=i; 
       }
    }
	cout<<"Factors are in child"<<endl;
     for(int k=0;k<count1;k++)
  	{
  		cout<<f[k]<<endl;
  	}
	exit(0);	
}

else 
{
  
   wait(pid);
   cout<<"children complete"<<endl;  
   for(int j=((sqrt(n)/2)+1);j<sqrt(n);j++)
    {
       if(!(n%j))
       {   
          g[count2++]=j;
       }
    }


       
 

 cout<<"factors are in parent"<<endl;
 
 for(int k=0;k<count2;k++)
	{
  cout<<g[k]<<endl;
	}

exit(0);
}
}


