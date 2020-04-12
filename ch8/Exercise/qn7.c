#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <fcntl.h>

int main() 
{
	DIR *dir;
	int dir_fd;
	
	dir = opendir("/");
	dir_fd = dirfd(dir);
	printf("close on exec flag: %d\n", fcntl(dir_fd, F_GETFD));
	closedir(dir);
	
	dir_fd = open("/",O_RDONLY);
	printf("close on exec flag: %d\n", fcntl(dir_fd, F_GETFD));
	return 0;
}
