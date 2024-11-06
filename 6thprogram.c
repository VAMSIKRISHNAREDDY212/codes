#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
void handle_signal(int signal)
{
  if (signal == SIGINT || signal == SIGTERM || signal == SIGQUIT)
  {
    printf("\nSignal %d received, but ignored!\n", signal);
  }
}
int main(int c,char ** argv)
{
  if(c < 4)
  {
   printf("./a.out arg1 arg2 arg3\n");
   return 0;
  }
  signal(atoi(argv[1]),handle_signal);
  signal(atoi(argv[2]),handle_signal);
  signal(atoi(argv[3]),handle_signal);
  printf("Enter ctrl+c, kill -15 , ctrl+slash(3)\n");
  while(1);
}
