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

int main(){
    char delim[] = " \t\n";
    char **tokens;
    char string[256];
    int numtokens;
    int i;
    fgets(string, 256, stdin);
    numtokens = tokenize(string, delim, &tokens);
    for (i = 0; i < numtokens; i++) {
    printf("%d:%s\n", i, tokens[i]);
    }
}

