#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main()
{
    int pid;
    int i;

    i = 2000;
    pid = fork();
    if (pid == -1)
    {
        perror("fork error ");
        exit(0);
    }
    // child
    else if (pid == 0)
    {
        printf("child process : PID= %d\n", getpid());
        close(0);
        close(1);
        close(2);
        setsid();
        while(1)
        {
            printf("-->%d\n", i);
            i++;
            sleep(1);
        }
    }
    // parent
    else
    {
        printf("parent process : child pid= %d\n", pid);
        sleep(1);
        printf("parent exit.\n");
        exit(0);
    }
}
