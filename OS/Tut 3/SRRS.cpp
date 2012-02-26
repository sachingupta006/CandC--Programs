#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
struct process
{
       int p_id;
       int p_rt;
       int p_at;
       int p_tat;
       int p_wt;
       int p_priority;
       int temp;
       bool done,rQ;
};
void adjust(int *,int, int);
int main()
{
    int time=0,time_old=0;
    int x,y,q;
    cout<<"Enter the rate of build up of running process"<<endl;
    cin>>y;
    //cout<<"The value of y is"<<y<<endl;
    cout<<"Enter the rate of build up of waiting process"<<endl;
    cin>>x;
    cout<<"Enter the value of time quantum"<<endl;
    cin>>q;
    cout<<"Enter the number of process"<<endl;
    int n;
    cin>>n;
    struct process p_array[n];
    int readyQ[n];
    int waitQ[n];
    int a_time;
    int r_time;
    int r_no;
    int completed=0;
    int index1=0;
    int index2=0;
    int priority=0,flag=0;
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
            p_array[i].p_priority=0;
            p_array[i].p_wt=0;
    }
    int k=0;
    int index;
    cout<<endl<<endl<<endl<<endl<<"=====================Sequence of executing the process====================="<<endl<<endl<<endl;
    do
    {
	for(int i=0;i<n;i++)
            {
                    if(p_array[i].p_at<=time && p_array[i].rQ==0 && p_array[i].done==0)
                    {
                                                       readyQ[index1++]=i;
                                                       p_array[i].rQ=1;
                                                       cout<<"Process "<<p_array[i].p_id<<" entering ready queue"<<endl;
                    }                                   
            }
	//cout<<"The value of y is "<<y<<endl;
        //k=(k+1)%index1;
        if(index1==0)
        {
                         time=time+1;
                         continue;
        }
        cout<<"Ready Queue"<<endl;
        for(int i=0;i<index1;i++)
        {
                    cout<<"Process: "<<readyQ[i]+1<<endl;
        }
        cout<<endl;
        //cout<<"The number of elements in ready queue are "<<index1<<endl;
        //cout<<"The value of k is "<<k<<endl;
        index=readyQ[k];
	if(p_array[index].p_priority>=priority || completed<n-1)
	{
		cout<<"Processing job: "<<p_array[index].p_id<<" and priority: "<<p_array[index].p_priority<<endl;
		cout<<"The system priority is "<<priority<<endl;		
		if(p_array[index].p_rt<q)
            	{
                                     time_old=time;
				                     p_array[index].p_wt+=time-p_array[index].temp;
                                     cout<<"Time: "<<time<<"      Process: "<<p_array[index].p_id;
                                     time+=p_array[index].p_rt;
                                     cout<<"    Finished: "<<time<<endl;
                                     p_array[index].p_rt=0;
                                     adjust(readyQ,k,index1);
                                     completed++;
                                     index1--;
                                     //cout<<"The number of elements in ready queue now are "<<index1<<endl;
                                     p_array[index].p_tat=time;                                     
                                     cout<<endl<<"Process: "<<p_array[index].p_id<<" is exiting"<<endl<<endl;
                                     p_array[index].done=1;
                                     flag=1;
                                     //cout<<"The total time waited by the process is "<<p_array[index].p_wt<<endl;
            	}
            	else
            	{
                	time_old=time;
		         	p_array[index].p_wt+=time-p_array[index].temp;
                	cout<<"Time: "<<time<<"      Process: "<<p_array[index].p_id<<endl;
                	time+=q;
                	p_array[index].temp=time;
                	p_array[index].p_rt-=q;
                	//cout<<"Time: "<<time<<"      Process: "<<p_array[index].p_id<<endl;
            	}
	} 
	else
	{
	    cout<<"Process: "<<p_array[index].p_id<<" could not be processed due to lower priority"<<endl;
	}    
	for(int i=0;i<index1;i++)
        {
                    p_array[readyQ[i]].p_priority+=(x*(time-time_old));
        }        
	p_array[index].p_priority-=(x*(time-time_old));
	p_array[index].p_priority+=(y*(time-time_old));
        priority=p_array[index].p_priority;
        if(flag==1)
        {
                       if(k==index1)
                       {
                           flag=0;
                           k=0;
                       }    
                       else
                       flag=0;
        }
        else
	//cout<<"Could not Process job: "<<p_array[index].p_id<<" with priority: "<<p_array[index].p_priority<<" as system priority is "<<priority<<endl;
        k=(k+1)%index1;
        //cout<<"The value of priority is "<<priority<<endl<<endl;
        //system("pause");
        cout<<endl;
            
    }while(completed<n); 
 
    float total_wt=0.0;
    float total_tat=0.0;

    for(int i=0;i<n;i++)
    {
              total_wt+=(float)p_array[i].p_wt;
              total_tat+=(float)p_array[i].p_tat;
    }
    total_wt/=n;
    total_tat/=n;    
    cout<<endl<<"The average turn around time "<<total_tat<<endl;
    cout<<"The average wait time "<<total_wt<<endl;
    system("pause");
    return 0;
}
void adjust (int *array,int start,int end)
{
     if(start==(end-1))
     return;
     for(int i=start;i<end-1;i++)
     {
             array[i]=array[i+1];
     }
}
 

















