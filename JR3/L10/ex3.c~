#include<stdio.h>
#define SIZE 101

int hash(char *s){
  int i = 0, ans;
  while(s[i] != '\0'){
    if(i==0) ans = s[0]%SIZE;
    else ans = (ans*128 + s[i]) % SIZE;
    i++;
  }
  return ans;
}

int main() {
  char s[32];
  scanf("%[^\n]", s);
  printf("%d\n", hash(s));
  return 0;
}
