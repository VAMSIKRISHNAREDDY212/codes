#include"header.h"
void main(int argc,char**argv)
{
int id,ret;
id=semget(4,5,IPC_CREAT|0666);
if(id==-1)
	printf("error\n");

printf("%d",id);
ret=semctl(id,atoi(argv[1]),SETVAL,atoi(argv[2]));
if(ret==-1)
	printf("semctl error\n");
printf("%d",ret);

}
