#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

//#include<anio.h>
static void *fact2_fun(void *ar);
static int i,l=100,num=1,k=0,h=0,g=0,s=1;
pthread_t fact[4];
int a[4];
void *fact1_fun(void *ar){
	int j=1;
	if(k==0){
		h=i/2;
	}else if(k==1){
		h=i/3;
	}
	else if(k==2)
		h=i/4;
printf("%d",k);
	//else if(k==1){
	for(;j<=h;j++){
	printf("%d * %d=%d  ",num,j,num);
		num=num*j;
		//printf("%d * %d=%d  ",num,j,num);
	}
	printf("\tfirst thread total :%d\n",num);

	s++;
		
	a[1]=pthread_create(&fact[1],0,fact2_fun,0);
	if(a[1]){
		perror("fact[1]");
		exit(0);
	}
	pthread_join(fact[1],0);
	pthread_exit(0);
}

static void *fact2_fun(void *ar){

//	pthread_join(fact[0],0);
	int j;
j=(i/2)+1;
	if(k==0)
		h=i;
	else if(k==1){
		h=(i/3)*s;
		j=(i/3)+1;
	}
	else if(k==2){
		h=(i/4)*s;
		j=(i/4)+1;
	}

	//else if(k==1){
	for(;j<=h;j++){
		num=num*j;
		//printf("%d * %d=%d  ",num,j,num);
	}
	printf("\tsecond thread :%d\n",num);
	s++;
	g++;
	pthread_exit(0);
}

/*void *fact3_fun(void *ar){
	pthread_join(fact[1],0);
	int j;
	if(k==1){
		h=i;
		j=(i/3)*(++g)+1;
	}
	else if(k==2){
		h=(i/4)*s;
		j=(i/4)*(++g)+1;
		
	}

	//else if(k==1){
	for(;j<=h;j++){
		num=num*j;
		//printf("%d * %d=%d  ",num,j,num);
	}
	printf("\tthird thread :%d\n",num);
	s++;
	pthread_exit(0);
}

void *fact4_fun(void *ar){
	int j;
	pthread_join(fact[2],0);
	j=(i/4)*(++g)+1;
	//else if(k==1){
	for(;j<=1;j++){
		num=num*j;
		//printf("%d * %d=%d  ",num,j,num);
	}
	printf("\tfourth thread :%d\n",num);
	s++;
	pthread_exit(0);
}
*/
void main(){

	int k1=0;
	scanf("%d",&i);
	if(i>10&&i<=50){
		k=1;
	}
	else if(i>50){
		k=2;
		k1=1;
	}
	else 
		k=0;

	//int a[4];
	// pthread_t fact[4];
	a[0]=pthread_create(&fact[0],0,fact1_fun,0);
	if(a[0]){
		perror("fact[0]");
		exit(0);
	}
/*	a[1]=pthread_create(&fact[1],0,fact2_fun,0);
	if(a[1]){
		perror("fact[1]");
		exit(0);
	}*//*

		switch(k){

		case 1 :   a[2]=pthread_create(&fact[2],0,fact3_fun,0);
		if(a[2]){
		perror("fact[2]");
		exit(0);
		}
		if(k1==0)
		break;

		pthread_join(fact[2],0);
		case 2:    a[3]=pthread_create(&fact[3],0,fact4_fun,0);
		if(a[3]){
		perror("fact[3]");
		exit(0);
		}
		break;
		default : printf("bye bro");
		break;



		}*/


	pthread_join(fact[0],0);
/*	if(k==0)
		pthread_join(fact[1],0);
	else if(k==1)
		pthread_join(fact[2],0);
	else if(k==2){
		pthread_join(fact[3],0);}*/

	printf("after");

}
