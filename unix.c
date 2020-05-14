#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
main()
{
	pid_t pid;
	int status,choice;
	int f=0;
	
	while(f==0){

		printf("Select command to execute\n1. ls\n2. ps\n3. join\n4. exit\nEnter choice: ");
		scanf("%d",&choice);
		printf("\n\n");
		switch(choice){
				
			case 1: 
				pid = fork();
				if(pid<0)
				{
					printf("Error occured in fork()");
				}
				else if(pid==0)			//child process will get pid = 0 
				{
					execl("/bin/ls","ls",NULL);		//execute ls command
				}
				else				//parent process will get some non zero +ve pid
				{
					status = wait();
					printf("\nChild finished execution with status %d\n",status);
				}	
				break;
			case 2:
				pid = fork();
				if(pid<0)
				{
					printf("Error occured in fork()");
				}
				else if(pid==0)			//child process will get pid = 0 
				{
					execl("/bin/ps","ps",NULL);		//execute ps command
				}
				else				//parent process will get some non zero +ve pid
				{
					status = wait();
					printf("\nChild finished execution with status %d\n",status);
				}	
				break;
			case 3:
				pid = fork();
				if(pid<0)
				{
					printf("Error occured in fork()");
				}
				else if(pid==0)			//child process will get pid = 0 
				{
					execl("/usr/bin/join","join","a.txt","b.txt",NULL);		//execute join command
				}
				else				//parent process will get some non zero +ve pid
				{
					status = wait();
					printf("\nChild finished execution with status %d\n",status);
				}	
				
				break;
				
			case 4: 
				f=1;
				break;
			default:
				printf("Wrong choice\n");
		
		}
	}
	
	
}
