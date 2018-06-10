#include<stdio.h>

struct golden{
  long long int a;
  long long int b;
};

int multCount = 0, plusCount = 0;

struct golden mult_golden(struct golden x, struct golden y){
  multCount += 5;
  plusCount += 3;
  struct golden z;
  z.a = x.a*y.a + x.b*y.b;
  z.b = x.a*y.b + y.a*x.b + x.b*y.b;
  return z;
}

struct golden power_golden(struct golden x, int n){
  struct golden z;
  struct golden p;

  if(n == 0){
    z.a = 1; z.b = 0;
  }else if(n%2 == 0){
    z = mult_golden(p = power_golden(x, n/2), p);
  }else{
    z = mult_golden(x, power_golden(x, n-1));
  }

  return z;
}

int main() {
  struct golden x = {1, -1};
  int n;
  scanf("%d", &n);
  x = power_golden(x, n-1);
  printf("%lld\n", x.a);
  printf("%d\n%d\n", plusCount, multCount);

  return 0;


}
