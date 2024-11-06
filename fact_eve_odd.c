#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

//#include<anio.h>
static int i,l=100,num=1,k,h;
void *fact1_fun(void *ar){
int j=0;
//else if(k==1){
for(;j<i/2;j++)
	num=num*j;
printf("first thread :%d",num);
pthread_exit(0);
}

void main(){

	int i,k1=0;
	scanf("%d",&i);
	if(i>10&&i<=50){
		k=1;
	}
	else if(i>50){
                k=2;
	        k1=1;
	}
	else 
		k=3;
	
        int a[4];
		 pthread_t fact[4];
		 a[0]=pthread_create(&fact[0],0,fact1_fun,0);
		 if(a[0]){
                    perror("fact[0]");
		    exit(0);
		 }
		 a[1]=pthread_create(&fact[1],0,fact2_fun,0);
		 if(a[1]){
                    perror("fact[1]");
		    exit(0);
		 }
              
	switch(k){

		case 1 :   a[2]=pthread_create(&fact[2],0,fact3_fun,0);
			   if(a[2]){
                           perror("fact[2]");
			   exit(0);
			   }
			   pthread_join(fact[2],0);
			   if(k1==0)
				   break;

			   pthread_join(fact[2],0);
                case 2:    a[3]=pthread_create(&fact[3],0,fact4_fun,0);
			   if(a[3]){
                           perror("fact[3]");
			   exit(0);
			   }
			   pthread_join(fact[2],0);
			   break;
	        default : printf("bye bro");
			  break;



	}

	pthread_join(fact[0],0);
	pthread_join(fact[1],0);
	printf("after");

}
