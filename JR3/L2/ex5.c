#include<stdio.h>
#include<string.h>

#define MAXLEN 128
char buf[MAXLEN+2];

int main(){
  char *p;

  while(fgets(buf, sizeof(buf), stdin) != NULL){
    p = strchr(buf, '\n');
    if(p != NULL){
      *p = '\0';
    }
    printf("%s\n", buf);
  }
  return 0;
}
