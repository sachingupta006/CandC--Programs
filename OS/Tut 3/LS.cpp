#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
using namespace std;
struct process
{
       int p_id;
       int p_rt;
       int p_at;
       int p_tat;
       int l_no;
       int p_wt;
       //int temp;
       bool done;
};
int main()
{
    int time_taken=0;
    srand (time(NULL));
    cout<<"Enter the number of process"<<endl;
    int n;
    cin>>n;
    struct process p_array[n];
    int lottery[n];
    int a_time;
    int r_time;
    int r_no;
    int completed=0;
    int index=0;
    cout<<"Enter the arrival time of the "<<n<<" processes"<<endl;
    for(int i=0;i<n;i++)
    {
            cin>>a_time;
            p_array[i].p_id=i+1;
            p_array[i].p_at=a_time;
    }
    cout<<"Enter the request time of the "<<n<<" processes"<<endl;
    for(int i=0;i<n;i++)
    {        
            cin>>r_time;
            p_array[i].p_rt=r_time;
            r_no=rand()%100;
            p_array[i].l_no=r_no;
            lottery[i]=r_no;
            p_array[i].done=0;
    }
    cout<<endl<<endl<<endl<<endl<<"=====================Sequence of executing the process====================="<<endl<<endl<<endl;
    do
    {
            for (int i=0; i<n-1; i++) 
            {
                int r = i + (rand() % (n)); // Random remaining position.
                int temp = lottery[i]; 
                lottery[i] = lottery[r]; 
                lottery[r] = temp;
            }
            int k;
            for(k=0;k<n;k++)
            {
                if(lottery[index]==p_array[k].l_no)
                break;
            }
            if(p_array[k].done==0 && p_array[k].p_at<=time_taken)
            {
                                       completed++;
                                       p_array[k].done=1;
                                       //p_array[k].temp=time;
                                       p_array[k].p_wt=time_taken-p_array[k].p_at;
                                       cout<<"Time: "<<time_taken<<"      Process: "<<p_array[k].p_id<<"Time Taken:       "<<p_array[k].p_rt<<endl;
                                       time_taken+=p_array[k].p_rt;
                                       //cout<<p_array[k].pid"<<        "<<endl;
                                       p_array[k].p_tat=time_taken-p_array[k].p_at;
            } 
            
            index=(index+1)%n;
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
