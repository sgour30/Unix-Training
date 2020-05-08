#include <stdio.h>
#include <setjmp.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

static void                     sig_usr1(int);
static void                     sig_alrm(int);
static sigjmp_buf               jmpbuf;
static volatile sig_atomic_t    canjump;
int main(void)
{
    if (signal(SIGUSR1, sig_usr1) == SIG_ERR)
        printf("signal(SIGUSR1) error");
    if (signal(SIGALRM, sig_alrm) == SIG_ERR)
        printf("signal(SIGALRM) error");

     printf("starting main: ");     

    if (sigsetjmp(jmpbuf, 1)) {

        printf("ending main: ");

        return 0;
    }
    canjump = 1;    

    for ( ; ; )
        pause();
}

static void sig_usr1(int signo)
{
    time_t  starttime;

    if (canjump == 0)
        return;     

     printf("starting sig_usr1: ");

    alarm(3);               
    starttime = time(NULL);
    for ( ; ; )             
        if (time(NULL) > starttime + 5)
            break;

    printf("finishing sig_usr1: ");

    canjump = 0;
    siglongjmp(jmpbuf, 1);  
}

static void
sig_alrm(int signo)
{
    printf("in sig_alrm: ");
}
