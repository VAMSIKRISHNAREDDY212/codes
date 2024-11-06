#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
 
static void * threadFunc(void *arg)
{
         pthread_t *t1= (pthread_t*)arg;
 
         char *str = (char *) arg;
         printf("ThreadFunc: pid = (%d)\n",getpid());
         (void)sleep(2);
         printf("Thread cancelled by itslef\n");
         pthread_cancel(pthread_self());
        //pthread_cancel(*t1);
        printf("\nthreadFunc: exiting now\n");
         return(0);
}
 
int main(int argc, char *argv[])
{
   pthread_t t1;
   void *res;
    int s;
 
    s = pthread_create(&t1, NULL, threadFunc, &t1);
    if (s != 0)
     perror("Thread create error");
     printf("main thread: Message from main() , pid = (%d)\n",getpid());
 
     printf("\nmain thread: exiting now\n");
     pthread_exit(0);
//   exit(0);
}
