#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
char* strstr(const char* text, const char* word){
  if (!*word) return (char*) text;
  for (; *text; text++) {
    const char *t = text;
    const char *w = word;
    while (*t && *w && *t == *w) {
      t++;
      w++;
    }
    if (!*w) return (char*) text;
  }

  return 0;
}


int main(int argc, char *argv[]){
  if (argc!=3){
    fprintf(2, "Write: search <filename> <keyword>\n");
    exit(1);
  }
  char *filename = argv[1];
  char *keyword = argv[2];
  char buf[512];
  int n;
  int fd=open(filename, 0);
  if (fd < 0){
    fprintf(2,"search: cannot open %s\n",filename);
    exit(1);
  }
  while ((n = read(fd, buf, sizeof(buf)-1)) > 0) {
    buf[n]='\0';
    if (strstr(buf, keyword)!=0){
      printf("Found: %s\n", keyword);
      close(fd);
      exit(0);
    }
  }
  printf("Not found.\n");
  close(fd);
  exit(0);
}
