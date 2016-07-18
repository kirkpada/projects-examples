/* Group 17 - Concurrency 4
** Brett Hayes
** Daniel Kirkpatrick
** Kris Van derZandt
*/


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* declare global varibles */
pthread_mutex_t lock;

void* helloWorld(void* a)
{
  int td = 1;
  /*insert lock here */
  while (td != 0)
    td = pthread_mutex_trylock(&lock);

  printf("hello ");
  printf("world \n");
  /*relase lock here */
  pthread_mutex_unlock(&lock);

  return;
}

int main (int argc, char** argv)
{
  pthread_t hw;
  void *res;
  int s, i;
  
  for (i = 0; i < 10; i++)
    s = pthread_create(&hw, NULL, &helloWorld, NULL);

  s = pthread_join(hw, NULL);

  exit(EXIT_SUCCESS);
}
