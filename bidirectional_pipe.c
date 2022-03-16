#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

void main()
{
	int fd1[2];
	int fd2[2];

	int exit_code;

	int ret1=pipe(fd1);
	int ret2=pipe(fd2);
	int pid=fork();
	if (pid<0)
	{
		perror("fork() failed..\n");
		exit(0);
	}
	else if (pid==0)
	{
		char rd_buf[100];
		read(fd1[0],rd_buf,sizeof(rd_buf));
		printf("received data is %s",rd_buf);

		char data[100]="hello parent";
		write(fd2[1],data,sizeof(data));
		printf(".....child process end....");
	}
	else
	{
		printf("....parent process start....");
		char buf[100];
		int stat_val;
		pid_t child_pid;
		printf("enter message foe sending data in child process\n");
		fgets(buf,100,stdin);
		write(fd1[1],buf,sizeof(buf));

		child_pid=wait(&stat_val);
		char dt[100];
		read(fd2[0],dt,sizeof(dt));

		printf(" in parent,recieved data is %s\n",dt);
		printf("....parent process...\n");
	}

	close(fd1[0]);
	close(fd1[1]);
	close(fd2[0]);
	close(fd2[1]);
	
}
