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
    //int count=0;
    int f[100] , g[100];
    cout<<"Enter the number"<<endl;
    cin>>n;
    int limit=(int)sqrt(n)/2;
    //int factors[100];
    pid_t pid;         
    pid=fork();
    if(pid<0)
    {
             cout<<"Error!! Process could not be forked"<<endl;
             return 0 ;
    }
    else if(pid==0)
    {
         for(int i=1;i<=limit;i++)
         {  
                 if(!(n%i))
                 {             
                               f[count1++]=i;
                               //f[count++]=i; 
                 }
         }
	     cout<<"Factors returned by child"<<endl;
         for(int k=0;k<count;k++)
  	     {
  		         cout<<f[k]<<endl;
        }                    
	    exit(0);	
     }
     else 
     {
          wait(pid);
          cout<<"Child Process complete"<<endl;  
          int end=(int)sqrt(n);
          //int count=t;
          for(int j=(limit+1);j<end;j++)
          {     
                if(!(n%j))
                {   
                    g[count2++]=j;
                    //f[count++]=j;
                }
          }
          cout<<"Factors returned by parent"<<endl;
          for(int k=0;k<count2;k++)
	      {
                  cout<<g[k]<<endl;
          }
          /*for(int k=t;k<count;k++)
          {
                  cout<<f[k]<<endl;
          }*/
          exit(0);
       }
}


