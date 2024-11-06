#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
pthread_t even,odd;
static int flag=1,count=0;
void *even_fun(void *arg){
	while(1){
while(flag){
if(count%2==0)
	printf("%d is a even ",count);
//flag=0;
//sleep(1);
flag=0;
count++;
}
if(count==100)
	break;
}
pthread_exit(0);
}

void *odd_fun(void *arg){
while(1){
while(flag==0){
if(count%2!=0)
	printf("\t%d is a odd\n",count);
//flag=1;
//sleep(1);
flag=1;
count++;
}
if(count==100)
	break;
	}
pthread_exit(0);
}
void main(){
	int thrd_id1,thrd_id2;
	thrd_id1=pthread_create(&even,0,even_fun,0);
	thrd_id2=pthread_create(&odd,0,odd_fun,0);
	if(pthread_equal(even,odd))
	{printf("both are equal");
	}
	else{
       printf("both are not equal");
	}
	pthread_join(even,0);
	pthread_join(odd,0);
}
