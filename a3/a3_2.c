#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int  main(){
    int i;
    int n;
    int status = 0;
    pid_t childpid, wpid;
    n = 4;
    for (i = 0; i < n; ++i) {
        childpid = fork() ;
        if (childpid > 0) break;
    }
    while ((wpid = wait(&status)) > 0);
    printf("This is process %ld with parent %ld\n",(long) getpid(), (long)getppid() );
}
