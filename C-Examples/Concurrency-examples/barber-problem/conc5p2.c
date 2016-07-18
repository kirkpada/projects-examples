#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>


/* change this to any number to customers */
#define MAX_WAIT 3

/* make semaphores */
sem_t waiting, barb_chair, barb_sleep, cut_time;

/* flag so barber knows when to quit */
int finished = 0;


/* time for customer to get hair cut */
void *get_hair_cut ()
{
	sleep(5);
}


/* time for barber to give hair cut */
void *cut_hair ()
{
	sleep(5);
}


/* do all our barber stuff here */
void *barber (void *t)
{
	while (finished != 1) {

		/* sleep until someone shows up */
		sem_wait(&barb_sleep);

		/* either cut hair or exit program */
		if (finished != 1) {
			printf("Cutting customer's hair!\n");
			cut_hair();
			printf("Finished cutting hair!\n");

			/* send customer on their way */
			sem_post(&cut_time);
		} else 
			printf("No one left for hair cut! Leaving!\n");
	}
}


/* do all our customer stuff here */
void *barbcustomer (void *t)
{
	int randentry, sd = 123;

	randentry = rand() % 20 + 1;

	/* makes customers come at random times instead of all at once */
	sleep(randentry);

	printf("Customer arrives!\n");
	sd = sem_trywait(&waiting);
	if (sd != 0) {
		printf("No empty chairs, customer leaves!\n");
		return;
	} else {
		printf("Customer grabs a seat\n");
	}

	/* Customer waits for barber chair to open up */
	sem_wait(&barb_chair);

	/* move from waiting line to barber chair */
	sem_post(&waiting);

	/* make sure barber is awake */
	sem_post(&barb_sleep);

	/* wait for hair cut to finish */
	get_hair_cut();
	sem_wait(&cut_time);

	/*finished with hair cut */
	sem_post(&barb_chair);
	printf("Hair cut done, customer leaves!\n");
}

int main (int argc, char *argv[])
{
	int i = 0, td = 123, gen = 1, seat_time, forever = 1;

	pthread_t barb, cust;

	srand(time(NULL));

	/* init semaphores */
	sem_init(&waiting, 0, MAX_WAIT);
	sem_init(&barb_chair, 0, 1);
	sem_init(&barb_sleep, 0, 0);
	sem_init(&cut_time, 0, 0);

	while (forever == 1){
		/* make barber thread */
		td = pthread_create(&barb, NULL, barber, NULL);
		if (td != 0) {
			perror("Failed to make barber thread!\n");
			exit(1);
		}

		/* reset td */
		td = 123;

		/* make lots of customers */
		for (i = 0; i < 20; i++) {
			td = pthread_create(&cust, NULL, barbcustomer, NULL);
			if (td != 0) {
				perror("Failed to make customer thread!\n");
				exit(1);
			}
		}


		/* sync for finish */
		pthread_join(cust, NULL);


		/* finish the barber stuff */
		finished = 1;
		sem_post(&barb_sleep);
		pthread_join(barb, NULL);
	}


	exit(EXIT_SUCCESS);
}