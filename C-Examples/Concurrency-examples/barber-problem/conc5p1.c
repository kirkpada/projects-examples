#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


/* Set up mutex */
pthread_mutex_t tex[3];
pthread_cond_t cond;

int counter = 0;

/* 
** Three threads will lock a process 
**
** All threads that come through here will try and lock 1 of 3 mutexes.
** If threads cannot lock any mutexes they will not wait around to lock.
** They will complete the function and return and terminate, there is no
** point in them waiting around.
**
*/
void *access (void *t)
{
	int i, j, td = 123;

	if (counter == 3) {
		for (i = 0; i < 3; i++)
			pthread_cond_broadcast(&cond);
	}
	
	/* Lock mutex */
	for (i = 0; i < 3; i++) {
		td = pthread_mutex_trylock(&tex[i]);
		if (td == 0) {
			printf("Locked mutex %d\n", i);
			printf("td: %d\n", td);
			counter++;
			continue;
		} else if (td != 0) {
			printf("nothing to lock\n");
			printf("td: %d\n", td);
			return;
		}
	}
	
	while (j < counter) {
		pthread_cond_wait(&cond, &tex[i]);
		j++;
	}

	if (counter == 3) {
		/* Unlock when whole thing is filled */
		for (i = 0; i < 3; i++) {
			td = pthread_mutex_unlock(&tex[i]);
			if (td == 0) {
				printf("Unlocked mutex %d\n", i);

			}
		}
		/* Reset counter since resource is empty */
		counter = 0;
	} 


	return;
}


/* Driver */
int main (int argc, char *argv[])
{
	int i, j, error, td, inf = 1;

	pthread_t thread;


	td = pthread_cond_init(&cond, NULL);

	/* init all mutex */
	for (j = 0; j < 3; j++) {
		td = pthread_mutex_init(&tex[j], NULL);
		if (td != 0) {
			perror("Could not init a mutex\n");
			error = -1;
		}

		/* error handler */
		if (error == -1)
			exit(1);
		else
			continue;
	}

	
	for (i = 0; i < 10; i++) {
		/* set/reset td before creating a thread */
		td = 123;

		/* create the threads */
		td = pthread_create(&thread, NULL, access, NULL);
		if (td != 0) {
			perror("Could not create thread!\n");
			error = -1;
		}


		/* error handler */
		if (error == -1)
			exit(1);
		else
			continue;
	}

	/* set/reset td before syncing the threads */
	td = 123;

	/* sync threads */
	td = pthread_join(thread, NULL);
	if (td != 0) {
		perror("Could not sync threads!\n");
		error = -1;
	}

	/* error handler */
	if (error == -1)
		exit(1);

	/* successful exit */
	exit(EXIT_SUCCESS);

}