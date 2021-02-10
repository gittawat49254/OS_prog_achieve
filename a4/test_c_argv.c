#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
	printf("%d\n",argc);
	for (int i = 1; i < argc; i++){
		printf("%s\n",argv[i]);
		}
	return 0;
	}
