#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXLEN 128
char buf[MAXLEN+2];

int main(void){
  char *p;
  char s[] = "//";
  int n;

  //fgetsでbufに一行文の文字列を保存。
  fgets(buf, sizeof(buf), stdin);
  
  if((p = strstr(buf, s)) != NULL){
    printf("%d\n", p - buf);
  }else{
    printf("%d\n",length(buf)-1);
  }
      

  /*
    if(p != NULL){
      //bufに//がなかった
      printf("%d\n", p-buf);
    }else{
      n = length(buf)
    }
  */
    
}

int length(char *s){
  int count = 0;
  while(*s++)count++;

  return count;
}
