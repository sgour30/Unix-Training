#include <stdio.h>
#include <unistd.h>
int main()
{
    int id;
    printf("Fork Example\n");
    id=fork();
    if(id>0)
    {
     printf("\nThis is parent Process id: %d",getpid());
    }
    else if(id==0)
    {
     printf("\nafter fork child process id %d",getpid());
     printf("\nparent process id: %d",getppid());
    }
    else
    {
        printf("\nchild not created\n");
    }
    return 0;
}
