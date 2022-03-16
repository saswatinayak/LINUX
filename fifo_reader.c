#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>     /*  for mkfifo */
#include<sys/fcntl.h>    /*  for open */

void main()
{
    int ret=open("fifo_1", O_RDONLY );
    if(ret<0)
        perror("Error in open..");
    char data[100];
    printf("Waiting for writer to write into fifo..");
    read(ret,data,100);
    printf("received.= %s ",data);
    close(ret);

 

//    unlink("fifo");  // deleting fifo ( Link ) from directory.
}
