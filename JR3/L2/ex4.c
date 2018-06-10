#include<stdio.h>

int main(void){
  char str[1000] = {};
  int i, j, check = 0;

  scanf("%[^\n]", str);

  for(i = 2; i < 1000; i++){
    check = 0;
    for(j = 2; j < i; j++){
      if(i % j == 0){
	check = 1;
	break;
      }  
    }
    if(check == 0){
      printf("%c", str[i-1]);
    }
    if(str[i] == 0){
      break;
    }
  }

  printf("\n");

}
