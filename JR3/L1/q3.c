#include<stdio.h>

int main(void){
  char moji[128];
  scanf("%[^\n]", moji);
  printf("%s\n", moji);
  return 0;
}
