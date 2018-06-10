#include<stdio.h>

struct golden{
  long long int a;
  long long int b;
};

struct golden add_golden(struct golden x, struct golden y){
  struct golden z;
  z.a = y.a + x.a;
  z.b = y.b + x.b;
  return z;
}

int main() {
  struct golden x, y;
  scanf("%lld %lld", &x.a, &x.b);
  scanf("%lld %lld", &y.a, &y.b);
  x = add_golden(x, y);
  printf("%lld %lld\n", x.a, x.b);

  return 0;


}
