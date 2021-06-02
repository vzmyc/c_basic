#include <stdio.h>
#include <pthread.h>
#include <time.h>

void *firstThreadRun()
{
    while(1)
    {
        sleep(1);
        printf("start First Thread\n");
    }
}

void *secondThreadRun()
{
    while(1)
    {
        sleep(3);
        printf("start Second Thread\n");
    }
}

int main()
{
    pthread_t firstThread, seconThread;
    int threadErr;

    if(threadErr = pthread_create(&firstThread,NULL,firstThreadRun,NULL))
    {
        printf("Thread Err = %d",threadErr);
    }

    if(threadErr = pthread_create(&seconThread,NULL,secondThreadRun,NULL))
    {
        printf("Thread Err = %d",threadErr);
    }

    while(1);
}
