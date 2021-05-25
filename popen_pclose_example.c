#include <stdio.h>

#define MAXLINE 256

int main()
{
    FILE *fp;
    int state;

    char buff[MAXLINE];
    /*
     * popen 은 command 를 shell(:12)을 가동시켜서 열고 pipe(2)로 연결한다.
     * pipe 는 기본적으로 단방향으로만 정의 되어 있음으로, 읽기전용 혹은 쓰기전용
     * 으로만 열수 있으며, type 로 정의된다. popen 은 command 를 실행시키고 pip 연결을
     * 위해서 내부적으로 fork() 와 pipe() 를 사용한다.
     *
     * command 는 실행쉘인 /bin/sh 에 -c 옵션을 사용하여서 전달되게 된다.
     * pclose(2) 함수는 종료되는 관련 프로세스를 기다리며 wait(2) 가 반환하는 것처럼 명령어의 종료 상태를 반환한다.
     */
    fp = popen("ls -al", "r");
    if (fp == NULL)
    {
        perror("erro : ");
        exit(0);
    }

    while(fgets(buff, MAXLINE, fp) != NULL)
    {
        printf("%s", buff);
    }

    state = pclose(fp);
    printf("state is %d\n", state);
}
