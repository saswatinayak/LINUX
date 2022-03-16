#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/fcntl.h>

void main()
{
	int ret=open("fifo",0666);
	if (ret<0)
		perror("error in open");
	char data[100];
	printf("waiting for writer to write into fifo");
	read(ret,data,100);
	printf("received=%s",data);
	close(ret);
	unlink("fifo23");
}
