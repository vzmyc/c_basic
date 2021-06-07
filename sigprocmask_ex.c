#include <signal.h>
#include <unistd.h>
 
int main(){
        sigset_t set, oldset;
        sigemptyset(&set);
        sigemptyset(&oldset);
        sigaddset(&set,SIGINT);
        sigaddset(&set,SIGQUIT);
 
        sigprocmask(SIG_BLOCK,&set,NULL);
        printf("SIGINT와 SIGQUIT는 블록되었습니다.\n");
        printf("Ctrl+C와 Ctrl+\\ 눌러도 반응이 없습니다.\n");
 
        sleep(5);
 
        sigdelset(&set,SIGINT);
        sigprocmask(SIG_UNBLOCK,&set,&oldset);
        printf("만약 Ctrl+\\을 눌렀다면 종료합니다.\n");
        printf("현재 남은 시그널은 SIGINT입니다.\n");
        printf("Ctrl+C를 눌러도 반응이 없습니다.\n");
 
        sleep(5);
 
        set=oldset;
 
        sigprocmask(SIG_SETMASK,&set,NULL);
        printf("다시 SIGINT와 SIGQUIT이 블록됩니다.\n");
        printf("Ctrl+C와 Ctrl+\\ 눌러도 반응이 없습니다.\n");
 
        sleep(5);
 
        sigprocmask(SIG_UNBLOCK,&set,NULL);
        printf("모든 시그널이 해제되었습니다\n");
 
}
