#include<iostream>
#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
using namespace std;


static int cars_onbridge[2]={0,0};
pthread_mutex_t mutex1;
pthread_cond_t condition1;

const int MAX_CARS=3;
static int curr_direc=0;

void ArriveBridge(int direc,int carNo)
{
   printf("Car %d arriving at the bridge in the direction %d \n",carNo,direc);
   while(1)
   {
           pthread_mutex_lock(&mutex1);
           if((direc==curr_direc && cars_onbridge[direc]<MAX_CARS)||(direc!=curr_direc && cars_onbridge[!direc]==0))
           {

                                 cars_onbridge[direc]++;
                                 curr_direc=direc;
                                 pthread_mutex_unlock(&mutex1);
                                 return;
           }
           else
           {
                                 printf("\t Car %d waiting for bridge in the direction %d \n",carNo,direc);
                                 pthread_cond_wait(&condition1,&mutex1);
                                 // printf("ArriveBridge wake up i.e got the bridge in the direction %d \n ",direc);
                                 pthread_mutex_unlock(&mutex1);
           }
    }
}

void CrossBridge(int direc,int carNo)
{
     //printf("\t\tcrossing bridge in the direction %d \n",direc);
     usleep(100000);
}

void ExitBridge(int direc,int carNo)
{
     pthread_mutex_lock(&mutex1);
     cars_onbridge[direc]--;
     printf("Car %d exiting bridge in the direction %d \n",carNo,direc);
     pthread_cond_broadcast(&condition1);
     pthread_mutex_unlock(&mutex1);
}
void * OneVehicle(void * data)
{  
     int direc;
     int carNo;
     int *threadData=(int*)data;
     direc=threadData[0];
     carNo=threadData[1];
     ArriveBridge(direc,carNo);
     CrossBridge(direc,carNo);
     ExitBridge(direc,carNo);
     return 0;

}

int main()
{
    pthread_mutex_init(&mutex1,NULL);
    pthread_cond_init(&condition1,NULL);
    cout<<"Enter the sequence of cars on the bridge"<<endl;
    while(1)
    {
            srand((unsigned) time(NULL));
            char seq[100];
            cin>>seq;
		    int size = strlen(seq);
		    int i = 0;
            for( ; i < size ; i++)
		    {
			     pthread_t pth;
                 int a[2];
                 a[0] = seq[i] - 48;
                 a[1] =i+1;
                 pthread_create(&pth, NULL, OneVehicle,(void*) a);
			     usleep(rand()%1000);
              }
     }
	 return 0;
}





  

