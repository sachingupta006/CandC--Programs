#include<iostream>
using namespace std;
int main()
{
    cout<<"Enter the number of jobs"<<endl;
    int j;
    cin>>j;
    cout<<"Enter the number of processors"<<endl;
    int m;
    cin>>m;
    int job[j][j];
    int completed=0;
    int done[j];
    for(int i=0;i<j;i++)
    {
            done[i]=0;
            cout<<"Enter the dependancies of the "<<i+1<<" job and enter 0 at the end"<<endl;
            int k;
            for(k=0;k<j;k++)
            {
                    int x;
                    cin>>x;
                    if(x==0)
                    break;
                    else
                    job[i][k]=x;
            }
            job[i][k]=0;
    } 
    int level=0;       
    int mc;
    while(completed!=j)
    {
         cout<<"Level "<<++level<<endl<<endl; 
         mc=0;
         //system("pause");
         for(int i=0;i<j;i++)
         {
                 bool find=true;
                 int l=0;
                 if(done[i]==0)
                 {
                               //cout<<"Checking for job "<<i+1<<endl;
                               while(job[i][l]!=0)
                               {
                                    if(done[job[i][l]-1]==1)
                                    find=true;
                                    else
                                    find=false;
                                    l++;
                               }
                               if(find==true)
                               {
                                             cout<<"Job: "<<i+1<<" "<<"Machine: "<<++mc<<"     ";
                                             done[i]=2;
                                             completed++;
                               }
                               if(mc==m)
                               {
                                        cout<<endl<<"No more processes can be carried out in parallel"<<endl;
                                        break;
                               }
                 }
         }
         cout<<endl<<"List of completed jobs"<<endl;
         for(int i=0;i<j;i++)
         {
                 if(done[i]==1)
                 cout<<i+1<<endl;
                 if(done[i]==2)
                 {
                               done[i]=1;
                               cout<<i+1<<endl;
                 }
         }
         if(completed==j)
         {
                         cout<<endl<<"All the jobs completed"<<endl;
         }
         else
         {
             cout<<endl<<"List of uncompleted jobs"<<endl;
             for(int i=0;i<j;i++)
             {
                 if(done[i]!=1)
                 cout<<i+1<<endl;
             }
             cout<<endl<<endl;
         }
    }                         
    system("pause");
    return 0;
}
