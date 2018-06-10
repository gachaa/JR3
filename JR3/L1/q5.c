#include<stdio.h>

int main(void){
  int a[10], i, j, count[10] = {}, check;
  scanf("%d %d %d %d %d %d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5], &a[6], &a[7], &a[8], &a[9]);

  for(i = 0; i<10; i++){
    for(j = 0; j<10; j++){
      if(a[i] >= a[j]){
	count[i]++;
      }
    }
  }

  for(i = 0; i< 10; i++){
    if(count[i] == 9){
      printf("%d\n", a[i]);
      check = 1;
      break;
    }
  }

  if(check == 0){
    for(i = 0; i < 10; i++){
      if(count[i] == 10){
	printf("%d\n", a[i]);
	break;
      }
    }
  }

  return 0;
  
}
