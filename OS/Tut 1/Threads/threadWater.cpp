#include<iostream>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>

using namespace std;

void *hReady(void *arg);
void *oReady(void *arg);
void *makeWater(void *arg);

int hAtom;
int oAtom;
sem_t lockH;
sem_t lockO;
sem_t lockReturn;
sem_t lockAtoms;
pthread_t h[20];
pthread_t o[20];
pthread_t water[10];
//int l=0;

int main()
{

    	sem_init(&lockH, 0, 1);      	/* lock the critical section */
    	sem_init(&lockO, 0, 1);
    	sem_init(&lockReturn, 0, 0); 	/* lock for return of makeWater() */
    	sem_init(&lockAtoms, 0, 0);
    	

    	srand((unsigned) time(NULL));
    	
        printf("Enter a string of 1s and 0s");
        char inp[20];
    	scanf("%s",inp);
    	int length=strlen(inp);
   	 
   	    int j=0,k=0;
        for(int i=0;i<length;i++)
   	    {
               
           if(inp[i]=='0')
           pthread_create(&o[j++], NULL, oReady,(void*) "O atom");     
           else
           pthread_create(&h[k++], NULL, hReady,(void*) "H atom");
           //usleep(rand()%1000);
        }
        
    	for(int i=0;i<j;i++)
   	    {
           pthread_join(o[i], NULL);
        }
    	for(int i=0;i<k;i++)
   	    {
           pthread_join(h[i], NULL);
        }
    	
    	/* destroy all the semaphores to free-up the memory */
    	sem_destroy(&lockO);
    	sem_destroy(&lockH);
    	sem_destroy(&lockReturn);
    //	sem_destroy(&lockH);
    	
    return 0;
}

void *hReady(void *arg)
{
	char* msg;
	msg = (char*)arg;

	sem_wait(&lockH); 				/* lock the critical section i.e. hAtom cannot be incremented by any1 else*/
	hAtom++;
	printf("Created %s. ",msg);
         cout<<endl;
	sem_post(&lockH);

	if(hAtom >= 2 && oAtom >=1)
	{
		sem_post(&lockAtoms);  			/* set H-atom = 2 */
		sem_wait(&lockH);
    }


	sem_wait(&lockReturn);    		 /* wait for return of makeWater() */
    printf("Returning from hReady)");
    cout<<endl;    
    return 0;
}

void *oReady(void *arg)
{
	char* msg;
	msg = (char*)arg;

	sem_wait(&lockO);
        oAtom++;   						
	printf("Created %s. ",msg);
        cout<<endl;
	
    sem_wait(&lockAtoms); 				/* wait for 2 H atoms */

	pthread_t water;
	pthread_create(&water, NULL, makeWater,(void*) "Making water using 2 H atoms & 1 O atom.\n");
	
	pthread_join(water, NULL);

	sem_post(&lockReturn);  		
	printf("Returning from oReady");
        cout<<endl;	
        return 0;

}

void *makeWater(void *arg)
{
	char* msg;
	msg = (char*)arg;
	hAtom--;
	hAtom--;
	oAtom--;	
        printf("%s",msg);
	sem_post(&lockO);
	sem_post(&lockH);
        return 0;
}
