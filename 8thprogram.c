#include <pthread.h>

#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>
 
static void * threadFunc(void *arg)

{

         pthread_t *t1= (pthread_t*)arg;
 
         char *str = (char *) arg;

         printf("ThreadFunc: pid = (%d)\n",getpid());

         printf("Thread is going to execute sleep(10)\n");

         (void)sleep(10);

         printf("\nthreadFunc: exiting now\n");

         return(0);

}
 
int main(int argc, char *argv[])

{

   pthread_t t1;

   pthread_t t2=pthread_self();

   void *res;

    int s;
 
    s = pthread_create(&t1, NULL, threadFunc, &t2);

    if (s != 0)

     perror("Thread create error");

    int ret= pthread_detach(t1);

     if(ret < 0)

     {

       perror("pthread_detach");

       return 0;

     }

     printf("Thread detached..\n");

     printf("main thread: Message from main() , pid = (%d)\n",getpid());

     sleep(2);

     pthread_cancel(t1);

     printf("Detached Thread is cancelled from main thread\n");

     sleep(2);

     printf("\nmain thread: exiting now\n");
 
     pthread_exit(0);
 
}
 
