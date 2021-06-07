#include <stdio.h>
#include <signal.h>
#include <unistd.h>
 
int main(){
        sigset_t pendingset;
        sigset_t set;
        sigemptyset(&set);
        sigemptyset(&pendingset);
 
        sigaddset(&set,SIGQUIT);
        sigaddset(&set,SIGINT);
        sigaddset(&set,SIGTSTP);
 
        sigprocmask(SIG_BLOCK,&set,NULL);
 
        printf("SIGQUIT, SIGINT, SIGTSTP를 발생시켜보세요.\n");
 
        sleep(3);
        if(sigpending(&pendingset)==0){
                printf("\n\nBlock되어 대기중인 SIGNAL\n");
                if(sigismember(&pendingset,SIGQUIT))
                        printf("SIGQUIT\n");
                if(sigismember(&pendingset,SIGINT))
                        printf("SIGINT\n");
                if(sigismember(&pendingset,SIGTSTP))
                        printf("SIGTSTP\n");
 
        }
        sleep(3);
        sigprocmask(SIG_UNBLOCK,&set,NULL);
        printf("SIGQUIT OR SIGINT OR SIGTSTP 신호를 발생시켰으면 이 메시지가 보이지 않습니다.\n");
 
        return 0;
}
