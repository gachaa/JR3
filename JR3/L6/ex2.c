#include<stdio.h>
#define DIGITS 126
char buf1[DIGITS+2];
char buf2[DIGITS+2];


int main() {
  int i, j, len1, len2;
  int arr1[DIGITS+1]={}, arr2[DIGITS]={}, arr3[DIGITS*2]={};

  //-----2つの数を読み込む------
  //arr1とarr2に一の位からひとけたずつ
  i = 0;
  fgets(buf1, sizeof(buf1), stdin);
  while(buf1[i] != '\n') ++i;
  len1 = i;
  for(i=0; i<len1; i++)
    arr1[i] = (int)(buf1[len1-1-i]-'0');

  i = 0;
  fgets(buf2, sizeof(buf2), stdin);
  while(buf2[i] != '\n') ++i;
  len2 = i;
  for(i=0; i<len2; i++)
    arr2[i] = (int)(buf2[len2-1-i]-'0');
  //----------ここまで----------
  
  int up = 0, plusArr[DIGITS][DIGITS*2] = {};
  for(i=0; i<len2; i++){
    for(j=i; j<=len1+i; j++) {
      plusArr[i][j] = arr1[j-i]*arr2[i] + up;
      up = plusArr[i][j]/10;
      plusArr[i][j] %= 10;
    }
  }

  for(i=0; i<len2; i++) {
    up = 0;
    for(j=i; j<=len1+i; j++){
      arr3[j] = arr3[j] + plusArr[i][j] + up;
      up = arr3[j] / 10;
      arr3[j] %= 10;
      // printf("%d", plusArr[i][j]);
    }
    //printf("\n");
  }
  

  //[len1+len2-1]が最高位のはず
  if(arr3[len1+len2-1] == 0 && arr3[len1+len2-2] == 0){
    printf("0");
  } else {
    if(arr3[len1+len2-1] != 0) printf("%d", arr3[len1+len2-1]);
    for(i=len1+len2-2; i>=0; --i){
      printf("%d", arr3[i]);
    }
  }
  printf("\n");
  return 0;

}
