#include<iostream>
#include<pthread>
#include<stdio>
#include<stdlib>

static int cars_onbridge[2]={0,0};
const int MAX_CARS=3;
static int curr_direc=0;

void *onevehicle(int);
void arrivebridge(int);
void crossbridge(int);
void exitbridge(int);

void *onevehicle(int direc)
{
   arrivebridge(direc);
   crossbridge(direc);
   exitbridge(direc);
}

void arrivebridge(int direc)
{
while(1)
{
  if ((direc == curr_direc && cars_onbridge[direc] < MAX_CARS) ||
    (direc != curr_direc && cars_onbridge[!direc] == 0))
{
    cars_onbridge[direc]++;
    curr_direc = direc;
    return;
}
else
{
  printf("car is waiting in direction%d",direc);
}
}
}

void crossbridge(int direc)
{
  printf("car is crossing in the direction %d" , direc);
   return;
}

void exitbridge(int direc)
{
 cars_onbridge[direc]--;
 printf("car is exiting in the direction %d",direc);
 pthread_exit(NULL); 
}

int main()
{
  int cars[10];
  int index;
printf("enter the car sequence \n");
for(int i=0;i<10;i++)
{
   scanf("%d",cars[i]);
}
index=0;
for(int j=0;j<10;j++)
{ 
   index++;
pthread_t *newthread[j]=new pthread_t;
if(!pthread_create(newthread[j],NULL,onevehicle,cars[index]))
   printf("Error in creating thread:\n");
}
pthread_exit(NULL);
system("pause");
return 0;
}



  
