#include<stdio.h>
#include<unistd.h>
#include<signal.h>
int i=1;
void isr(int sig)
{ char ch;
  printf("You want to snooze (y/n):");
  scanf(" %c",&ch);
  printf("\n");
  if(ch=='y')
  {  if(i==1)
    {
      printf("In isr..,snooze for 5 seconds\n");
      alarm(5);
      i=0;
    }
  else
   {
     signal(14,SIG_DFL);
     printf("Again 2nd snooze.. Timesup.. ,This time SIGALRM Default action will be taken\n");
     alarm(5);
   }
  }
  else
  { printf("Times up..\n");
    return;
  }
}
int main()
{
  signal(14,isr);
  printf("Alarm set for 10 seconds\n");
  alarm(10);
  while(1);
}