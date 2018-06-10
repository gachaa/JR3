#include<stdio.h>

int main(void){
  int i, num[100000] = {0,1};
  int  n;

  scanf("%d", &n);

  for(i = 2; i <= n; i++){
    num[i] = (num[i-1] + num[i-2]) % 2017;
  }

  printf("%d\n", num[n]);

  return;
}

/*
int fib(int n){

  int i, num[100000] = {0,1};
  for(i = 2; i < n; i++){
    num[i] = (num[i-1] + num[i-2]) % 2017;
  }



  return num[i];

}
*/
