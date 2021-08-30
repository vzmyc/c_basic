#include <stdio.h>
#include <pthread.h>

#define false (0!=0)
static void * TimerRoutine(void *) ;

int main( int argc, const char ** argv)
{
    pthread_t thread ;
    pthread_attr_t attr ;

    pthread_attr_init( & attr ) ;
    pthread_create( & thread, & attr, TimerRoutine, NULL ) ;

    int done = false ;
    while( !done )
    {
        char input[80] ;
        scanf("%79s", input) ;
        // handle input command (or something)

        done = ( 0 == strcmp( input, "quit" ) ) ;
    }

    // wait for timer thread to exit
    pthread_cancel( thread ) ;
    pthread_join( thread, NULL ) ;
}

static void * TimerRoutine(void * arg)
{
    pthread_detach( pthread_self() ) ;

    int done = false ;
    while( !done )
    {
        // do background task, i.e.:
        printf("tick!\n") ;
        sleep(1) ;

        pthread_testcancel( ) ;
    }   
}
