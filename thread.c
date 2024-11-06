#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<aio.h>


                 pthread_t t,t1;
static void * threadFunc(void *arg)
{
//	pthread_detach(pthread_self());
pthread_t t=pthread_self();
//sleep(3);
			sleep(10);
		        printf("\nthreadFunc: exiting now %d\n ",t);
			//sleep(10);
			    pthread_exit(8);
}

static void * threadFunc1(void *arg)
{
//	pthread_detach(pthread_self());
//pthread_t t=pthread_self();
//sleep(3);
pthread_join(t,0);
		        printf("\nthreadFunc1: exiting now");
			    pthread_exit(8);
}
int main(int argc, char *argv[])
{
		printf("%d",getpid()); 
int k;
k=pthread_create(&t,0,threadFunc,0);
k=pthread_create(&t1,0,threadFunc1,0);
if(k){
perror("t");
exit(5);
}
if(pthread_equal(t,pthread_self()))
		printf("they both are not equal\n");
		else
		printf("they both are equal\n");
		int i;
		void *p=&i;
		printf("before\n");
//	pthread_join(t[0],&p);
	pthread_join(t1,&p);
	
	//pthread_join(t,&p);
		printf("after\n");
//pthread_exit(0);


}

