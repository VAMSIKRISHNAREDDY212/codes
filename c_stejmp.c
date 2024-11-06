#include <stdio.h>
#include <setjmp.h>
jmp_buf var;
void risky_function() 
{
 printf("Entering risky_function\n");
 
 longjmp(var, 1);
 printf("This line will not be executed\n");
}
int main()
{
 if (setjmp(var) == 0) 
 {
 
printf("In try block\n");
 
risky_function();
printf("This line will not be executed\n");
 
 }
 else
 {
 printf("In catch block\n");
 }
 printf("Program continues...\n");
 return 0;
}