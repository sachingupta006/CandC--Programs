/*
 * water.c
 *
 *  Created on: 25-Jul-2010
 *      Author: vivek
 */

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

void *hReady(void *arg);
void *oReady(void *arg);
void *makeWater();

int hAtom;
int oAtom;
sem_t lock;
sem_t lockReturn;
sem_t lockH;
pthread_t h1, h2, o;

int main()
{
    printf("\033[22;32m Multithreaded Program !\n");

    while(1)      /* for continuous result (not a busy-waiting) */
    {
    	hAtom = 2;
    	oAtom = 1;
    	sem_init(&lock, 0, 1);      	/* lock the critical section */
    	sem_init(&lockReturn, 0, 0); 	/* lock for return of makeWater() */
    	sem_init(&lockH, 0 , 0);  		/* lock for testing H-atom == 2 */

    	pthread_create(&h1, NULL, hReady, "H atom 1");
    	pthread_create(&h2, NULL, hReady, "H atom 2");
    	pthread_create(&o, NULL, oReady, "Oxygen atom");

    	pthread_join(o, NULL);
    	pthread_join(h1, NULL);
    	pthread_join(h2, NULL);

    	/* deallocate the resources owned by the threads */
		pthread_detach(h1);
    	pthread_detach(h2);
    	pthread_detach(o);

    	/* destroy all the semaphores to free-up the memory */
    	sem_destroy(&lock);
    	sem_destroy(&lockReturn);
    	sem_destroy(&lockH);

    	printf("========================================\n");
    	usleep(1000000);
    }

    return 0;
}

void *hReady(void *arg)
{
	char* msg;
	msg = (char*)arg;

	sem_wait(&lock); 				/* lock the critical section i.e. hAtom */
	hAtom--;
	printf("Created %s.\n",msg);
	sem_post(&lock);

	if(hAtom == 0)
		sem_post(&lockH);  			/* set H-atom == 2 */

	pthread_join(o, NULL);

	sem_wait(&lockReturn);    		 /* wait for return of makeWater() */
	printf("Returning from hReady() ( %s ).\n",msg);
	sem_post(&lockReturn);

	return;
}

void *oReady(void *arg)
{
	char* msg;
	msg = (char*)arg;

	oAtom--;   						/* only one thread of oReady runs */
	printf("Created %s.\n",msg);

	sem_wait(&lockH); 				/* wait for H-atom == 2 */

	pthread_t water;
	pthread_create(&water, NULL, makeWater,(void*) "make water");
	pthread_join(water, NULL);

	sem_post(&lockReturn);  		/* set the return of makeWater() */
	printf("Returning from oReady() ( %s ).\n",msg);

	return;

}

void *makeWater()
{
	printf("Making water using 2 H atoms & 1 O atom.\n");
	return;
}
