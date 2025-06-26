#include "kernel/types.h"
#include "user/user.h"

int main(int argc,char *argv[]){
  if(argc!= 2){
  printf("Enter a valid syscall number.\n");
    exit(1);
  }
  int n=atoi(argv[1]);
  int count=syscall_count(n);

  if(count<0){
    printf("Invalid syscall number\n");
}
 else{
    printf("Syscall %d was called %d times\n",n,count);
}
  exit(0);
}
