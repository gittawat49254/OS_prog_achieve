#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int my_fork(int fork_count){
    if (fork_count > 3){
        return 0;
    }
    int id = fork();
    if (id> 0) {
        printf("hi i am forked0%d\n",fork_count);
        return 0;
    }
    return my_fork(fork_count + 1);
}

int main(){
    //printf("test");
    my_fork(0);
    return 0;
}