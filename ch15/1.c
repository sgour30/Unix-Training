#include <stdio.h>
#include <sys/wait.h>

int main(void)
{
	char	line[MAXLINE];
	FILE	*fpin;

	if ((fpin = popen("myuclc", "r")) == NULL)
		printf("popen error");
	for ( ; ; ) {
		fputs("prompt> ", stdout);
		fflush(stdout);
		if (fgets(line, MAXLINE, fpin) == NULL)	/* read from pipe */
			break;
		if (fputs(line, stdout) == EOF)
			printf("fputs error to pipe");
	}
	if (pclose(fpin) == -1)
		printf("pclose error");
	putchar('\n');
	
}
