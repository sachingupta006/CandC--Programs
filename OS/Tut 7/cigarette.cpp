#include<iostream>
#include<pthread.h>
#include <semaphore.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 3
using namespace std;

sem_t locktable;
sem_t locksmoke[N];

int turn[N];

pthread_t smokerPaper;
pthread_t smokerMatch;
pthread_t smokerTobacco;
pthread_t arbiter1;

void *smoker_paper(void* arg);
void *smoker_match(void* arg);
void *smoker_tobacco(void* arg);
void *arbiter(void* arg);

void smoke();


int main()
{
    srand((unsigned) time(NULL));
    sem_init(&locktable , 0 , 1);
    for(int i=0;i<N;i++)
    {
        sem_init(&locksmoke[i], 0 , 1);
    }    
    
    
    pthread_create(&smokerPaper, NULL , smoker_paper, (void*)"smoker-paper");
    pthread_create(&smokerMatch, NULL , smoker_match, (void*)"smoker-match");
    pthread_create(&smokerTobacco, NULL , smoker_tobacco, (void*)"smoker-tobacco");
    pthread_create(&arbiter1, NULL , arbiter, (void*)"arbiter");
   
    pthread_join(smokerPaper, NULL);
    pthread_join(smokerMatch, NULL);
    pthread_join(smokerTobacco, NULL);

    
    
    return 0;
}    

void *smoker_paper(void* arg)
{
    char* msg;
    msg=(char*)arg;
    cout<<msg<<endl;
    while(1)
    {
        while(turn[0]==0);
        sem_post(&locktable);
        sem_wait(&locksmoke[0]);
        cout<<"smoker paper wala"<<endl;
        
        smoke();
        turn[0]=0;
        sem_post(&locksmoke[0]);
    }
}

void *smoker_match(void* arg)
{
    char* msg;
    msg=(char*)arg;
    cout<<msg<<endl;
    while(1)
    {
        while(turn[1]==0);
        sem_post(&locktable);
        sem_wait(&locksmoke[1]);
        cout<<"smoker match wala"<<endl;
        smoke();
        turn[1]=0;
        sem_post(&locksmoke[1]);
    }
}

void *smoker_tobacco(void* arg)
{
    char* msg;
    msg=(char*)arg;
    cout<<msg<<endl;
    while(1)
    {
        while(turn[2]==0);
          sem_post(&locktable);
          sem_wait(&locksmoke[2]);
          cout<<"smoker tobacco wala"<<endl;
          smoke();
         turn[2]=0;
        sem_post(&locksmoke[2]);
    }
} 


void *arbiter(void* arg)
{
    char* msg;
    msg =(char*)arg;
    cout<<arg<<endl;
    
    while(1)
       {
           sem_wait(&locktable);
           int r1=rand()%3;
cout<<endl;
           cout<<"r1"<<"--"<<r1<<endl;
           int r2=(r1+1)%3;
cout<<"r2"<<"--"<<r2<<endl;
           turn[r1]=0;
           turn[r2]=0;
           int r3=(r2+1)%3;
cout<<"r3"<<"--"<<r3<<endl;
cout<<endl;
           sem_wait(&locksmoke[r3]);
           turn[r3]=1;
           sem_post(&locksmoke[r3]);
       }
       
}       


void smoke()
{
    
    usleep(100000);
    return;
}    

                          
