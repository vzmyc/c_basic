#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

main(int argc, char *argv[])
{
    int fd;
    struct flock filelock;

    filelock.l_type = F_WRLCK;   /* 쓰기 잠금 */
    filelock.l_whence = SEEK_SET;   /* 파일의 시작을 기준으로 */
    filelock.l_start = 0;   /* 기준의 처음부터 */

    fd = open(argv[1], O_RDWR);   /* agrv[1] 파일 열기 */

    /* fork에 의해 자식 프로세스를 생성 */
    switch(fork()) {
       /* fork 호출에 실패하면 */
       case -1:
          perror("fork failed");
          exit(1);
       /* 자식 프로세스는 */
       case 0:
          filelock.l_len = 5;   /* 5바이트 크기에 대해 */
          /* fd 파일에 대해 레코드 잠금을 설정.
            이미 레코드 잠금이 설정되어 있으면 해제될 때까지 기다림 */
          if(fcntl(fd, F_SETLKW, &filelock) == -1) {
             perror("fcntl failed");
             exit(1);
          }
          printf("child process: locked\n");
          sleep(3);
          /* 레코드 잠금을 해제 */
          filelock.l_type = F_UNLCK;
          if(fcntl(fd, F_SETLK, &filelock) == -1) {
             perror("fcntl failed");
             exit(1);
          }
          printf("child process: unlocked\n");
          break;
       /* 부모 프로세스는 */
       default:
          filelock.l_len = 10;   /* 10바이트 크기에 대해 */
          /* fd 파일에 대해 레코드 잠금을 설정 */
          if(fcntl(fd, F_SETLKW, &filelock) == -1) {
             perror("fcntl failed");
             exit(1);
          }
          printf("parent process: locked\n");
          sleep(3);
          /* 레코드 잠금을 해제 */
          filelock.l_type = F_UNLCK;
          if(fcntl(fd, F_SETLK, &filelock) == -1) {
             perror("fcntl failed");
             exit(1);
          }
          printf("parent process: unlocked\n");
          /* 자식 프로세스가 종료될 때까지 기다림 */
          wait(NULL);
    }
    return 0;
}
