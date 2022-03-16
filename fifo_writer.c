#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>

 

#include<sys/stat.h> /* for mkfifo*/

 

#include<sys/fcntl.h>  /* for open() */

 

void main()
{
    int ret;
    int fd;
    ret=mkfifo("fifo_1",0666);
    if(ret<0)
        perror("mkfifo error");

 

    fd=open("fifo_1",0666 | O_WRONLY);
    printf("fd=%d \n",fd);
    if(errno == ENXIO )
        perror("NO reader is available ");

 

    write(fd,"hello_Friends",14);
    printf("data has been Written into fifo..\n");
    close(fd);

 


}
