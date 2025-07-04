#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/fcntl.h"
#include "user/user.h"
int main(int argc, char *argv[]){
  if(argc<2){
    printf("Write: touch <filename>\n");
    exit(1);
  }

  int fd=open(argv[1],O_CREATE|O_RDWR);
  if (fd<0){
    printf("touch: cannot create %s\n",argv[1]);
    exit(1);
  }
  close(fd);
  exit(0);
}

