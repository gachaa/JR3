#include<stdio.h>

int main(void){
  int i, j, n, k, ans[1000][1000];
  scanf("%d %d", &n, &k);
  /*
  for(i = 0; i < n; i++){
    for(j = 0; j <= i; j++){
      if(j == 0 || j == i){
	ans[i][j] = 1;
      }else if(j == 1){
	ans[i][j] = i;
      }
    }
  }
  */
  for(i = 1; i <= n;i++){
    ans[i][0] = 1;
  }
  for(i = 0; i <= k; i++){
    ans[i][i] = 1;
  }
  //ans[0][0] = 0;

  for(i = 2; i <= n; i++){
    for(j = 1; j <= k; j++){
      ans[i][j] = (ans[i-1][j] + ans[i-1][j-1]) % 2017;
    }
  }

  printf("%d\n", ans[n][k]);
  return;

}
