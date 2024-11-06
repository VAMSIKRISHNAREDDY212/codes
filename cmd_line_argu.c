#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
void main(int argc,char **argv){
	int j,k,l=0;
	j=atoi(argv[1]);
	k=atoi(argv[2]);
//rintf("%d %d\n",j,k);
	
	int s=fork();
 	 if(s==0){
		 printf("the chilld process accessing the command line arguments\n");
		 printf("%d %d",j,k);
	}
	 else{
	printf("the parent process \n");
	 }
}
