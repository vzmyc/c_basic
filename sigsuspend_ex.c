#include <stdio.h>
#include <signal.h>
#include <unistd.h>
 
int main(){
        sigset_t set;
        sigemptyset(&set);
 
        sigaddset(&set,SIGQUIT);
        sigaddset(&set,SIGINT);
        sigaddset(&set,SIGTSTP);
 
        printf("SIGQUIT, SIGINT, SIGTSTP이 5초간 BLOCK됩니다.\n");
        sigprocmask(SIG_SETMASK,&set,NULL);
        sleep(5);
 
         
        printf("\n\nSIGNAL 블록이 해제되고 시그널이 발생했다면 종료됩니다.\n");
        printf("시그널을 발생시키지 않았다면 발생시켜 종료하세요.\n");
        sigemptyset(&set);
        sigsuspend(&set);
        return 0;
}
