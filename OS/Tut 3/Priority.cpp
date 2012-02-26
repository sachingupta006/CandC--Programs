#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#define R 5
using namespace std;
struct process
{
       int p_id;
       int p_rt;
       int p_at;
       int p_tat;
       int p_wt;
       int p_priority;
       int p_rs[R];
       int temp;
       bool done,rQ;
};
void adjust(int *,int, int);
int main()
{
    int time=0;
    int res[R];
    for(int i=0;i<R;i++)
    {
            res[i]=0;
    }
    int q;
    cout<<"Enter the value of time quantum"<<endl;
    cin>>q;
    cout<<"Enter the number of process"<<endl;
    int n;
    cin>>n;
    struct process p_array[n];
    int readyQ[n];
    int a_time;
    int r_time,priority;
    int completed=0;
    cout<<"Enter the arrival time of the "<<n<<" processes"<<endl;
    for(int i=0;i<n;i++)
    {
            cin>>a_time;
            p_array[i].p_id=i+1;
            p_array[i].p_at=a_time;
            p_array[i].temp=a_time;
    }
     cout<<"Enter the request time of the "<<n<<" processes"<<endl;
    for(int i=0;i<n;i++)
    {        
            cin>>r_time;
            p_array[i].p_rt=r_time;
            p_array[i].done=0;
            p_array[i].rQ=0;
            //p_array[i].wQ=0;
            p_array[i].temp=0;
            //p_array[i].p_priority=0;
            p_array[i].p_wt=0;
    }
    cout<<"Enter the priority of the "<<n<<" processes"<<endl;
    for(int i=0;i<n;i++)
    {
          cin>>priority;
          p_array[i].p_priority=priority;
    }
    cout<<"Enter the resource requirement of the "<<n<<" processes. Enter 0 at the end"<<endl;
    for(int i=0;i<n;i++)
    {
            int k,x;
            for(k=0;k<R;k++)
            {
                            cin>>x;
                            if(x==0)
                            break;
                            else
                            p_array[i].p_rs[k]=x;
            }
            p_array[i].p_rs[k]=0;
    }                        
    cout<<endl<<endl<<endl<<endl<<"=====================Sequence of executing the process====================="<<endl<<endl<<endl;
    do
    {
         
            
