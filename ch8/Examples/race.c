#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
static void charatatime(char *);
int main(void)
{
    pid_t   pid;

    if ((pid = fork()) < 0) {
        printf("fork error");
    } else if (pid == 0) {
        charatatime("output from child\n");
    } else {
        charatatime("output from parent\n");
    }
    
}

static void charatatime(char *str)
{
    char    *ptr;
    int     c;

    setbuf(stdout, NULL);      
    for (ptr = str; (c = *ptr++) != 0; )
        putc(c, stdout);
}
