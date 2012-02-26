
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void* OneVehicle(void* );
void ArriveBridge(int ,int );
void CrossBridge(int ,int );
void ExitBridge(int ,int );

sem_t numAllowedtoCrossRight;
sem_t numAllowedtoCrossLeft;
sem_t lockBridge;
sem_t lock;

int main()
{
	 printf("\n\033[22;32m Multi-threaded Program !\n\n");
	 printf("The Program will create random arbitrary delay\n "
			"(from 0 to 1 second) in between arrival of each car.\n");
	 printf("\nEnter the sequence of car directions:");

	 sem_init(&numAllowedtoCrossRight, 0, 3);	/* control maximum cars on bridge */
	 sem_init(&numAllowedtoCrossLeft, 0, 3);	/* control maximum cars on bridge */
	 sem_init(&lockBridge, 0, 1);               /* bridge lock */
	 sem_init(&lock, 0, 1);						/* critical section lock */

	 while(1)   /* for continuous input (not busy-waiting) */
	 {
		 srand((unsigned) time(NULL));

		 char seq[100];
		 scanf("%s",seq);
		 int size = strlen(seq);
		 int i = 0;

		 for( ; i < size ; i++)
		 {
			 pthread_t pth;
			 int a[2] = { 0 };
			 a[0] = seq[i] - 48;
			 a[1] = i+1;
			 pthread_create(&pth, NULL, OneVehicle, a);
			 usleep(rand()%1000);
		 }
	 }
	 return 0;
}

void* OneVehicle(void* arg)
{
	int *info;
	info = (int*)arg;
	int direc = info[0];
	int id = info[1];
	printf("id: %d",id);
	ArriveBridge(direc, id);
	CrossBridge(direc, id);
	ExitBridge(direc, id);
	return;
}

void ArriveBridge(int direc, int id)
{
	/*  Lock the critical region i.e. bridge because if two
	 *  cars arrive on the bridge at the same time, there
	 *  will be a deadlock with neither willing to go back !
	 *  This also ensures that the car which arrives first get
	 *  to cross first, which avoids starvation.
	 */
	printf("Car: %d arrived on bridge in direction: %d.\n",id,direc);
	sem_wait(&lockBridge);   /* avoids head-on collision */

	if(direc == 1 )
	{
		while(1)     /* busy-waiting */
		{
			int value;
			sem_getvalue(&numAllowedtoCrossLeft, &value);
			if(value == 3)
				break;
			else continue;
		}
		/* pass through above code after all cars in opposite direction(left) exit. */

		sem_wait(&numAllowedtoCrossRight);  /* avoid bridge collapse */
	}
	else if(direc == 0)
	{
		while(1)    /* busy-waiting */
		{
			int value;
			sem_getvalue(&numAllowedtoCrossRight, &value);
			if(value == 3)
				break;
			else continue;
		}
		/* pass through above code after all cars in opposite direction(right) exit. */

		sem_wait(&numAllowedtoCrossLeft); /* avoid bridge collapse */
	}

	sem_post(&lockBridge);

	return;
}

void CrossBridge(int direc,int id)
{
	int value1;
	int value2;
	sem_getvalue(&numAllowedtoCrossRight, &value1);
	sem_getvalue(&numAllowedtoCrossLeft, &value2);

	/*
	 *  Don't try to cross the bridge until
	 *  all the car's in opposite direction exits.
	 */

	if(direc == 0 && value1 == 3)
	{
		sem_wait(&lock);
		sem_post(&lock);
	}
	if(direc == 1 && value2 == 3)
	{
		sem_wait(&lock);
		sem_post(&lock);
	}

	printf("Car: %d crossing bridge in direction: %d.\n",id,direc);
	usleep(1000000);     /* arbitrary time taken to cross the bridge */
	return;
}

void ExitBridge(int direc, int id)
{
	/* Only one car can exit the bridge at any instant. */

	sem_wait(&lock);
	if(direc == 1)
		sem_post(&numAllowedtoCrossRight);
	else if(direc == 0)
		sem_post(&numAllowedtoCrossLeft);

	printf("Car: %d exiting bridge in direction: %d.\n",id,direc);
	sem_post(&lock);

	return;
}
