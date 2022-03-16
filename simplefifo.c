#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/stat.h>
#include<sys/fcntl.h>

void main()
{
	int ret;
	int fd;
	ret=mkfifo("fifo",0666);
	if(ret<0)
		perror("mkfifo error");
	fd=open("fifo",O_WRONLY);
	printf("fd=%d\n",fd);
	if(errno==ENXIO)
		perror("no reader is available");

	write(fd,"hello_friends",14);
	printf("data has been written into fifo..\n");
	close(fd);
}
