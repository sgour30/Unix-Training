#include<stdio.h>
#include<unistd.h>
int main(void)
{
printf("Before vfork\n");
vfork();
printf("after vfork\n");
return 0;
}
