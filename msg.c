#include"header.h"
void main(int argc,char**argv){
	union semun {
	int              val;    /* Value for SETVAL */
	struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
	unsigned short  *array;  /* Array for GETALL, SETALL */
	struct seminfo  *__buf;  /* Buffer for IPC_INFO
				    (Linux-specific) */
}v[2];
short int a[5]={1,2,3,4,5};
short int b[5];
v[0].array=(short int*)a;
v[1].array=(short int*)b;
	int id,ret;
	id=semget(4,5,IPC_CREAT|0666);
	printf("%d",id);
	ret=semctl(id,0,SETALL,v[0].array);
	ret=semctl(id,0,GETALL,v[1].array);
	for(int i=0;i<5;i++)
	printf("%hd ",b[i]);
}
