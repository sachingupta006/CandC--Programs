#include<iostream>
#include<pthread.h>
#include <semaphore.h>
using namespace std;

#define FALSE 0
#define N 5

int turn[N];
int stage[N+1];


pthread_t process[N+1];
void Process(void* arg);
void enterRegion(int a);
void leaveRegion(int a);
void criticalRegion(int a);


int main()
{
    for(int i=1;i<=N;i++)
    {
       pthread_create(&process[i], NULL , Process, (void*)i);
    }    
    
  	for(int i=1;i<=N;i++)
     {
        pthread_join(process[i], NULL);
     }
        
        return 0;
        
}  


void Process(void* arg)
{
    int* index;
    index=(int*)arg;
    int j=*index;
    cout<<"process__"<<j<<endl;
    
    enterRegion(j);
    criticalRegion(j);
    leaveRegion(j);
    
}


void enterRegion(int a)
{
    int i,j;
    
        for(i=1;i<=N-1;i++)
        {
            stage[a]=i;
            turn[i]=a;
            for(j=1;j<=N;j++)
            {
                if(j==a)
                continue;
              while(stage[j]>=i && turn[i]==a);
            }
        }
}

void leaveRegion(int a)
{
    stage[a]=FALSE;
    cout<<"process__"<<a<<" is leaving"<<endl;
}


void criticalRegion(int a)
{
    cout<<"process__"<<a<<"is in it's critical region"<<endl;
    usleep(rand()%10000);
}                                             
         
