#include <stdio.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

static void sig_int(int);

int main(void)
{
    sigset_t    newmask, oldmask, waitmask;

    printf("program start: ");

    if (signal(SIGINT, sig_int) == SIG_ERR)
        printf("signal(SIGINT) error");
    sigemptyset(&waitmask);
    sigaddset(&waitmask, SIGUSR1);
    sigemptyset(&newmask);
    sigaddset(&newmask, SIGINT);

    
    if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
        printf("SIG_BLOCK error");

    
    printf("in critical region: ");

    
    if (sigsuspend(&waitmask) != -1)
        printf("sigsuspend error");

    printf("after return from sigsuspend: ");

    
    if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
        printf("SIG_SETMASK error");

    
    printf("program exit: ");

    return 0;
}

static void sig_int(int signo)
{
    printf("\nin sig_int: ");
}
