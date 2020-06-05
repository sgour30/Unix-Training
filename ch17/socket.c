#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <sys/socket.h>
int main(void)
{
  int fd, size;
  struct sockaddr_un un;

  un.sun_family = AF_UNIX;
  strcpy(un.sun_path, "foo.socket");
  if ((fd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0) {
    printf("socket failed");
  }
  size = offsetof(struct sockaddr_un, sun_path) + strlen(un.sun_path);
  if (bind(fd, (struct sockaddr *)&un, size) < 0) {
    printf("bind failed");
  }
  printf("UNIX domain socket bound\n");
  exit(0);
}
