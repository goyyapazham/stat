#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main() {

  struct stat *buf;
  stat("test.txt", buf);
  
  printf("file size: %lld\n", buf->st_size);
  printf("permissions: %o\n", buf->st_mode);

  struct tm *info;
  time_t rawtime = buf->st_atime;

  info = localtime( &rawtime );

  char buffer [80];

  strftime(buffer,80,"time of last access: %c", info);
  puts(buffer);

  return 0;
}
