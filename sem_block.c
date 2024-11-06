#include<string.h>
#include"header.h"
#include<semaphore.h>
main(int argc, char *argv[])
{
sem_t *sem,*sem2;
 if (argc < 2 || strcmp(argv[1], "--help") == 0)
	 // usageErr("%s sem-name\n", argv[0]);
  sem = sem_open("gh",O_CREAT,0666,0);
 printf("%d\n",(sem_t*)sem);
 /*  if (sem == SEM_FAILED)
	   perror("sem_open");*/
//sem_post(sem);
//sem2=sem;
//int*p=&i
sem_post(sem);
    if (sem_trywait(sem) == -1){
	    printf("vamsi");
	     perror("sem_wait");}
     printf("%ld sem_wait() succeeded\n", (long) getpid());
      exit(EXIT_SUCCESS);
}
