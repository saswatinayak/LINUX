#include<stdio.h>
#include<unistd.h>

int main()
{
	int pipefds1[2],pipefds2[2];
	int return_status1,return_status2;
	int pid;
	char writemsgpipe1[10]="lizzy";
	char writemsgpipe2[10]="saswati";
	char readmsg[10];
	return_status1= pipe(pipefds1);


	if (return_status1 == -1)
	{
		printf("unable to create pipe 1\n");
		return 1;
	}

	return_status2= pipe(pipefds2);
	if 
		(return_status2 == -1)
	
	{
		printf("unable to create pipe 2\n");
		return 1;
	}

	pid= fork();

	if (pid !=0);
	{
	close(pipefds1[0]);
	close(pipefds2[1]);
	printf("in parent process:writing to pipe 1 message is %s\n",writemsgpipe1);
	write(pipefds1[1],writemsgpipe1,sizeof(writemsgpipe1));
	read(pipefds2[0],readmsg,sizeof(readmsg));
	printf("in parent process:reading from pipe 2 message is %s\n",readmsg);
	}
	
	else
	{
	close (pipefds1[1]);
	close (pipefds2[0]);
	read(pipefds1[0],readmsg,sizeof(readmsg));
	printf("in child process:reading from pipe 1 message is %s\n",readmsg);
        printf("in child process:writing to pipe 2 message is %s\n",writemsgpipe2);
	write(pipefds2[1],writemsgpipe2,sizeof(writemsgpipe2));
	}
	return 0;
}
