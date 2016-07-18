#include "mt19937ar.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>




/* Thread stuff (yeeeeeee!) */
pthread_mutex_t mute;
pthread_cond_t cond;

/* Struct for our linked list */
struct link{
	int value;
	struct link *next;
	pthread_mutex_t mutex;
	pthread_t thread;
};


/* Insert values into our list */
void *insert (void *t)
{
	struct link *curr_lnk = t;
	struct link *new_lnk;
	pthread_mutex_t *lock;
	int td = 1;

	lock = &curr_lnk->mutex;

	/* Lock list so we can add to it */
	while (td != 0)
		td = pthread_mutex_trylock(lock);

	/* Iterate through our list to find the end */
	while (curr_lnk->next != NULL)
		curr_lnk = curr_lnk->next;

	/* When we hit the end, we add a new node */
	if (curr_lnk->next == NULL){
		new_lnk = malloc(sizeof(struct link));
		new_lnk->next = NULL;
		curr_lnk->next = new_lnk;
		new_lnk->value = genrand_int32() % 10 + 1;
		printf("Value added to list: %d\n", new_lnk->value);
	}

	/* Unlock before we leave */
	pthread_mutex_unlock(lock);

	return;
}


/* Search for a value in our list */
void *search (void *t)
{
	struct link *curr_lnk = t;
	int td = 1, find, count = 0;

	find = genrand_int32() % 10 + 1;

	/* Start from the head and iterate through list */
	while (curr_lnk->next != NULL){
		//printf("list contains: %d\n", curr_lnk->value);
		if (curr_lnk->value == find)
			count++;

		curr_lnk = curr_lnk->next;
	}
	//printf("list contains: %d\n", curr_lnk->value);

	printf("Searching list for %d.....\n", find);
	printf("Found %d %d times\n", find, count);

	return;
}
 

/* Delete value from our list */
void *delete (void *t)
{
	struct link *curr_lnk = t, *head = t;
	struct link *temp;
	pthread_mutex_t *lock;
	int td = 1, find, gone = 0, count = 0;

	find = genrand_int32() % 10 + 1;

	lock = &curr_lnk->mutex;

	if (curr_lnk->next == NULL){
		printf("List is empty, nothing to delete!\n");
		return;
	} else {
		/* Lock down head */
		while (td != 0)
			td = pthread_mutex_trylock(&curr_lnk->mutex);

		curr_lnk = curr_lnk->next;
		td = 123;


		/* Move our current location back to beginning of list */
		curr_lnk = head;

		/* Start from the head and iterate through list */
		while (curr_lnk->next != NULL){
			if (curr_lnk->next->value == find){
				temp = curr_lnk->next;
				if (curr_lnk->next->next == NULL){
					curr_lnk->next == NULL;
				} else
					curr_lnk->next = curr_lnk->next->next;

				free(temp);
				gone = 1;
				printf("Deleted first instance of %d from list.....\n", find);
				
				break;		/* found our value, no need to keep looking */
			}

			curr_lnk = curr_lnk->next;
		}

		/* Move our current location back to beginning of list */
		curr_lnk = head;

		while (td != 0)
			td = pthread_mutex_unlock(&curr_lnk->mutex);

		curr_lnk = curr_lnk->next;
	}
	

	if (gone == 1)
		return;
	else{
		printf("Could not find value to remove! Tried to remove: %d\n", find);
		return;
	}
}


/* Decide what each thread is going to be */
void *threadtype (void *t)
{
	struct link *link;
	link = t;

	int option;
	option = genrand_int32() % 3 + 1;

	/* Decide what the thread is */
	switch (option) {
		case 1:
				insert(link);
				break;
		case 2:
				search(link);
				break;
		case 3:
				delete(link);
				break;
	}
}


/* Driver */
int main (int argc, char *argv[])
{
	struct link *head_lnk, *temp;

	int i, count = 0, num1, num2, td;
	srand(time(NULL));
	num1 = rand()%1000;
	num2 = rand()%1000;
	unsigned long seed;
	seed = num1 * num2;
	init_genrand(seed);

	/* Create initial node */
	head_lnk = malloc(sizeof(struct link));
	head_lnk->next = NULL;
	head_lnk->value = 0;

	pthread_mutex_init(&head_lnk->mutex, NULL);

	/* Create threads */
	for (i = 0; i < 10; i++)
		td = pthread_create(&head_lnk->thread, NULL, &threadtype, head_lnk);

	td = pthread_join(head_lnk->thread, NULL);

	/* Free before we quit */
	while (head_lnk->next != NULL) {
		printf("freeing node\n");
		temp = head_lnk;
		head_lnk = head_lnk->next;
		free(temp);
	}

	free(head_lnk);
	printf("freed head node\n");

	exit(EXIT_SUCCESS);
}