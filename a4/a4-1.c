#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
	pid_t pid;
	if(argc < 2){
		printf("Please enter UNIX command\n");
		}
	char* av[argc];
	for (int i = 1;i < argc;i++){
		av[i-1] = argv[i];
		}
	av[argc-1] = (char*)0;
	pid = fork() ;
	if (pid < 0) {
		printf("Error : cannot fork\n");
		exit(1);
	}
	else if (pid == 0) {
		execvp(av[0],av);
	}
	else {
		wait(NULL);
		return(0);
	}
}
