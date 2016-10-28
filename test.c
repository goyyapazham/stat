#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int main() {

  struct stat *buf;
  stat("test.txt", buf);
  printf("file size: %d\n", buf->st_size);
  printf("permissions: %o\n", buf->st_mode);

  return 0;
}
