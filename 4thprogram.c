 #include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
int i=0,line_no;
void handler(int signo,siginfo_t *info,void * ucontext)
{
  printf("In isr...\n");
  printf("Signal recieved by the process :%d\n",signo);
  printf("Memory loaction which caused fault:%p\n",(char*)info -> si_addr);
   //void    *si_addr;   Memory location which caused fault
   sleep(1);
   exit(0);
}
int main()
{
     printf("Modifying the signal 11 behaviour\n");
     struct sigaction sa;
     sa.sa_flags = SA_SIGINFO;
     sa.sa_sigaction = handler;
     sigemptyset(&sa.sa_mask);
     if (sigaction(SIGSEGV, &sa, NULL) == -1)
     {
       perror("sigaction");
       exit(EXIT_FAILURE);
     }
    // Code that causes segmentation fault
    sleep(1);
    printf("Creating segmenatation fault to recieve signal SIGSEGV\n");
        int *p = NULL;
        sleep(1);
      *p = 42;  // This will cause a segmentation fault
   /* char *p="hello";
    p[0]='h';  */
 
    return 0;
}
