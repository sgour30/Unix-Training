#include <stdio.h>
#include <fcntl.h>

#define	FIFO	"temp.fifo"

int main(void)
{
	int		fdread, fdwrite;

	unlink(FIFO);
	if (mkfifo(FIFO, FILE_MODE) < 0)
		printf("mkfifo error");
	if ((fdread = open(FIFO, O_RDONLY | O_NONBLOCK)) < 0)
		printf("open error for reading");
	if ((fdwrite = open(FIFO, O_WRONLY)) < 0)
		printf("open error for writing");
	clr_fl(fdread, O_NONBLOCK);
	return 0;
}
