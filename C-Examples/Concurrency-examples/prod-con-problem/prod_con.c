#include "mt19937ar.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUFFER 32

/*pthread info*/
pthread_mutex_t mutex;
pthread_cond_t  cond;

int place_holder = 0, open = 0, error = 0;

struct info
{
	int data;
	int sleeping;
};

/*init buffer (static allocation)*/
struct info buffer[MAX_BUFFER];

void* producer(void *ptr)
{
	int i, td;		/*thread descriptor*/
		
	if (place_holder != MAX_BUFFER) {
		td = pthread_mutex_lock(&mutex);
		if (td != 0) {
			perror("Could not lock (producer)");
			error = -1;
		}

		/*sleep 3-7 seconds*/
		sleep(genrand_int32() % 5 + 3);

		/*random generate data/sleeping values via ASM*/
		buffer[place_holder].data = genrand_int32() % 100;
		buffer[place_holder].sleeping = genrand_int32() % 8 + 2;
		place_holder++;

		/*release the buffer*/
		td = pthread_mutex_unlock(&mutex);
		if (td != 0) {
			perror("Could not unlock (producer)");
			error = -1;
		}

		/*wake consumer*/
		td = pthread_cond_signal(&cond);
		if (td != 0) {
			perror("Consumer won't wake up");
			error = -1;
		}
	}
		
	return NULL;
}

void* consumer(void *ptr)
{
	int i, td;		/*thread descriptor*/

	td = pthread_mutex_lock(&mutex);
	if (td != 0) {
		perror("Could not lock (consumer)");
		error = -1;
	}

	/*waiting to use buffer*/
	if (place_holder == 0) {
		while (place_holder == 0) {
			td = pthread_cond_wait(&cond, &mutex);
			if (td != 0) {
				perror("Wait is broken");
				error = -1;
			}
		}
	}

	/*sleep based on sleeeping value from struct*/
	sleep(buffer[place_holder].sleeping);

	/*print value stored in data from struct*/
	place_holder--;
	printf("value: %d\n", buffer[place_holder].data);

	/*Reset values*/
	buffer[place_holder].data = 0;
	buffer[place_holder].sleeping = 0;

	/*release the buffer*/
	td = pthread_mutex_unlock(&mutex);
	if (td != 0) {
		perror("Could not unlock (consumer)");
		error = -1;
	}
			
	return NULL;
}


int main(int argc, int* argv[])
{
	pthread_t conthread, prothread;
	int i, td; 	/*td = thread descriptor*/
	srand(time(NULL));


	/*create a random seed for mtwist to use*/
	int num1, num2;
	num1 = rand()%1000000000;
	num2 = rand()%1000000000;
	unsigned long seed;
	seed = num1 * num2;
	init_genrand(seed);

	/*init mutex and condition vars*/
	pthread_mutex_init(&mutex, NULL);
	pthread_cond_init(&cond, NULL);

	/*create threads*/
	for (;;) {
		td = pthread_create(&prothread, NULL, producer, NULL);
		if (td != 0) {
			perror("Could not create producer thread!");
			error = -1;
		}

		td = pthread_create(&conthread, NULL, consumer, NULL);
		if (td != 0) {
			perror("Could not create consumer thread!");
			error = -1;
		}

		/*synch threads*/
		td = pthread_join(prothread, NULL);
		if (td != 0) {
			perror("Could not join producer thread!");
			error = -1;
		}
		td = pthread_join(conthread, NULL);
		if (td != 0) {
			perror("Could not join consumer thread!");
			error = -1;
		}
		

		/*error handling exit*/
		if (error == -1)
			exit(1);
		else
			continue;

	}

	/*exit program*/
	exit(EXIT_SUCCESS);
}