#include <stdio.h>
#include <sys/wait.h>

#define	PAGER	"${PAGER:-more}" 

int
main(int argc, char *argv[])
{
	char	line[MAXLINE];
	FILE	*fpin, *fpout;

	if (argc != 2)
		err_quit("usage: a.out <pathname>");
	if ((fpin = fopen(argv[1], "r")) == NULL)
		printf("can't open %s", argv[1]);

	if ((fpout = popen(PAGER, "w")) == NULL)
		printf("popen error");

	
	while (fgets(line, MAXLINE, fpin) != NULL) {
		if (fputs(line, fpout) == EOF)
			printf("fputs error to pipe");
	}
	if (ferror(fpin))
		printf("fgets error");
	if (pclose(fpout) == -1)
		printf("pclose error");

	return 0;
}
