#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
int main(int argc ,char**argv){
	if(argc !=2)
	{
		printf("USAGE:./a.out file_name\n");
		return 0;
	}
	int fd=open(argv[1],O_WRONLY|O_APPEND|O_CREAT,0666);
	if(fd==-1)
	{
		perror("file open");
		return 0;
	}
	struct flock lock;
	lock.l_whence=SEEK_END;
	lock.l_start=0;
	lock.l_len=0;
	char ch='a';
	while(ch<='z'){
		lock.l_type=F_WRLCK;
		fcntl(fd,F_SETLKW,&lock);
		write(fd,&ch,1);
		ch++;
		fflush(stdout);
		usleep(1000);
		lock.l_type=F_UNLCK;
		fcntl(fd,F_SETLK,&lock);
		sleep(5);
	}
	close(fd);
}

