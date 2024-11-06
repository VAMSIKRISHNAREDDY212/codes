#include <stdio.h>
#include <stdlib.h>
void execute_command(const char *command) 
{
 int status = system(command);
 if (status == -1) 
 {
perror("Error executing command");
 }
}
int main()
{
 printf("CPU Info:\n");
 execute_command("cat /proc/cpuinfo | grep \"model name\"| uniq");
 printf("\nCores : \n");
 execute_command("cat /proc/cpuinfo | grep \"cores\" | uniq");
 printf("\nMemory Info:\n");
 
 execute_command("cat /proc/meminfo | grep \"MemTotal\"");
 printf("\nSystem Uptime:\n");
 
 execute_command("cat /proc/uptime");
 return 0;
}
