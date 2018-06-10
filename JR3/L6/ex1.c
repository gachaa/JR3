#include<stdio.h>
#define DIGITS 126
char buf1[DIGITS+2];
char buf2[DIGITS+2];

int main() {
  int i, len1, len2, maxLen;
  int arr1[DIGITS]={}, arr2[DIGITS]={}, arr3[DIGITS]={};
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

  if(len1 <= len2) maxLen = len2;
  else maxLen = len1;

  int up = 0;
  for(i=0; i<maxLen+1; i++) {
    arr3[i] = arr1[i] + arr2[i] + up;
    if(arr3[i] >= 10){ up = 1; arr3[i] %= 10;}
    else up = 0;
  }
  if(arr3[maxLen] == 1)printf("1");
  
  for(i=maxLen-1; i>=0; --i){
    printf("%d", arr3[i]);
  }
  printf("\n");
  return 0;

}
