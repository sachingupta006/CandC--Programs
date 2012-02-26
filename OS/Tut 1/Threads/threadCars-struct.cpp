#include<iostream>
#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#define NUM_THREADS 20
using namespace std;

void * OneVehicle(void * );
void ArriveBridge(char,int);
void CrossBridge(char,int);
void ExitBridge(char,int );

struct thread_data
{
       int carNo;
       char direction;
};
struct thread_data data_array[NUM_THREADS];

static int cars_onbridge[2]={0,0};
pthread_mutex_t mutex;
pthread_cond_t cond;
pthread_t pth[20];

const int MAX_CARS=3;
static int curr_direc=0;

int main()
{
    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&cond,NULL);
    cout<<"Enter the Sequence of cars 1: Right 0: Left"<<endl;
    while(1)
    {
            srand((unsigned) time(NULL));
            char inp[100];
            cin>>inp;
		    int len = strlen(inp);
            for(int i=0;i<len;i++)
		    {
			    data_array[i].carNo = i;
                data_array[i].direction =inp[i];
		        pthread_create(&pth[i], NULL, OneVehicle,(void*) &data_array[i]);
		        usleep(rand()%1000);
	       }
    }
    return 0;
}

void * OneVehicle(void * thread_arg)
{  
     struct thread_data *my_data;
     my_data=(struct thread_data *) thread_arg;

     char direc=my_data->direction;
     int id=my_data->carNo;
     
     ArriveBridge(direc,id);
     CrossBridge(direc,id);
     ExitBridge(direc,id);
     return 0;
}

void ArriveBridge(char direc,int id)
{
     printf("Car no: %d has arrived at the bridge in the direction %c \n",id,direc); 
     while(1)
     {
             pthread_mutex_lock(&mutex);
             if((direc==curr_direc && cars_onbridge[direc]<MAX_CARS)||(direc!=curr_direc && cars_onbridge[!direc]==0))
             {
                                   cars_onbridge[direc]++;
                                   curr_direc=direc;
                                   pthread_mutex_unlock(&mutex);
                                   return;
             }
             else
             {
                                   printf("\tCar no: %d waiting for bridge in the direction %c \n",id,direc);
                                   pthread_cond_wait(&cond,&mutex);
                                   // printf("ArriveBridge wake up i.e got the bridge in the direction %d \n ",direc);
                                   pthread_mutex_unlock(&mutex);
             }
     }
}

void CrossBridge(char direc,int id)
{
     printf("\t\t Car no: %c crossing bridge in the direction %d \n",id,direc);
     usleep(100000);
}

void ExitBridge(char direc,int id)
{
     pthread_mutex_lock(&mutex);
     cars_onbridge[direc]--;
     printf("\t\t\tcars exiting bridge in the direction %c \n",direc);
     pthread_cond_broadcast(&cond);
     pthread_mutex_unlock(&mutex);
}


