#include<stdio.h>
#include<setjmp.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int i=1,pid,status;
void isr(int n)
{
  printf("Exit status collected...\n");
  i=0;
  pid= wait(&status);
  status = status >> 8;
  printf("exit status....%d pid=%d \n",status,pid);
  sleep(2);
  printf("End of isr\n");
}
int main()
{
   if(fork()==0)
  {
    printf("In child process pid:%d...\n",getpid());
    sleep(2);
    printf("going to become zombie process..\n");
    exit(1);
    }
 
   else
   {
      printf("In parent process ppid:%d..\n",getppid());
      signal(17,isr);
      while(i);
      sleep(2);
      printf("parent process got terminated..\n");
      sleep(1);
 
   }
}
