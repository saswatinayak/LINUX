#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h> 
#include <signal.h>

int fd[2];   
void sigHandler(int signumber)
{

	if(signumber == SIGUSR1) 
	{

	printf("SIGUSR1 catched.\n");
 	int read_data = -1;
	close(fd[1]);
	read(fd[0], &read_data, sizeof(read_data));
	printf("Received data: %s", read_data);
	}
       	else 
	{
	printf("SIGQUIT catched.\n");
	exit(3);
	}
	}
	
	void sigDummy(int signumber){
    	printf("SigDummy catched\n");
	}

int main()
{    
	fflush(stdout);
	pipe(fd);
	char option=-1;
	pid_t child_a;
	pid_t child_b;
	child_a = fork();
	if (child_a == 0) 
	{
    	signal(SIGQUIT ,sigHandler); 
    	signal(SIGUSR1 ,sigHandler); 
	 while(1) 
    	{
        sleep(1);
        printf("child_a iddle work\n");
    	}
}

    else 
{
    child_b = fork();

    if (child_b == 0) 
    {
	signal(SIGQUIT ,sigHandler);
        signal(SIGUSR1 ,sigHandler);

        while(1) 
	{
            sleep(1);
            printf("child_b iddle work\n");

        }

    }
       else 
       {
	signal(SIGUSR1 ,sigDummy); 

        while(option!=0)
	{

        scanf("%d", &option);
        printf("input was: %d\n", option);
        kill(child_b,SIGUSR1); 

        close(fd[0]);
	write(fd[1], &option, sizeof(option));
        }

	}
        if(option==0)
	{

            int status_a, status_b;

            waitpid(child_b, &status_b, WNOHANG|WUNTRACED);
            waitpid(child_a, &status_a, WNOHANG|WUNTRACED);

            kill(child_b,SIGQUIT); 
            kill(child_a,SIGQUIT); 

        }
    }
    return 0;
} 
