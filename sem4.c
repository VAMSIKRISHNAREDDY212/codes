#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<semaphore.h>
#include"header.h"
#include<string.h>

void main(int argc,char **argv){
sem_t *sem;
 if (argc < 2 || strcmp(argv[1], "--help") == 0)
	//  usageErr("%s sem-name\n", argv[0]);
  sem = sem_open("gh",O_CREAT,0666, 0);
   if (sem == SEM_FAILED)
	    perror("sem_open");
   int k;
   if(sem_getvalue(sem,&k)==0){
     sem_post(sem);
   printf("vamsi");
   }


  //int k ,i;
  //i=sem_getvalue(sem,&k);
//printf("%d",k);
    //if (sem_wait(sem) == -1)
//	    perror("sem_wait");
  //   printf("%ld sem_wait() succeeded\n", (long) getpid());
    //  exit(EXIT_SUCCESS);
}
