#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <math.h>
#include <string.h>

char * ret_perm(mode_t dig) {
  char *buff = (char *)malloc(3);
  if( dig == 0 )
    strcpy(buff, "---");
  if( dig == 1 )
    strcpy(buff, "--x");
  if( dig == 2 )
    strcpy(buff, "-w-");
  if( dig == 3 )
    strcpy(buff, "-wx");
  if( dig == 4 )
    strcpy(buff, "r--");
  if( dig == 5 )
    strcpy(buff, "r-x");
  if( dig == 6 )
    strcpy(buff, "rw-");
  if( dig == 7 )
    strcpy(buff, "rwx");
  //  char ret[3] = *buff;
  //free(buff);
  //return ret;
  return buff;
}

int main() {

  //create stat buffer
  struct stat *buf = (struct stat *)malloc(sizeof(struct stat));
  char file[10] = "test.txt";
  stat(file, buf);

  //FILE SIZE
  float size = (float)(buf->st_size);
  if(size > 1024000000)
    printf("file size: %.1f %s\n", size / 1000000000, "GB");
  else if(size > 1024000)
    printf("file size: %.1f %s\n", size / 1000000, "MB");
  else if(size > 1024)
    printf("file size: %.1f %s\n", size / 1000, "KB");
  else
    printf("file size: %d %s\n", (int)size, "B");

  //PERMISSIONS
  mode_t mode = (buf->st_mode) % 512;
  char first[3];
  strcpy(first, ret_perm(mode / 64));

  
  char second[3];
  strcpy(second, ret_perm((mode / 8) % 8));
  char third[3];
  strcpy(third, ret_perm(mode % 8)); 
  printf("permissions: %s%s%s\n", first, second, third);

  //TIME OF LAST ACCESS
  struct tm *info;
  time_t rawtime = buf->st_atime;

  info = localtime( &rawtime );

  char buffer [80];

  strftime(buffer,80,"time of last access: %c", info);

  //printf("$ls -l\n");
 
  //printf("$-%s%s%s %d %s %s %d ", first, second, third, buf->st_ino, buf->st_uid, buf->st_gid, buf->st_size);
  //strftime(buffer,80,"%c ", info);
  //printf("%s\n",file);
  
  puts(buffer);
  
  free(buf);
  return 0;
}
