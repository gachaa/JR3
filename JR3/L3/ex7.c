#include<stdio.h>
#include<math.h>

struct golden{
  long long int a;
  long long int b;
};

int main() {
  struct golden x, y;
  scanf("%lld %lld", &x.a, &x.b);
  scanf("%lld %lld", &y.a, &y.b);
  long double q1, q2;
  q1 = x.a + x.b*(1+sqrtl(5))/2;
  q2 = y.a + y.b*(1+sqrtl(5))/2;

  if(q1 == q2){
    printf("0\n");
  }else if(q1-q2 > 0){
    printf("1\n");
  }else{
    printf("-1\n");
  }

  return 0;


}
