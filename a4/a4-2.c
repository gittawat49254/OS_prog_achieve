#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int tokenize(char *string, char *delimiters, char ***arrayOfTokens)
{
    char *token;
    int numtokens;
    int i;
    /* skip the beginning delimiters */
    string += strspn(string, delimiters);
    if ((token = malloc(strlen(string) + 1)) == NULL){ return -1;}
    /* count tokens */
    strcpy(token, string);
    numtokens = 0;
    if (strtok(token, delimiters) != NULL){
        for (numtokens = 1; strtok(NULL, delimiters) != NULL;
    numtokens++);}
    /* create array of pointers to tokens */
    if ((*arrayOfTokens = malloc((numtokens+1)*sizeof(char *))) == NULL) {
        free(token);
        return -1;
    }
    /* fill pointers to tokens into the array */
    if (numtokens == 0) {
        free(token);
    }
    else {
        strcpy(token, string);
        (*arrayOfTokens)[0] = strtok(token, delimiters);
        for (i = 1; i < numtokens; i++)
        (*arrayOfTokens)[i] = strtok(NULL, delimiters);
        (*arrayOfTokens)[numtokens] = NULL;
    }
    return numtokens;
}

int main()
{
	int run = 1;
	while(run) {
		printf("mysh > ");
		/*
		After reading user input, do these steps
		1. use tokenize() function to get command
		2. fork a child process
		3. child use execvp() to run command
		4. parent call wait() until user enter "exit"
		*/
		
		//1. use tokenize() function to get command
		char delim[] = " \t\n";
		char **tokens;
		char string[256];
		int numtokens;
		int i;
		fgets(string, 256, stdin);
		numtokens = tokenize(string, delim, &tokens);
		
		//printf("%s\n",tokens[0]);
		if (!strcmp(tokens[0],"exit")){
			return 0;
		}

		// 2. fork a child process and 3. child use execvp() to run command
		pid_t pid;
		char* av[numtokens+1];
		for (int i = 0;i < numtokens;i++){
			av[i] = tokens[i];
			}
		av[numtokens] = (char*)0;
		pid = fork() ;
		if (pid < 0) {
			printf("Error : cannot fork\n");
			exit(1);
		}
		//3. child use execvp() to run command
		else if (pid == 0) {
			execvp(av[0],av);
		}
		//4. parent call wait() until user enter "exit"
		else {
			wait(NULL);
		}
	}
}