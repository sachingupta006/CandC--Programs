#include<iostream>
#include <stdlib.h>
#include<time.h>
#include<math.h>
#define size 200
#define len 8

int FCFS(int*);
int SSTF(int*);
int SCAN(int*);
int CSCAN(int*);
int LOOK(int*);
int CLOOK(int*);

using namespace std;

int main()
{
    srand((unsigned) time(NULL));
    //int cylinder[len];
    //int test[len];
    int cylinder[len]={26,37,100,14,88,33,99,12};
    int test[len]={26,37,100,14,88,33,99,12};    
    cout<<"FCFS: "<<FCFS(cylinder)<<endl;
    cout<<"SSTF: "<<SSTF(test)<<endl;
    cout<<"SCAN: "<<SCAN(cylinder)<<endl;
    cout<<"CSCAN: "<<CSCAN(cylinder)<<endl;
    cout<<"LOOK: "<<LOOK(cylinder)<<endl;
    cout<<"CLOOK: "<<CLOOK(cylinder)<<endl;
    system("pause");
    return 0;
}
int FCFS(int* list)    
{
    int result=0;
    for(int i=0;i<len-1;i++)
    {
            result+=fabs(list[i+1]-list[i]);
    }
    return result;
}

int SSTF(int* list)
{
    //int head=list[0];
    int current=0;
    int min_val;
    int min;
    int result=0;
    for(int i=1;i<len;i++)
    {
            min_val=size+100;
            for(int j=0;j<len;j++)
            {
                    if(j==current || list[j] == -1)
                    continue;
                    if(min_val > fabs(list[current]-list[j]))
                    {
                               min_val=fabs(list[current]-list[j]);
                               min=j;
                    }
            }
     result+=fabs(list[current]-list[min]);
     list[current]=-1;
     current=min;
     }
     return result;
}
int SCAN(int* list)  
{
    int head=list[0];
    int temp[len-1];
    for(int i=0;i<len-1;i++)
    {
            temp[i]=list[i+1];
    }
    for(int i=0;i<len-1;i++)
    {
            for(int j=i+1;j<len-1;j++)
            {
                    if(temp[j]<temp[i])
                    {
                                       int t=temp[j];
                                       temp[j]=temp[i];
                                       temp[i]=t;
                    }
            }
    }
    int i=0;
    while(head>temp[i])
    {
                       i++;
    }
    int t=i-1;
    int result=0;
    while(t>=0)
    {
               result+=(head-temp[t]);
               head=temp[t];
               t--;
    }
    result+=head;
    head=0;
    while(i<len-1)
    {
               result+=(temp[i]-head);
               head=temp[i];
               i++;
    }
    return result;
}
int CSCAN (int* list)
{
    int head=list[0];
    int temp[len-1];
    for(int i=0;i<len-1;i++)
    {
            temp[i]=list[i+1];
    }
    for(int i=0;i<len-1;i++)
    {
            for(int j=i+1;j<len-1;j++)
            {
                    if(temp[j]<temp[i])
                    {
                                       int t=temp[j];
                                       temp[j]=temp[i];
                                       temp[i]=t;
                    }
            }
    }
    int i=0;
    while(head>temp[i])
    {
                       i++;
    }
    int result=0;
    int t=i-1;
    while(i<len-1)
    {
               result+=(temp[i]-head);
               head=temp[i];
               i++;
    }
    result+=(size-head);
    result+=size;
    head=0;
    for(int j=0;j<=t;j++)
    {
            result+=(temp[j]-head);
            head=temp[j];
    }
    return result;
}
int LOOK(int* list)  
{
    int head=list[0];
    int temp[len-1];
    for(int i=0;i<len-1;i++)
    {
            temp[i]=list[i+1];
    }
    for(int i=0;i<len-1;i++)
    {
            for(int j=i+1;j<len-1;j++)
            {
                    if(temp[j]<temp[i])
                    {
                                       int t=temp[j];
                                       temp[j]=temp[i];
                                       temp[i]=t;
                    }
            }
    }
    int i=0;
    while(head>temp[i])
    {
                       i++;
    }
    int t=i-1;
    int result=0;
    while(t>=0)
    {
               result+=(head-temp[t]);
               head=temp[t];
               t--;
    }
    while(i<len-1)
    {
               result+=(temp[i]-head);
               head=temp[i];
               i++;
    }
    return result;
}             
int CLOOK (int* list)
{
    int head=list[0];
    int temp[len-1];
    for(int i=0;i<len-1;i++)
    {
            temp[i]=list[i+1];
    }
    for(int i=0;i<len-1;i++)
    {
            for(int j=i+1;j<len-1;j++)
            {
                    if(temp[j]<temp[i])
                    {
                                       int t=temp[j];
                                       temp[j]=temp[i];
                                       temp[i]=t;
                    }
            }
    }
    int i=0;
    while(head>temp[i])
    {
                       i++;
    }
    int result=0;
    int t=i-1;
    while(i<len-1)
    {
               result+=(temp[i]-head);
               head=temp[i];
               i++;
    }
    result+=(size-temp[0]);
    head=temp[0];
    for(int j=1;j<=t;j++)
    {
            result+=(temp[j]-head);
            head=temp[j];
    }
    return result;
}                                 
                    
    
    

            
