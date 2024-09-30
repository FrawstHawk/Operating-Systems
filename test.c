#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {

    int pid = fork();
    
    if (pid == 0) {
        int pid3 = fork();

        if (pid3 == 0) {
            printf("Child of child process (pid: %d)\n", getpid());
        } // End If //
        else {
            wait(NULL); 
            wait(NULL); 
            printf("First child process (pid: %d)\n", getpid());
        } // End Else //
    } // End If //
    else {
        int pid2 = fork();

        if (pid2 == 0) {
            printf("Second child process (pid: %d)\n", getpid());
        } // End If //
        else {
            wait(NULL); 
            wait(NULL); 
            printf("Parent process (pid: %d)\n", getpid());
        } // End Else //
    } // End Else //
    return 0;

}
