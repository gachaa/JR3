#include<stdio.h>

int main(void){
  int a, b, ans[100000], i;
  scanf("%d %d", &a, &b);

  ans[0] = 1; ans[1] = a % 2017;

  for(i = 2; i <= b; i++){
    if(i%2 != 0){
      ans[i] = (ans[i-1] * (a % 2017)) % 2017;
    }else{
      ans[i] = (ans[i/2] * ans[i/2]) % 2017;
    }
  }

  printf("%d\n", ans[b]);
  return;
}
