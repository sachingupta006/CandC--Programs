#include<iostream>
#include<pthread.h>
#include <semaphore.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//#include<string.h>
#define N 10
using namespace std;




sem_t mutex ;
sem_t empty;
sem_t full;


pthread_t producer;
pthread_t consumer;

void *consume(void* arg);
void *produce(void* arg);
void consume_item(int);
int produce_item();
int remove_item();
void insert_item(int);

int buffer[N];
int index=0;

int main()
{
    sem_init(&empty, 0 , N);
    sem_init(&full, 0 , 0);
    sem_init(&mutex , 0 , 1);
    
    pthread_create(&producer , NULL , produce , (void*)"producing");    
    pthread_create(&consumer, NULL , consume , (void*)"consuming");
    pthread_join(producer , NULL);
    pthread_join(consumer , NULL);
    
    return 0;
}


void *consume(void* arg)
{
    char * msg;
    msg = (char*)arg;
    cout<<msg<<endl;
    
        int item;
        while(1)
        {
           
            usleep(rand()%1000000);
            sem_wait(&full);
                sem_wait(&mutex);
                   index--;
                   item=remove_item();
                sem_post(&mutex);
            sem_post(&empty); 
            consume_item(item);
        }
}


void *produce(void* arg)
{
    char * msg;
    msg = (char*)arg;
    cout<<msg<<endl;
    int item;
    while(1)
    { 
        item =produce_item();
        usleep(rand()%1000000);
        sem_wait(&empty);
             sem_wait(&mutex);
                  insert_item(item);
                  index++;
             sem_post(&mutex);
        sem_post(&full);
    }
    
}             
            
void consume_item(int a)
{
    cout<<"item consumed is "<<a<<endl;
    return ;
}
    
    
int produce_item()
{
    
    int i=rand()%100;
    cout<<"item produced"<<"      "<<i<<endl;
    return i;
}
   
int remove_item()
{
    int i=buffer[index];
    return i;
}

void insert_item(int a)
{
    buffer[index]=a;
    return ;
}            
         
    
                

