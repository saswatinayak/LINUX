#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<unistd.h>
 
int main()
{
	key_t keys;
	char cwd[200];
	int msg_qid;
	getcwd(cwd,sizeof(cwd));
	keys= ftok(cwd,25);
	printf("keys :%d \n",keys);

	msg_qid = msgget(keys,IPC_CREAT |0666);
	printf("msg_qid : %d\n",msg_qid);

	return 0;
}


