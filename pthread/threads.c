/******************************************************************************
* FILE: hello.c
* DESCRIPTION:
*   A "hello world" Pthreads program.  Demonstrates thread creation and
*   termination.
* AUTHOR: Blaise Barney
* LAST REVISED: 08/09/11
******************************************************************************/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS	10
pthread_mutex_t lock;

int deposito = 0;

void *PrintHello(void *threadid)
{
   long tid;
   int localdeposito = deposito;gi
   pthread_mutex_lock(&lock);
   tid = (long)threadid;
   printf("Hello World! It's me, thread #%ld!\n", tid);
   printf("another print \n");
   deposito = localdeposito + 100;
   pthread_mutex_unlock(&lock);
   pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
   pthread_t threads[NUM_THREADS];
   int rc;
   long t;
   for(t=0;t<NUM_THREADS;t++){
     printf("In main: creating thread %ld\n", t);
     rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
     if (rc){
       printf("ERROR; return code from pthread_create() is %d\n", rc);
       exit(-1);
       }
     }
	
   for(t=0; t<NUM_THREADS; t++) {
       rc = pthread_join(threads[t], NULL);  
       if (rc) {
          printf("ERROR; return code from pthread_create() is %d\n", rc);
          exit(-1);
	   }
	}

   printf("mi dinero es %d\n", deposito);
   /* Last thing that main() should do */
   pthread_exit(NULL);
	
  return 0;
}