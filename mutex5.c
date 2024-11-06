#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t my_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t myConVar = PTHREAD_COND_INITIALIZER;

int flag = 0; //// counter variable


void * odd(void *p) {
while(1){
pthread_mutex_lock(&my_mutex);
if(flag==0)
	flag=1;
if(flag%2!=0)
printf("odd thread1:%d\n",flag);
pthread_mutex_unlock(&my_mutex);
if(flag==9){
flag++;
	break;}
flag++;
if(flag==2)
pthread_cond_signal(&myConVar);
sleep(2);
}
}
void * even(void *p) {
//	printf("jack");
	while(1){
	pthread_mutex_lock(&my_mutex);
	if(flag==0){
	pthread_cond_wait(&myConVar,&my_mutex);}
	if(flag%2==0)
	printf("even thread2:%d\n",flag);
	pthread_mutex_unlock(&my_mutex);
	if(flag==10){
		flag++;
		break;}
	flag++;
	sleep(2);
	}
	printf("every time the odd thread will execute first:\n");
}

int main(int argc, char** argv) {
    pthread_t pthreadA;
    pthread_create(&pthreadA, NULL, even, NULL);
    pthread_t pthreadB;
    pthread_create(&pthreadB, NULL, odd, NULL);
    pthread_join(pthreadA,NULL);
    pthread_join(pthreadB,NULL);
    printf("\n Main thread is exiting now\n");
    return (EXIT_SUCCESS);
}
