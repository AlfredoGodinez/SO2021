#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv){
    int fd[2];
    int pid;
    pipe(fd);
    pid = fork();
    if(pid == 0){
        // HIJO
        close(fd[1]);
        dup2(fd[0],STDIN_FILENO);
        execl("/usr/bin/tr","tr","' '","-",NULL);
    }
    if(pid > 0) {
        // Padre
        close(fd[0]);
        dup2(fd[1],STDOUT_FILENO);
        execl("/usr/bin/cat","cat",NULL);
    }
    return 0;
}