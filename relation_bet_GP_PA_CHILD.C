#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main()
{
  int grandpid = getpid();
  if(fork()==0)
  {
    printf("In parent process..pid = %d \n",getpid());
    sleep(2);
    if(fork()==0)
    {
      printf("In child process ..pid = %d \n\n",getpid());
      printf("Its(child) Grand_parent process ..pid =%d \n\n",grandpid);
      sleep(10);
      exit(1);
    }
    else
    {
      int status,pid;
      pid = wait(&status);
      status =status >> 8;
      printf("child exited...pid:%d status:%d \n",pid,status);
    }
    exit(0);
  }
  else
  {
    printf("In Grand_parent process..pid = %d \n",getpid());
    int status,pid;
    pid = wait(&status);
    status =status >> 8;
    printf("Parent exited...pid:%d status:%d \n\n",pid,status);
    sleep(2);
    printf("Status collected ....grandparent exited...\n");
  }
}
