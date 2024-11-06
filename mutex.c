#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
static pthread_mutex_t my_mutex=PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t my_mute=PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond=PTHREAD_COND_INITIALIZER;
static pthread_cond_t con=PTHREAD_COND_INITIALIZER;
void *thread1(void *arg){
	
pthread_mutex_lock(&my_mutex);
printf("hi thread1:\n");
pthread_mutex_unlock(&my_mutex);
sleep(2);
pthread_cond_broadcast(&cond);
}
void *thread2(void *arg){
pthread_cond_wait(&cond,&my_mutex);
printf("hi thread2:\n");

}
void *thread3(void *arg){
pthread_cond_wait(&cond,&my_mute);
printf("hi thread3:\n");

}
void main(){
pthread_t t,t1,t2;
pthread_create(&t,0,thread1,0);

pthread_create(&t1,0,thread2,0);

pthread_create(&t2,0,thread3,0);

pthread_join(t,0);
pthread_join(t1,0);
pthread_join(t2,0);

printf("main thread was completed");

}
